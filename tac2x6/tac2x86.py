###############################################################################
# TAC TO x86 TRANSLATOR (tac2x86)
#
# This script is intended to translate Nicolas Maillard's TAC as seen on 
# Compilers course (II/UFRGS) to an Intel's x86 assembly compatible "as" (GNU 
# Assembler) code.
#
# It actually generates code compatible with Intel's 386 processor and above;
# it will not work with Intel's 286 processor. Since it is deprecated, one must
# not worry about it.
#
# @author Stefano Mor
# @author Nicolas Maillard
# @author Claudio Schepke
# 
# Run it as
#     ===============================
#     = python tac2x86.py <foo.tac> =
#     ===============================
# for any foo.tac file containing TAC code.
#


#==============================================================================
#= MODULES SECTION                                                            =
#==============================================================================

import sys
import os
import string
import re


#==============================================================================
#= REGULAR EXPRESSION DEFINITIONS                                             =
#==============================================================================

# Defines an integer arithmetic expression.

expriRE = re.compile('(?P<ln>\d\d\d): +(?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\))) := (?P<op1>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*)) (?P<M>(ADD)|(SUB)|(MUL)|(DIV)) (?P<op2>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*))')

#------------------------------------------------------------------------------

# Defines a floating point arithmetic expression.

exprvRE = re.compile('(?P<ln>\d\d\d): +(?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\))) := (?P<op1>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?)) (?P<M>(FADD)|(FSUB)|(FMUL)|(FDIV)) (?P<op2>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))')

#------------------------------------------------------------------------------

# Defines an integer attribution expression. Indirect addressing is also 
# treated here, since its always integer attribution.

attriRE = re.compile('(?P<ln>\d\d\d): +(?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\)))( ?(?P<op1> ?\(((\d\d\d\(Rx\))|(Rx)|(\d\d\d\(SP\))|(SP))\)))? := (?P<op2>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*))( ?(?P<op3> ?\(((\d\d\d\(Rx\))|(Rx)|(\d\d\d\(SP\))|(SP))\)))?')

#------------------------------------------------------------------------------

# Defines an floating point attribution expression.

attrvRE = re.compile('(?P<ln>\d\d\d): +(?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\))) := (?P<op1>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))')

#------------------------------------------------------------------------------

# Defines PRINT expression (printing an integer on screen).

printiRE = re.compile('(?P<ln>\d\d\d): +(PRINT) (?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*))( ?(?P<op1> ?\(((\d\d\d\(Rx\))|(Rx)|(\d\d\d\(SP\))|(SP))\)))?')

#------------------------------------------------------------------------------

# Defines FPRINT expression (printing an floating-point number on screen).

printvRE = re.compile('(?P<ln>\d\d\d): +(FPRINT) (?P<op>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|([-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?))')

#------------------------------------------------------------------------------

# Defines a label.

labelRE = re.compile('[A-Za-z][A-Za-z0-9_]*:')

#------------------------------------------------------------------------------

# Defines a goto.

gotoRE = re.compile('(?P<ln>\d\d\d): +GOTO (?P<label>(([A-Za-z][A-Za-z0-9_]*)|(_\d\d\d)))')

#------------------------------------------------------------------------------

# Defines an integer IF comparsion.

ifiRE = re.compile('(?P<ln>\d\d\d): +IF (?P<op0>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*)) (?P<cmpr>(<|<=|==|!=|>=|>)) (?P<op1>(\d\d\d\(Rx\))|(\d\d\d\(SP\))|((-?\d)(\d)*)) GOTO (?P<label>(([A-Z][A-Za-z0-9_]*)|(_\d\d\d)))')

#------------------------------------------------------------------------------

# Defines a TAG for marking template's given space for stack's size.

stackSizeRE = re.compile('<stack_size>')

#------------------------------------------------------------------------------

# Defines a TAG for marking template's given space for heap's size.

tempSizeRE = re.compile('<temp_size>')

#------------------------------------------------------------------------------

# Defines a TAG for marking template's given space for user's code.
codeRE = re.compile('<code>')


#==============================================================================
#= FILE HANDLING SECTION                                                      =
#==============================================================================

# Reads input file's name.
filename = sys.argv[1]

# Opens user's TAC (file named as, v.g., foo.tac)
userFile = open(filename, 'r')

# Opens tac2x86 template-formatting file.
templateFile = open('model.template', 'r')

# Opens the deafult output file that must be assembled after.
outFile = open('output.s', 'w')


#==============================================================================
#= ACTUAL TRANSLATING SECTION                                                 =
#==============================================================================

# Gets stack & temporary variable space alocation from TAC's first two lines.
stackSize = int( userFile.readline() )
tempSize = int( userFile.readline() )

# All generated code will be put in here. Initializes empty.
code = []

# Gets next file line and begins iterating over all lines. For each remaining
# line on user's file, does translation.
userLine = userFile.readline()
while userLine != '' :
	print userLine  # Outputs line read from user's file.
	
	# Each expression below tries to match each read line with one type of 
	# instruction. Only one following IF should hold, because one line can 
	# not be two or more instruction types togheter. However, code doesn't 
	# prevent it from happening. 
	expri = expriRE.match(userLine)
	#exprv = exprvRE.match(userLine)
	attri = attriRE.match(userLine)
	#attrv = attrvRE.match(userLine)
	printi = printiRE.match(userLine)
	#printv = printvRE.match(userLine)
	label = labelRE.match(userLine)
	goto = gotoRE.match(userLine)
	ifi = ifiRE.match(userLine)
	
	# Matching integer arithmetic expressions.
	if expri != None :
		# If it is an expression, operands must be converted to propper
		# format.
		
		ln = '_' + expri.group('ln')  # Assembles line number. 
	
		# op0 can never be an immediate number, so it must refer a 
		# register. The instruction below does:
		#   (1)  Removes all leading zeros.
		#   (2)  Replaces all occurrences of SP by its real register.
		#   (3)  Replaces all occurrences of Rx by its real register.
		# Although (2) and (3) are dicotomic, analysing wich one is
		# going to be applied is far more slower that simply doing
		# both.
		op0 = expri.group('op0')
		op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		
		# op1 can be an immediate number or a reference.First should 
		# determine which type it is. find() method will retunr -1 
		# anytime it finds nothing corresponding. So, one have a sum of
		# both equal to -2 only if it dosen't refer both Rx an SP, thus
		# being an immediate number.
		op1 = expri.group('op1')
		if op1.find('Rx') + op1.find('SP') == -2 :
			# Number: should prefix it with '$' in gAS' syntax.
			op1 = '$'+op1
		else :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			op1 = op1.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		# op2 can be an immediate number or a reference.First should 
		# determine which type it is. "find()" method will retunr -1 
		# anytime it finds nothing corresponding. So, one have a sum of
		# both equal to -2 only if it dosen't refer both Rx an SP, thus
		# being an immediate number.
		op2 = expri.group('op2')
		if op2.find('Rx') + op2.find('SP') == -2 :
			# Number: should prefix it with '$' in gAS' syntax.
			op2 = '$'+op2
		else :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			op2 = op2.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
			
		# Code below matches the desired operation with the necessary 
		# instructions. op_ is already mapped to assembly structure,
		# thus letting all the work with operation converting.
		
		if expri.group('M') == 'ADD' :
			command = '\n\t'+ln+':\tMOVL  '+op1+' , %EAX\n\t\tADDL  '+op2+' , %EAX\n\t\tMOVL  %EAX ,'+op0+'\n'
		
		elif expri.group('M') == 'SUB' :
			command = '\n\t'+ln+':\tMOVL  '+op1+' , %EAX\n\t\tSUBL  '+op2+' , %EAX\n\t\tMOVL  %EAX ,'+op0+'\n'
			
		elif expri.group('M') == 'MUL' :
			command = '\n\t'+ln+':\tMOVL  '+op1+' , %EAX\n\t\tIMULL '+op2+' , %EAX\n\t\tMOVL  %EAX ,'+op0+'\n'
		elif expri.group('M') == 'DIV' :
			command = '\n\t'+ln+':\tMOVL   '+op1+' , %EAX\n\t\tMOVL   '+op2+' , %EBX\n\t\tPUSHL %EDX\n\t\tXORL   %EDX , %EDX\n\t\tIDIVL  %EBX\n\t\tMOVL   %EDX, %EBX\n\t\tPOPL   %EDX\n\t\tMOVL   %EAX , '+op0+'\n'
	#TODO
	# Matching floating point arithmetic expression.
	#elif exprv != None :
		## If it is an exrpession, operands must be converted to propper
		## format.
		
		#ln = '_' + exprv.group('ln')  # Assembles line number. 
	
		## op0 can never be an immediate number, so it must refer a 
		## register. The instruction below does:
		##   (1)  Removes all leading zeros.
		##   (2)  Replaces all occurrences of SP by its real register.
		##   (3)  Replaces all occurrences of Rx by its real register.
		## Although (2) and (3) are dicotomic, analysing wich one is
		## going to be applied is far more slower that simply doing
		## both.
		#op0 = exprv.group('op0')
		#op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		
		## op1 can be an immediate number or a reference.First should 
		## determine which type it is. find method will retunr -1 
		## anytime it finds nothing corresponding. So, one have a sum of
		## both equal to -2 only if it dosen't refer both Rx an SP, thus
		## being an immediate number.
		#op1 = exprv.group('op1')
		#if op1.find('Rx') + op1.find('SP') == -2 :
			## Number: should prefix it with '$' in gAS' syntax.
			#op1 = '$0e'+op1
		#else :
			## The instruction below does:
			##   (1)  Removes all leading zeros.
			##   (2)  Replaces all occurrences of SP by its real register.
			##   (3)  Replaces all occurrences of Rx by its real register.
			## Although (2) and (3) are dicotomic, analysing wich one is
			## going to be applied is far more slower that simply doing
			## both.
			#op1 = op1.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		## op2 can be an immediate number or a reference.First should 
		## determine which type it is. "find()" method will retunr -1 
		## anytime it finds nothing corresponding. So, one have a sum of
		## both equal to -2 only if it dosen't refer both Rx an SP, thus
		## being an immediate number.
		#op2 = exprv.group('op2')
		#if op2.find('Rx') + op2.find('SP') == -2 :
			## Number: should prefix it with '$' in gAS' syntax.
			#op2 = '$0e'+op2
		#else :
			## The instruction below does:
			##   (1)  Removes all leading zeros.
			##   (2)  Replaces all occurrences of SP by its real register.
			##   (3)  Replaces all occurrences of Rx by its real register.
			## Although (2) and (3) are dicotomic, analysing wich one is
			## going to be applied is far more slower that simply doing
			## both.
			#op2 = op2.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
			
		#if exprv.group('M') == 'FADD' :
			#command = '\n\t'+ln+':\tFLDS  '+op1+'\n\t\tFADDS  '+op2+'\n\t\tFSTPS  '+op0+'\n'
		
		#elif exprv.group('M') == 'FSUB' :
			#command = '\n\t'+ln+':\tMOVL  '+op1+' , %EAX\n\t\tSUBL  '+op2+' , %EAX\n\t\tMOVL  %EAX ,'+op0+'\n'
			
		#elif exprv.group('M') == 'FMUL' :
			#command = '\n\t'+ln+':\tMOVL  '+op1+' , %EAX\n\t\tIMULL '+op2+' , %EAX\n\t\tMOVL  %EAX ,'+op0+'\n'
		#elif exprv.group('M') == 'FDIV' :
			#command = '\n\t'+ln+':\tMOVL   '+op1+' , %EAX\n\t\tMOVL   '+op2+' , %EBX\n\t\tPUSHL %EDX\n\t\tXORL   %EDX , %EDX\n\t\tIDIVL  %EBX\n\t\tMOVL   %EDX, %EBX\n\t\tPOPL   %EDX\n\t\tMOVL   %EAX , '+op0+'\n'

	# Matching attribution of an integer (indexed or not).
	elif attri != None :
		# If it is an attribution, operands must be converted to propper
		# format.
		
		# Assembles line number. # Already concat. at final line (sure 
		# it will be there) 
		ln = '_' + attri.group('ln')
		command='\n\t'+ln+':\t'
		
		# op0 can never be an immediate number, so it must refer a 
		# register. The instruction below does:
		#   (1)  Removes all leading zeros.
		#   (2)  Replaces all occurrences of SP by its real register.
		#   (3)  Replaces all occurrences of Rx by its real register.
		# Although (2) and (3) are dicotomic, analysing wich one is
		# going to be applied is far more slower that simply doing
		# both.
		op0 = attri.group('op0')
		op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		
		op1 = attri.group('op1')
		if op1 != None :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			
			# If it is simple indirect fills left with zeros to 
			# unify next normalization.
			if (op1 == '(Rx)') or (op1 == '(SP)') :
				op1 = '000' + op1 
			
			# Since the first strip eliminates one more parentesis 
			# than desired at the end, one should replace it.
			op1 = op1.strip('()').lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX') + ')'
			
			# Formatted command with pre-loaded ops.
			command+='MOVL '+op0+' , %EAX\n\t\tLEAL '+op1+' , %EBX\n\t\tADDL %EBX , %EAX\n\t\tPUSHL  %EAX\n'
		else :
			command+='LEAL '+op0+' , %EAX\n\t\tPUSHL  %EAX\n'
		
		# op1 can be an immediate number or a reference.First should 
		# determine which type it is. find method will retunr -1 
		# anytime it finds nothing corresponding. So, one have a sum of
		# both equal to -2 only if it dosen't refer both Rx an SP, thus
		# being an immediate number.
		op2 = attri.group('op2')
		if op2.find('Rx') + op2.find('SP') == -2 :
			# Number: should prefix it with '$' in gAS' syntax.
			op2 = '$'+op2
		else :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			op2 = op2.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		op3 = attri.group('op3')
		if op3 != None :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			
			# If it is simple indirect fills left with zeros to 
			# unify next normalization.
			if (op3 == '(Rx)') or (op3 == '(SP)') :
				op3 = '000' + op3 
			
			# Since the first strip eliminates one more parentesis 
			# than desired at the end, one should replace it.
			op3 = op3.strip('()').lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX') + ')'
			
			command+='\t\tMOVL '+op2+' , %EAX\n\t\tLEAL '+op3+' , %EBX\n\t\tADDL %EBX , %EAX\n\t\tPOPL  %EBX\n\t\tMOVL (%EAX) , %EAX\n\t\tMOVL %EAX , (%EBX)\n'
		else :
			command+='\t\tMOVL '+op2+' , %EBX\n\t\tPOPL %EAX\n\t\tMOVL %EBX , (%EAX)\n'

	# TODO
	#elif attrv != None :
		## If it is an attribution, operands must be converted to propper
		## format.
		
		#ln = '_' + attrv.group('ln')  # Assembles line number. 
	
		## op0 can never be an immediate number, so it must refer a 
		## register. The instruction below does:
		##   (1)  Removes all leading zeros.
		##   (2)  Replaces all occurrences of SP by its real register.
		##   (3)  Replaces all occurrences of Rx by its real register.
		## Although (2) and (3) are dicotomic, analysing wich one is
		## going to be applied is far more slower that simply doing
		## both.
		#op0 = attrv.group('op0')
		#op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		
		## op1 can be an immediate number or a reference.First should 
		## determine which type it is. find method will retunr -1 
		## anytime it finds nothing corresponding. So, one have a sum of
		## both equal to -2 only if it dosen't refer both Rx an SP, thus
		## being an immediate number.
		#op1 = attrv.group('op1')
		#if op1.find('Rx') + op1.find('SP') == -2 :
			## Number: should prefix it with '$' in gAS' syntax.
			#op1 = '$0e'+op1
		#else :
			## The instruction below does:
			##   (1)  Removes all leading zeros.
			##   (2)  Replaces all occurrences of SP by its real register.
			##   (3)  Replaces all occurrences of Rx by its real register.
			## Although (2) and (3) are dicotomic, analysing wich one is
			## going to be applied is far more slower that simply doing
			## both.
			#op1 = op1.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		#command='\n\t'+ln+':\tMOVL '+op1+' , %EAX\n\t\tMOVL %EAX , '+op0+'\n'
	
	# Prints integer.
	elif printi != None :
		ln = '_' + printi.group('ln')
		op0 = printi.group('op0')
		if op0.find('Rx') + op0.find('SP') == -2 :
			op0 = '$'+op0
		else :
			op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		command = '\n\t'+ln+':\tPUSHL  %ECX\n\t\tPUSHL  %EDX\n\t\tPUSHL  '+op0+'\n\t\tPUSHL  $intf\n\t\tCALL printf\n\t\tPOPL  %EAX\n\t\tPOPL  %EAX\n\t\tPOPL  %EDX\n\t\tPOPL  %ECX\n'
		
		op1 = printi.group('op1')
		if op1 != None :
			# The instruction below does:
			#   (1)  Removes all leading zeros.
			#   (2)  Replaces all occurrences of SP by its real register.
			#   (3)  Replaces all occurrences of Rx by its real register.
			# Although (2) and (3) are dicotomic, analysing wich one is
			# going to be applied is far more slower that simply doing
			# both.
			
			# If it is simple indirect fills left with zeros to 
			# unify next normalization.
			if (op1 == '(Rx)') or (op1 == '(SP)') :
				op1 = '000' + op1 
			
			# Since the first strip eliminates one more parentesis 
			# than desired at the end, one should replace it.
			
			print op1
			op1 = op1.strip('()').lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX') + ')'
			
			command='\n\t'+ln+':\tMOVL '+op0+' , %EAX\n\t\tLEAL '+op1+' , %EBX\n\t\tADDL %EBX , %EAX\n\t\tMOVL  (%EAX) , %EAX\n\t\tPUSHL  %EAX\n\t\tPUSHL  $intf\n\t\tCALL printf\n'
		
	# TODO
	# Prints floating point.
	#elif printv != None :
		#ln = '_' + printv.group('ln')
		#op = printv.group('op')
		#if op.find('Rx') + op.find('SP') == -2 :
			#op = '$0e'+op
		#else :
			#op = op.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		#command = '\n\t'+ln+':\tPUSHL  '+op+'\n\t\tPUSHL  $floatf\n\t\tCALL printf\n'
	elif label != None :
		command='\n\t'+label.group()+'\n'
	
	elif goto != None :
		ln = '_' + goto.group('ln')
		label = goto.group('label')
		command = '\n\t'+ln+':\tJMP  '+label+'\n'
		
	elif ifi != None :
		ln = '_' + ifi.group('ln')
		label = ifi.group('label')
		op0 = ifi.group('op0')
		op1 = ifi.group('op1')
		
		if op0.find('Rx') + op0.find('SP') == -2 :
			op0 = '$'+op0
		else :
			op0 = op0.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		if op1.find('Rx') + op1.find('SP') == -2 :
			op1 = '$'+op1
		else :
			op1 = op1.lstrip('0').replace('SP', '%ECX').replace('Rx', '%EDX')
		
		cmpr = ifi.group('cmpr')
		if cmpr == '<' :
			cmpr = 'JG'
		elif cmpr == '<=' :
			cmpr = 'JGE'
		elif cmpr == '==' :
			cmpr = 'JE'
		elif cmpr == '!=' :
			cmpr = 'JNE'
		elif cmpr == '>=' :
			cmpr = 'JLE'
		elif cmpr == '>' :
			cmpr = 'JL'
		
		command='\n\t'+ln+':\tMOVL '+op0+' , %EAX\n\t\tMOVL '+op1+' , %EBX\n\t\tCMPL %EAX , %EBX\n\t\t'+cmpr+' '+label+'\n'
		
	# If TAC line doesn't matches any of the above.
	else :
		print 'TAC FORMAT ERROR'
		command = 'TAC FORMAT ERROR'
	
	# Prints correspondent TAC line command. Put it into code after.
	print command
	code.append(command)
	
	# Analyzes next line.
	userLine = userFile.readline()


# Reads template file and fills TAGs with information supplied by the user. 
# Code is alredy traslated at this point.
templateLines = templateFile.readlines()
for templateLine in templateLines :
	templateLine = re.sub(stackSizeRE, str(stackSize)+'\t', templateLine)
	templateLine = re.sub(tempSizeRE, str(tempSize)+'\t', templateLine)
	templateLine = re.sub(codeRE, ''.join(code), templateLine)
	outFile.write(templateLine)	
	templateLine = templateFile.readline()

# Close all open files.
userFile.close()
templateFile.close()
outFile.close()

