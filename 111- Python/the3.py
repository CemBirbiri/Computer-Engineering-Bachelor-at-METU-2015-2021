from random import choice
from collections import *

def hyphenate(kelime):
		unluler=["A","E","a","e","I","i","o","O","u","U"]
		ind=0
		heceler=[]
		while True:
			
			#print kelime+"eeeeeeeeee"
			#print ind	#continue
			if kelime[ind] not in unluler:
				if kelime[ind] != (len(kelime)-1): #kirpik,traktor,yay
					#print kelime[ind]
					#print ind
					ind=ind+1
					#print ind
					#print "girdi0"
					#print kelime
					continue
					
				else:
					heceler.append(kelime[:ind])
					kelime=kelime[ind+1:]
					ind =0
					#print kelime[ind]
					#print "girdi1"
					break
			else:
				#if len(kelime)>ind:
					#heceler.append(kelime[ind])
					#kelime=kelime[ind+1:]
					#ind=0
				if len(kelime)==1:
					heceler.append(kelime)
					break
				if len(kelime)==3 and kelime[0] in unluler:

					#print kelime+"  w"
					heceler.append(kelime[0])
					kelime=kelime[1:]
					#print ind
					#print kelime
					#print "girdi1.5"
					
					continue
				else:
					if len(kelime)==2:
						#print kelime + "asdasd"
						heceler.append(kelime)
						#print kelime
						#print "girdi1.75"
						break		
					else:

						ind=ind+1 
						if kelime[ind] in unluler and kelime[ind-1] in unluler:
							heceler.append(kelime[:ind])
							kelime=kelime[ind:]
							ind=0
							#print "girdi1.80"
							continue
						 #ba.
							#print "girdi2"

				
						while True:
							if len(kelime)==2:
								heceler.append(kelime)
								#print kelime+" 2.5"
								#print "girdi2.5"
								break
							else:

								if kelime[ind] in unluler:

									heceler.append(kelime[:ind-1])
									kelime=kelime[ind-1:]

									#print "girdi4"

									ind=0
									break
								else:
									if kelime[ind]==kelime[-1]:

										heceler.append(kelime[:ind+1])
										#print kelime
										#print ind
								
										#print "girdi5"
									
										return heceler
									else:
										ind=ind+1
										if kelime[0] not in unluler and kelime[1] in unluler and kelime[2] not in unluler and kelime[3] in unluler:
											heceler.append(kelime[:ind-1])
											kelime=kelime[ind-1:]
											ind=0
											#print "son ekleme"
											#print kelime + " sonekleme"
											break

										else:


										#if kelime[ind] in unluler:
											#heceler.append(kelime[:ind-1])
											#kelime=kelime[ind-1:]
											#ind=0
										

											if kelime[ind]==kelime[-1] and len(kelime)==4:
												heceler.append(kelime)
												#print "girdi5.5"
												return heceler
											else:


												if kelime[ind] not in unluler:#a
													ind=ind+1
													#print "girdi6"

												else:
													heceler.append(kelime[:ind-1])
													kelime=kelime[ind-1:]
													ind=0
													#print "girdi7"
													#print kelime
										
													break
							
		return heceler
def execute():
	ufuk=[]
	#cumle="ufuk geldi.yemek yedi."
	#ufuk2=[]
	def gef(cumle):
		X=0
		ufuk2=[]
		#umle="gitti geldi."
		while X!=len(cumle):
			#ben.
			ufuk=[]
			if cumle[X]==" ":
				#print X
				#print "girdi1"
				
				if cumle[X]==cumle[-1]:
					#print X
					#print "girdi2"
					ufuk.append(hyphenate(cumle[:X]))
					ufuk.append(" ")
					#print ufuk
					ufuk2=ufuk2+ufuk

					break
				else:
					#print X
					#print "girdi3"
					ufuk.append(hyphenate(cumle[:X]))
					ufuk.append(" ")
					#print ufuk

					cumle=cumle[X+1:]
					#print cumle
					X=0
					ufuk2=ufuk2+ufuk
					continue
			#cumle="ufuk geldi.yemek yedi."
			#geldi.gitti
			elif cumle[X]==".":
				#print X
				#print "girdi4"
				
				
				
					#print X
				#print "girdi6"
				ufuk.append(hyphenate(cumle[:X]))
				ufuk.append(".")
				cumle=cumle[X+1:]
				ufuk2=ufuk2+ufuk
				
				if len(cumle)==1:
					break
				X=0
				#print cumle

				#print ufuk
				
				ufuk2=ufuk2+ufuk
				continue
			elif cumle.find(" ")==-1: #geldi.  #geldi.gitti
				#print X
				#print "girdi7"

				if cumle.find(".")==-1:
						#print "girdi7.5"
						if cumle=="=":
							break
						else:

							ufuk.append(hyphenate(cumle))
							#print ufuk
							ufuk2=ufuk2+ufuk
							break
				if cumle.find(".")!=cumle[-1]: #geldi.gitti
					#print "girdi8"



					index=cumle.find(".")
					#print index
					ufuk.append(hyphenate(cumle[:index]))
					#print ufuk
					ufuk.append(".")
					cumle=cumle[index+1:]
					#print "............"
					#print cumle
					#print ".........."
					X=0
				
					ufuk2=ufuk2+ufuk
					#print cumle
					continue
				else:  #geldi.
					

					
					
					#print "girdi9"
					ufuk.append(hyphenate(cumle[:cumle.find(".")]))
					ufuk.append(".")
					ufuk2=ufuk2+ufuk
					break

			
			X=X+1 
		#print "...."
		#print ufuk2
		#print "........"
		return ufuk2




	n,m=map(str,raw_input().split())
	n=int(n)
	m=int(m)

	L11=[]

	cumle=raw_input()
	while True:
		temmp=cumle
		if cumle=="=":
			break
		else:
			#temmp=cumle
			if temmp[-1]!=".":
				#print "girdi22"
				L11+=gef(temmp)+[" "]
				
				#print "//////////////"
				#print L11
				#print "///////////////"
				
				cumle=""
			
				cumle=raw_input()
				

			else:
				#print "girdi33"
				L11+=gef(temmp)
				#print "..........."
				#print gef(temmp)
				#print "%%%%%%%%%"
				#print L11
				#print "%%%%%%%%%%%%%%%55"
				cumle=""
				cumle=raw_input()
				#print L













	gef(cumle)


	#print gef(cumle)
	bos=[]
	#L=[['gel', 'di'], '.', ['git', 'ti'], '.']
	U=0
	while U!=len(L11):
		if type(L11[U])==list:
			#K=len(L[U])
			M=0
			while M!=len(L11[U]):
				bos.append(L11[U][M])
				M=M+1
		else:
			bos.append(L11[U])
		U=U+1
	#print "bosbosbosbosbosbosbsossobs"
	#print bos
	#print "bosbosbosbosbosbosbsossobs"

	if bos[(len(bos)-1)]==" ":
		del bos[(len(bos)-1)]
	#print "bosbosbosbosbosbosbsossobs"
	#print bos
	#print "bosbosbosbosbosbosbsossobs"
	d={}
	i=0#cumle="ali geldi.ali ders geldi ali."
	def dictionary(liste):
	#bos=['u', 'fuk', ' ', 'ye', 'mek', ' ', 'ye', 'di', '.', 'u', 'yu', 'du', '.', 'gu', 'zel', ' ', 'a', 'li', ' ', 'a', 'li', ' ', 'ye', 'mek', ' ', 'ye', 'di', '.', 'a', 'li', ' ']

		#d={}
		i=0
		#print len(liste) #17
		while i!=(len(liste)):
			if i==(len(liste)-1):
				if liste[i] not in d:
					d[liste[i]]="% "
					#print i
					#print d
					#print "girdi1"
					i=i+1
				else:
					d[liste[i]]+="%"+" "
					i=i+1
				
	#'.': ['cok', 'ag', 'o', 'se', 'oz', 'kalp', 'ben', '', ' ']				
	#d={'a': 'li%li%li', ' ': 'gel%ders%gel%a', 'di': '.% ', 'ders': ' ', '.': 'a% ', 'li': ' % %.', 'gel': 'di%di'}


			#if d.keys()==[]:
				#print i
				#print "girdi2"
				#[a[i]]={}
				#d[liste[i]]=liste[i+1]
					#print "girdi0"
				#print d
					#print i
				#i=i+1
			else:
				if liste[i] not in d:
					#print i
					#print "girdi3"
					d[liste[i]]=liste[i+1]
						#print "girdi1"	
					#print d
						#print i
					i=i+1
				else: 
					#liste[i] in d
						
					d[liste[i]]+="%"+liste[i+1]
					#print i
					#print "girdi4"
						
						#print "girdi2"
					#print d
						#print i
					i=i+1
		return d

		#return d
	dictionary(bos)	
	#print d



	#d={' ': 'git%ye%ye', 'git': 'ti', 'di': ' %.', 'ye': 'mek%di', 'mek': ' ', '.': 'u% ', 'u': 'fuk', 'ti': '.', 'fuk': ' ', 'gel': 'di'}








	#d={'.': 'git% ', 'git': 'ti', 'di': '.', 'ti': '.', 'gel': 'di'}
	MyDictionary={}
	noktabosluklistesi=[]
	Gfinal2=[]
	Gfinal3=[]
	noktabosluklistesi2=[]
	bosluklistesi=[]
	bosluklistesi2=[]
	def data_bulma(d):
		#d={'X': 'd k m m m m', 'Y': 'l l l k k m', 'Z': 'c d c d e'}
		#print "girdi1"
		keys=d.keys()	
		values=[]
	#keys=['1', '3', '5']
	#values=['2', '4', '6 7']
		i=0
		for i in d:
			#print "girdi2"
			values.append(d.get(i))	
		#print values
		
		#print keys
		
		#print "girdi2.5"
		j=0
		L=[]
		for j in range(len(values)):
			#print "girdi3"
			L.append(keys[j])	
			#L.append("=")	
			L.append(values[j])	
			#L.append("+")	

	#	print L
		
		#L={'a': 'li%li%li', ' ': 'gel%ders%gel%a', 'di': '.% ', 'ders': ' ', '.': 'a% ', 'li': ' % %.', 'gel': 'di%di'}

		Gfinal=[]
		G2=[]
		G1=[]
		#L=['a', 'li%li%li', ' ', 'gel%ders%gel%a', 'di', '.% ', 'ders', ' ', 'li', ' % %.', '.', 'a% ', 'gel', 'di%di']
		#print len(L)	
		F=1
		while F!=(len(L)+1):
			G1.append(L[F].split("%"))	
			F=F+2

		
		#print G1
		r=0
		R=0
		while r !=len(L):
			G2.append(L[r])	
			r=r+2
		#print G2
	#G2=['a', ' ', 'di', 'ders', 'li', '.', 'gel']
	#G1=[['li', 'li', 'li'], ['gel', 'ders', 'gel', 'a'], ['.', ' '], [' '], [' ', ' ', '.'], ['a', ' '], ['di', 'di']]

		while R!=len(G1):
			Gfinal.append(G2[R])	
			Gfinal.append(G1[R])	
			R=R+1
		#print "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"
		#print Gfinal
		#print "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"
		#return gef(dictionary(data_bulma(cumle)))	
		#return gef(dictionary(liste))	
		#print Gfinal
	#Gfinal=['a', ['li', 'li', 'li'], ' ', ['gel', 'ders', 'gel', 'a'], 'di', ['.', ' '], 'ders', [' '], 'li', [' ', ' ', '.'], '.', ['a', ' '], 'gel', ['di', 'di']]

	#Gfinal=[' ', ['git', 'ye', 'ye'], 'git', ['ti'], 'di', [' ', '.'], 'ye', ['mek', 'di'], 'mek', [' '], '.', ['u', ' '], 'u', ['fuk'], 'ti', ['.'], 'fuk', [' '], 'gel', ['di']]
		
		#print "METUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU"
		#print Gfinal
		#print "Metuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"




	#'.': ['cok', 'ag', 'o', 'se', 'oz', 'kalp', 'ben', '', ' ']
		


		p=0
		uzzunluk=len(Gfinal)	
		while p!=uzzunluk:
			if Gfinal[p]==" ":
				bosluklistesi.append(Gfinal[p+1])	
			
			if Gfinal[p]==" " or Gfinal[p]==".":
				noktabosluklistesi.append(Gfinal[p+1])	
				
			else:
				Gfinal2.append(Gfinal[p])	
				Gfinal2.append(Gfinal[p+1])	

			p=p+2

		#print "uuuuuuuuuuuuuuuuuuu"

		#print bosluklistesi

		#print "1111111111111111111111111"
		#print Gfinal2
		  #Gfinal2=['a', ['li', 'li'], 'e', ['li'], 'di', ['.'], 'fak', [' '], 'u', ['fuk', 'fuk', 'fak'], 'li', [' ', ' ', '.'], 'fuk', [' ', ' '], 'gel', ['di']]
		#print "111111111111111111111111111"
		#print noktabosluklistesi
		#noktabosluklistesi=[['u', 'u', 'gel', 'e', 'a'], ['a', ' ']]

		#print "333333333333333333333333"
	#from collections import *
	#Gfinal2=['a', ['le',"le","la", 'li', 'li'], ' ', ['gel', 'ders', 'gel', 'a'], 'di', ['.', ' '," ","a"], 'ders', [' '], 'li', [' ', ' ', '.',".","l"], '.', ['a', ' '], 'gel', ['di', 'di']]
	#Gfinali degistirdim
		D=1
		c=[]
		while D!=(len(Gfinal2)+1):
			a=Counter(Gfinal2[D]).most_common(2)	
			b=[i[0] for i in a]
			c.append(b)	
			D=D+2
		#print c
		#c=[['li'], ['li'], ['.'], [' '], ['fuk', 'fak'], [' ', '.'], [' '], ['di']]
	#data_bulma(d)	
		q=0
		#Gfinal2=['a', ['li', 'li'], 'e', ['li'], 'di', ['.'], 'fak', [' '], 'u', ['fuk', 'fuk', 'fak'], 'li', [' ', ' ', '.'], 'fuk', [' ', ' '], 'gel', ['di']]

		while q!=len(Gfinal2):
			Gfinal3.append(Gfinal2[q])	
			q=q+2

		#noktabosluklistesi=[['u', 'gel', 'al', 'a'], ['a', ' ']]

		t=0
		
		while t!=len(noktabosluklistesi):
			tmp=len(noktabosluklistesi[t])	
			T=0
			while T!=tmp:
				noktabosluklistesi2.append(noktabosluklistesi[t][T])	
				T=T+1
			t=t+1
		#print "ooooooooooooooooooooooooooo"
		#print noktabosluklistesi2
		E=0
		while E!=len(bosluklistesi):
			tttmp=len(bosluklistesi[E])	
			Y=0
			while Y!=tttmp:
				bosluklistesi2.append(bosluklistesi[E][Y])	
				Y=Y+1
			E=E+1




		#noktabosluklistesi=['u', 'a', 'al', 'al', ' ']
		#print "oooooooooooooooooooooooo"
		#print bosluklistesi2
	#	print "ooooooo=0000000000000000OOOO"



		
	#c=[['li', 'le'], ['gel', 'a'], [' ', 'a'], [' '], [' ', '.'], ['a', ' '], ['di']]
	#G2=['a', ' ', 'di', 'ders', 'li', '.', 'gel']
		
		S=0
		while S!=len(Gfinal3):
			MyDictionary[Gfinal3[S]]=c[S]
			S=S+1
		
		MyDictionary["."]=noktabosluklistesi2
		MyDictionary[" "]=bosluklistesi2
		#print "qqqqqqqqqqqqqqqqqq"
		#print MyDictionary[" "]

		#print "qqqqqqqqqqqqqqqqq"

		#print MyDictionary
		
	data_bulma(d)	


	#print data_bulma(d)	
	#MyDictionary={'a': ['li', 'le'], ' ': ['gel', 'a'], 'di': [' ', 'a'], 'ders': [' '], '.': ['a', ' '], 'li': [' ', '.'], 'gel': ['di']}



	import random


	#!!!!!!!!!!!!!  Mydictionary de "le" diye heceyi sonradan ekledim. Le den sonra gelen hece yok o yuzden KeyError "le" veryor. COK NORMAL!!!!!!!!!!!!
	#MyDictionary={'a': ['li', 'le'], ' ': ['gel', 'a'], 'di': [' ', 'a'], 'ders': [' '], '.': ['a', ' '], 'li': [' ', '.'], 'gel': ['di']}
	#n,m=map(str,raw_input().split())	
	#noktabosluk=MyDictionary[" "]+MyDictionary["."]


	the3output=""
	ilkhece=random.choice(noktabosluklistesi2)	
	#print "......"+ilkhece+"........."
	#print "aa"
	temp=ilkhece
	the3output=the3output+ilkhece
	#print the3output
	#print "bb"
	#print m
	while True:
		if len(the3output)>m:
			break
		else:


		#	print "........."
		#	print temp
		#	print "......."
			hece=random.choice(MyDictionary[temp])	
		#	print hece
		#	print "cc"
			

			if hece==".":
				temp=random.choice(noktabosluklistesi2)	
		#		print temp
				the3output=the3output+"."+temp
				if len(the3output)>m:
					break
		#			print the3output
				
				
				
				#continue
			else:
				temp=random.choice(MyDictionary[hece])	
				#print "dd"
				#print temp
				#print "ee"
				the3output=the3output+hece+ temp
				if len(the3output)>m:
					break
				#print the3output
				#print len(the3output)	
				#print "ff"
				#print m
				#temp=random.choice(MyDictionary[temp])
			
				#continue




	print the3output




