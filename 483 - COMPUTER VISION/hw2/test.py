import numpy as np
import cv2 
import scipy.signal
from scipy.signal import convolve2d
import math
import os
from glob import glob
from scipy import ndimage
import ast

from os import listdir
from os.path import isfile, join

import matplotlib.pyplot as plt
#import skimage.data as skid

import pylab as plt
from sklearn.cluster import KMeans
from sklearn.cluster import MiniBatchKMeans
from sklearn.metrics import confusion_matrix



def read_from_cluster_centers(cluster_centers):
	filepath2 = '/home/bs05/e2171379/Desktop/cv_hw2/train_img_hists/clus_centers_k256_ss3.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		while line:

			des=ast.literal_eval(line)
			cluster_centers.append(des)
			line = fp.readline()



def read_from_train_img_hist(train_img_hists):
	filepath2 = '/home/bs05/e2171379/Desktop/cv_hw2/train_img_hists/train_img_his_k256_ss3.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		while line:

			des=ast.literal_eval(line)
			train_img_hists.append(des)
			line = fp.readline()

def read_from_labels(labels):
	filepath2 = '/home/bs05/e2171379/Desktop/cv_hw2/train_img_hists/labels_k16_ss5.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		while line:
			
			line=line[:-2]
			
			labels.append(line)
			line = fp.readline()


def read_from_BOF(BOF):
	filepath2 = '/home/bs05/e2171379/Desktop/cv_hw2/BOF/BOF_ss5.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		while line:
	       
	       
	       	
			des=ast.literal_eval(line)
			BOF.append(des)
			line = fp.readline()

#******************************************************************************************************************************************************




def test_img_features(kmeans,train_img_hists,labels,test):
	
	test_images=glob('/home/bs05/e2171379/Desktop/test/*.png')

	for i in range(0,1500): #1500
		descr=[]  #her test imagein feature vektorleri ayri ayri bu arrayde tutulup histogram 
		#fonksiyonuna gidiyor
		name=test_images[i][33:]
		
		
		print test_images[i][33:]
		

		img=cv2.imread(test_images[i])

		gray= cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		sift = cv2.xfeatures2d.SIFT_create()
		
		kp = sift.detect(gray,None)
		
		kp,des = sift.compute(gray,kp)

		
		
		
		if( type(des)!=np.ndarray): #DSIFT kullaniyoruz burda cunku SIFT ile descriptor bulamiyoruz

			step_size = 5
			kp = [cv2.KeyPoint(x, y, step_size) for y in range(0, gray.shape[0], step_size) 
			                                    for x in range(0, gray.shape[1], step_size)]

			dense_feat,des = sift.compute(gray, kp)
			j=0
			while(j!=len(des)):
				descr.append(des[j])
				j=j+1	
		
		else:     #SIFT kullanarak descriptor buluyoruz
			j=0
			while(j!=len(des)):
				descr.append(des[j])
				j=j+1
		

		descriptors=np.array(descr)


		

	
		make_hist_for_test_imgs(descriptors,kmeans,train_img_hists,labels,test,name)

def make_hist_for_test_imgs(descriptors,kmeans,train_img_hists,labels,test,name):

	print("make_hist_for_test_imgs")
	
	
	
	predict=kmeans.predict(descriptors)
	
	cluster_centers=[]
	
	for i in range(1,257):
		cluster_centers.append(i)
	
	#cluster_centers=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
	#cluster_centers=[1,2,3,4]
	one_test_img_hist,bin_edges=np.histogram(predict,cluster_centers)
	'''en son burdayiz, histogram cikarttik, bu histogrami normalize edip bir file a kaydetmek gerekiyor
	'''
	
	
	

	one_test_img_hist=np.array(one_test_img_hist)
	if(one_test_img_hist.sum()!=0):
		one_test_img_hist = one_test_img_hist/(sum(one_test_img_hist)*1.0)

	

	classification(one_test_img_hist,train_img_hists,labels,test,name)

def classification(one_test_img_hist,train_img_hists,labels,test,name):


	distances=[]
	for i in range(0,len(train_img_hists)):

		result_hist=abs(one_test_img_hist-train_img_hists[i])*abs(one_test_img_hist-train_img_hists[i])

		#print("///////classification///////",result_hist)

		distance= (result_hist.sum())**(0.5)
		distances.append(distance)
	
	
	
	find_mins(distances,labels,test,name)

def find_mins(distances,labels,test,name):
	print ("find_mins")
	

	
	min_distances=[]
	min_labels=[]
	knn_k=256

	for i in range(1,knn_k+1):
		
		min_index=distances.index(min(distances))
		
		
		
		min_distances.append(distances[min_index])
		min_labels.append(labels[min_index])
		
		
		distances[min_index]=9999
		
	
	test.append( (min_distances,min_labels,name))
	
	









def give_index(i):

	if(i=="apple"):
		return 0
	elif(i=="aquarium_fish"):
		return 1
	elif(i=="beetle"):
		return 2
	elif(i=="camel"):
		return 3
	elif(i=="crab"):
		return 4
	elif(i=="cup"):
		return 5
	elif(i=="elephant"):
		return 6
	elif(i=="flatfish"):
		return 7
	elif(i=="lion"):
		return 8
	elif(i=="mushroom"):
		return 9
	elif(i=="orange"):
		return 10
	elif(i=="pear"):
		return 11
	elif(i=="road"):
		return 12
	elif(i=="skyscraper"):
		return 13
	else:
		return 14

def find_index(classes,name):
	for i in range(0,15):
		if(name==classes[i]):
			return i
	return i

def Final_guess(tuplee):
	classes=["apple","aquarium_fish","beetle","camel","crab","cup","elephant","flatfish","lion","mushroom","orange","pear","road","skyscraper","woman"]
	if(len(tuplee[1])==2 ):
		return tuplee[1][0]
	
	elif(len(tuplee[1])==1):
		return tuplee[1][0]
	

	
	else:
		labels=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
		for i in range(0,len(tuplee[1])):
			labels[give_index(tuplee[1][i])]=labels[give_index(tuplee[1][i])]+1
		maximum=max(labels)
		for i in range(0, len(tuplee[1])):

			if( labels[find_index( classes ,tuplee[1][i] )]== maximum):
				return tuplee[1][i]




#***************************************************************************************************************
'''
en son gun odtuclassa koyulan test imagelerin histogramlarini hesapliyor
'''

cluster_centers=[]
read_from_cluster_centers(cluster_centers)
cluster_centers=np.array(cluster_centers)



train_img_hists=[]
read_from_train_img_hist(train_img_hists)
train_img_hists=np.array(train_img_hists)




labels=[]
read_from_labels(labels)





BOF=[]
read_from_BOF(BOF)


BOF=np.array(BOF)


kmeans = MiniBatchKMeans(n_clusters=256)
#kmeans.fit(BOF)
#cluster_centers=kmeans.cluster_centers_ #cluster centerlar burda
kmeans.cluster_centers_=cluster_centers

#print cluster_centers



test=[]
test_img_features(kmeans,train_img_hists,labels,test) 


print ("len_test=",len(test))

result=[]
for i in range(0,len(test)):
	result.append( (test[i][2],Final_guess(test[i]) ) )

print ("len_result=",len(result))

for i in range(0,1500):
	f=open("results.txt","a+")
	f.write("%s: %s\n"  %( result[i][0],result[i][1] ))


