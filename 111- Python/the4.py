

def query(tree,variable_value):
	def left(tree):
  		return tree[1]

	def right(tree):
  		return tree[2]
	BKE=["<",">","==","!=","in"]
	temperature=["very low","low","normal","high","very high"]
	def ufuk(tree,variable_value): #tree[0] a bakar
		if tree[0]=="not":
			
			return NOT(tree,variable_value)
		if tree[0] in BKE:
			
			return uclu(tree,variable_value)
		if tree[0]=="and":
			
			return AND(tree,variable_value)
		if tree[0]=="or":
			
			return OR(tree,variable_value)
	def NOT(tree,variable_value):
		if tree[1][0]=="<":
			
			
			if type(tree[1][1])!=str and type(tree[1][2])!=str:
				
				if tree[1][1]>=tree[1][2]:
					return True
				else:
					return False
			else:
				if type(tree[1][1])==str and type(tree[1][2])==str:
					
					k=0
					while k!=len(variable_value):
				
						h=0
						while h!=len(variable_value):				

							
							
							if tree[1][2]==variable_value[h][0] and tree[1][1]==variable_value[k][0]:
								if variable_value[k][1]>=variable_value[h][1]:
									
									return True
								else:
									
									return False
							

							else: h=h+1
						k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1][1] :
							if variable_value[k][1]>=tree[1][2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[1][2]:
							if variable_value[k][1]>=tree[1][1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
				
					
					
		if tree[1][0]==">":
			if type(tree[1][1])!=str and type(tree[1][2])!=str:
				
				if tree[1][1]<=tree[1][2]:
					return True
				else:
					return False
			else:
				if type(tree[1][1])==str and type(tree[1][2])==str:
					
					k=0
					while k!=len(variable_value):
				
						h=0
						while h!=len(variable_value):				

							
							
							if tree[1][2]==variable_value[h][0] and tree[1][1]==variable_value[k][0]:
								if variable_value[k][1]<=variable_value[h][1]:
									
									return True
								else:
									
									return False
							

							else: h=h+1
						k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1][1] :
							if variable_value[k][1]<=tree[1][2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[1][2]:
							if variable_value[k][1]<=tree[1][1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[1][0]=="==":
			if type(tree[1][1])!=str and type(tree[1][2])!=str:
				
				if tree[1][1]==tree[1][2]:
					return True
				else:
					return False
			else:
				if type(tree[1][1])==str and type(tree[1][2])==str:
					if tree[1][1] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:
								if temperature.index(tree[1][1])==temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1
								
					if tree[1][2] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:

								if temperature.index(tree[1][2])==temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1			

					else:
						k=0
						while k!=len(variable_value):
					
							h=0
							while h!=len(variable_value):				

								
								if tree[1][2]==variable_value[h][0] and tree[1][1]==variable_value[k][0]:
									if variable_value[k][1]==variable_value[h][1]:
										
										return True
									else:
										
										return False
								

								else: h=h+1
							k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1][1] :
							if variable_value[k][1]==tree[1][2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[1][2]:
							if variable_value[k][1]==tree[1][1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[1][0]=="!=":
			if type(tree[1][1])!=str and type(tree[1][2])!=str:
				
				if tree[1][1]!=tree[1][2]:
					return True
				else:
					return False
			else:
				if type(tree[1][1])==str and type(tree[1][2])==str:
					if tree[1][1] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:
								if temperature.index(tree[1][1])!=temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1
					if tree[1][2] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:

								if temperature.index(tree[1][2])!=temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1			

								

					else:
						k=0
						while k!=len(variable_value):
					
							h=0
							while h!=len(variable_value):				

								
								if tree[1][2]==variable_value[h][0] and tree[1][1]==variable_value[k][0]:
									if variable_value[k][1]!=variable_value[h][1]:
										
										return True
									else:
										
										return False
								

								else: h=h+1
							k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1][1] :
							if variable_value[k][1]!=tree[1][2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[1][2]:
							if variable_value[k][1]!=tree[1][1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[1][0]=="in":
			k=0
			while k!=len(variable_value):
				if variable_value[k][0]==tree[1][1]:
					if variable_value[k][1] not in tree[1][2]:
						return True
					else:
						return False
				if variable_value[k][0]==tree[1][2]:
					if variable_value[k][1] not in tree[1][1]:
						return True
					else:
						return False
				else:
					k=k+1
		if tree[1][0]=="not":
			return not ufuk(tree[1],variable_value)
		if tree[1][0]=="and":
			
			return not ufuk(tree[1],variable_value)
		if tree[1][0]=="or":
			return not ufuk(tree[1],variable_value)

	def uclu(tree,variable_value):
	
		if tree[0]=="<":
			if type(tree[1])!=str and type(tree[2])!=str:
				
				if tree[1]<tree[2]:
					return True
				else:
					return False
			else:
				if type(tree[1])==str and type(tree[2])==str:
					
					k=0
					while k!=len(variable_value):
				
						h=0
						while h!=len(variable_value):				

							
							
							if tree[2]==variable_value[h][0] and tree[1]==variable_value[k][0]:
								if variable_value[k][1]<variable_value[h][1] :
									
									return True
								else:
									
									return False
							

							else: h=h+1
						k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1] :
							if variable_value[k][1]<tree[2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[2]:
							if variable_value[k][1]<tree[1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
					
		if tree[0]==">":
			if type(tree[1])!=str and type(tree[2])!=str:
				
				if tree[1]>tree[2]:
					return True
				else:
					return False
			else:
				if type(tree[1])==str and type(tree[2])==str:
					
					k=0
					while k!=len(variable_value):
				
						h=0
						while h!=len(variable_value):				

							
							
							if tree[2]==variable_value[h][0] and tree[1]==variable_value[k][0]:
								if variable_value[k][1]>variable_value[h][1]:
									
									return True
								else:
									
									return False
							

							else: h=h+1
						k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1] :
							if variable_value[k][1]>tree[2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[2]:
							if variable_value[k][1]>tree[1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[0]=="==":
			
			
			
			if type(tree[1])!=str and type(tree[2])!=str:
				
				if tree[1]==tree[2]:
					return True
				else:
					return False
			else:
				if type(tree[1])==str and type(tree[2])==str:
					if tree[1] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:

								if temperature.index(tree[1])==temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1
					if tree[2] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:

								if temperature.index(tree[2])==temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1			

					else:
						k=0
						while k!=len(variable_value):
					
							h=0
							while h!=len(variable_value):				

								
								if tree[2]==variable_value[h][0] and tree[1]==variable_value[k][0]:
									if variable_value[k][1]==variable_value[h][1]:
										
										return True
									else:
										
										return False
								

								else: h=h+1
							k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1] :
							if variable_value[k][1]==tree[2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[2]:
							if variable_value[k][1]==tree[1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[0]=="!=":
			if type(tree[1])!=str and type(tree[2])!=str:
				
				if tree[1]!=tree[2]:
					return True
				else:
					return False
			else:
				if type(tree[1])==str and type(tree[2])==str:
					if tree[1] in temperature :
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:
								if temperature.index(tree[1])!=temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1
								
					if tree[2] in temperature:
						k=0
						while k!=len(variable_value):
							if variable_value[k][1] in temperature:

								if temperature.index(tree[2])!=temperature.index(variable_value[k][1]):
									return True
								else:
									return False
							else:
								k=k+1			

					else:
						k=0
						while k!=len(variable_value):
					
							h=0
							while h!=len(variable_value):				

								
								if tree[2]==variable_value[h][0] and tree[1]==variable_value[k][0]:
									if variable_value[k][1]!=variable_value[h][1]:
										
										return True
									else:
										
										return False
								

								else: h=h+1
							k=k+1
				
				else: 
					
					k=0
					while k!=len(variable_value):
						
						if variable_value[k][0]==tree[1] :
							if variable_value[k][1]!=tree[2]:
								
								return True
							else:
								
								return False
						
						if variable_value[k][0]==tree[2]:
							if variable_value[k][1]!=tree[1]:
								
								return True
							else:
								
								return False
						else:
							k=k+1
		if tree[0]=="in":
			k=0
			while k!=len(variable_value):

				if variable_value[k][0]==tree[1] :
					if variable_value[k][1] in tree[2]:
						return True
					else:
						return False
				
				if variable_value[k][0]==tree[2]:
					if variable_value[k][1] in tree[1]:
						return True
					else:
						return False
				else:
					k=k+1

	

	def OR(tree,variable_value):
		a=False
		k=1
		while k!= len(tree):
			
			a = a or ufuk(tree[k],variable_value)
			k=k+1
		return a
	def AND(tree,variable_value):
		a=True
		k=1
		while k!= len(tree):
			
			a = a and ufuk(tree[k],variable_value)
			k=k+1
		
		return a
	
	if type(tree)==str:
		return tree
	
	if ufuk(tree[0],variable_value):
		
		return query(left(tree),variable_value)
	else:
		
		return query(right(tree),variable_value)



print query(['!=', 'Pi1', 'Pi2'], 'test10_wrongoutc1', [['!=', '3.14', 'Pi1'], 'test10_outc', 'test10_wrongoutc2']]
,[('Pi1', 3.14), ('Pi2', 3.14)])