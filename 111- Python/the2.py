id = raw_input()
if id[0] == '?':
	cifttoplam= int(id[2])+int(id[4])
	toplam1=0
	toplam2=0
	toplam3=0
	if (int(id[3])*2) > 9 :
		toplam1 = toplam1 + (int(id[3])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam2= toplam2 + ((int(id[5])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[5])*2)
	if (int(id[1])*2) > 9 :
		toplam3 = toplam3 + (int(id[1])*2) - 9
	else:
		toplam3 = toplam3 + (int(id[1])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+toplam3+int(id[7])
	a=(10-(bigtoplam%10))%10
	fd=list(id)
	del fd[0]
	fd.insert(0,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e		
if id[1]=='?':
	cifttoplam= int(id[0])+int(id[2])+int(id[4])
	toplam1=0
	toplam2=0
	if (int(id[3])*2) > 9 :
		toplam1 = toplam1 + (int(id[3])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam2= toplam2 + ((int(id[5])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[5])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+int(id[7])
	k=(10-(bigtoplam%10))%10
	if k % 2 ==0:
		a=k/2
	elif k % 2 !=0 :
		if k==1:
			a=5
		elif k==3 :
			a=6
		elif k==5:
			a=7
		elif k==7:
			a=8
		elif k==9:
			a=9
	fd=list(id)
	del fd[1]
	fd.insert(1,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e		
if id[2]=='?':
	cifttoplam= int(id[0])+int(id[4])
	toplam1=0
	toplam2=0
	toplam3=0
	if (int(id[3])*2) > 9 :
		toplam1 = toplam1 + (int(id[3])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam2= toplam2 + ((int(id[5])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[5])*2)
	if (int(id[1])*2) > 9 :
		toplam3 = toplam3 + (int(id[1])*2) - 9
	else:
		toplam3 = toplam3 + (int(id[1])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+toplam3+int(id[7])
	a=(10-(bigtoplam%10))%10
	fd=list(id)
	del fd[2]
	fd.insert(2,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e		
if id[3]=='?':
	cifttoplam= int(id[0])+int(id[2])+int(id[4])
	toplam1=0
	toplam2=0
	if (int(id[1])*2) > 9 :
		toplam1 = toplam1 + (int(id[1])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[1])*2)
	if (int(id[5])*2) > 9 :
		toplam2= toplam2 + ((int(id[5])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[5])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+int(id[7])
	k=(10-(bigtoplam%10))%10
	if k % 2 ==0:
		a=k/2
	elif k % 2 !=0 :
		if k==1:
			a=5
		elif k==3 :
			a=6
		elif k==5:
			a=7
		elif k==7:
			a=8
		elif k==9:
			a=9
	fd=list(id)
	del fd[3]
	fd.insert(3,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e	
if id[4]=='?':
	cifttoplam= int(id[0])+int(id[2])
	toplam1=0
	toplam2=0
	toplam3=0
	if (int(id[3])*2) > 9 :
		toplam1 = toplam1 + (int(id[3])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam2= toplam2 + ((int(id[5])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[5])*2)
	if (int(id[1])*2) > 9 :
		toplam3 = toplam3 + (int(id[1])*2) - 9
	else:
		toplam3 = toplam3 + (int(id[1])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+toplam3+int(id[7])
	a=(10-(bigtoplam%10))%10
	fd=list(id)
	del fd[4]
	fd.insert(4,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e	
if id[5]=='?':
	cifttoplam= int(id[0])+int(id[2])+int(id[4])
	toplam1=0
	toplam2=0
	if (int(id[3])*2) > 9 :
		toplam1 = toplam1 + (int(id[3])*2) - 9
	else:
		toplam1 = toplam1 + (int(id[3])*2)
	if (int(id[1])*2) > 9 :
		toplam2= toplam2 + ((int(id[1])*2) - 9)
	else:
		toplam2 = toplam2 + (int(id[1])*2)
	bigtoplam= cifttoplam+toplam1+toplam2+int(id[7])
	k=(10-(bigtoplam%10))%10
	if k % 2 ==0:
		a=k/2
	elif k % 2 !=0 :
		if k==1:
			a=5
		elif k==3 :
			a=6
		elif k==5:
			a=7
		elif k==7:
			a=8
		elif k==9:
			a=9
	fd=list(id)
	del fd[5]
	fd.insert(5,a)
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e	
if id[6]=='?':
	fd=list(id)
	del fd[6]
	fd.insert(6,'-')
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e
if id[7]=='?':
	a= int(id[0])+int(id[2])+int(id[4])
	toplam=0
	if (int(id[1])*2) > 9 :
		toplam = toplam + (int(id[1])*2) - 9
	else:
		toplam = toplam + (int(id[1])*2)
	if (int(id[3])*2) > 9 :
		toplam = toplam + (int(id[3])*2) - 9
	else:
		toplam = toplam + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam = toplam + (int(id[5])*2) - 9
	else:
		toplam = toplam + (int(id[5])*2)
	sum = toplam + a 
	checkdigit = (10-(sum%10))%10
	fd=list(id)
	del fd[7]
	fd.append(str(checkdigit))
	e= str(fd[0]) + str(fd[1])+str(fd[2])+str(fd[3])+str(fd[4])+str(fd[5])+str(fd[6])+str(fd[7])
	print e	
if id[0]!='?' and id[1]!='?' and id[2]!='?' and id[3]!='?' and id[4]!='?' and id[5]!='?' and id[6]!='?' and id[7]!='?' :
	a= int(id[0])+int(id[2])+int(id[4])
	toplam=0
	if (int(id[1])*2) > 9 :
		toplam = toplam + (int(id[1])*2) - 9
	else:
		toplam = toplam + (int(id[1])*2)
	if (int(id[3])*2) > 9 :
		toplam = toplam + (int(id[3])*2) - 9
	else:
		toplam = toplam + (int(id[3])*2)
	if (int(id[5])*2) > 9 :
		toplam = toplam + (int(id[5])*2) - 9
	else:
		toplam = toplam + (int(id[5])*2)

	sum = toplam + a 
	checkdigit = (10-(sum%10))%10
	if checkdigit == int(id[7]):
		print "VALID"
	else:
		print "INVALID"