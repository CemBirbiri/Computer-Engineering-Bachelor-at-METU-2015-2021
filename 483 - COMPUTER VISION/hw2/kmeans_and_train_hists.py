import numpy as np
import cv2 
import scipy.signal
from scipy.signal import convolve2d
import math
import os
import glob
from scipy import ndimage

from os import listdir
from os.path import isfile, join

from matplotlib import pyplot
#import skimage.data as skid

import pylab as plt
from sklearn.cluster import KMeans
from sklearn.cluster import MiniBatchKMeans


import matplotlib.pyplot as plt
import ast





def read_from_BOF(BOF):
	filepath2 = '/home/bs05/e2171379/Desktop/cv_hw2/BOF/BOF_ss5.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		while line:
	       
	       
	       	
			des=ast.literal_eval(line)
			BOF.append(des)
			line = fp.readline()
		
		

#def train_img_histograms(train_img_hist,kmeans,labels):		
def train_img_histograms(train_img_hist,kmeans):
	classes=["apple","aquarium_fish","beetle","camel","crab","cup","elephant","flatfish","lion","mushroom","orange","pear","road","skyscraper","woman"]
	#classes=["apple","elephant"]
	i=0
	while(i!=15):
		train_img_histograms_helper(classes[i],train_img_hist,kmeans)
		#train_img_histograms_helper(classes[i],train_img_hist,kmeans,labels)
		i=i+1


#def train_img_histograms_helper(class_name,train_img_hist,kmeans,labels):
def train_img_histograms_helper(class_name,train_img_hist,kmeans):
	for i in range(101,501):
		descr=[] #her training imagein featurelari descr arrayinda toplanip bu imagein histogrami icin islem gorecek
		

		#labels.append(class_name)
		
		#f=open("labels_k16_ss5.txt","a+")
		#f.write("%s\r\n"  %( class_name))		

		
		strr= "0"+str(i)+".png"
		filepath = '/home/bs05/e2171379/Desktop/cv_hw2/the2_data/train/'+class_name+'/'+strr 

		img=cv2.imread(filepath)

		gray= cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		sift = cv2.xfeatures2d.SIFT_create()
		
		kp = sift.detect(gray,None)
		
		kp,des = sift.compute(gray,kp)

		
		
		
		if( type(des)!=np.ndarray): #DSIFT kullaniyoruz burda cunku SIFT ile descriptor bulamiyoruz

			step_size = 3  #CHANGE HERE FOR STEP_SIZE
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

		

		make_hist_for_train_imgs(descriptors,kmeans,train_img_hist)

def make_hist_for_train_imgs(descriptors,kmeans,train_img_histograms):
	
	
	predict=kmeans.predict(descriptors)
	
	cluster_centers=[]
	
	for i in range(1,257):  #CHANGE HERE FOR NUMBER OF CLUSTER CENTER
		cluster_centers.append(i)
	
	#cluster_centers=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17]
	#cluster_centers=[1,2,3,4]
	hist,bin_edges=np.histogram(predict,cluster_centers)
	'''en son burdayiz, histogram cikarttik, bu histogrami normalize edip bir file a kaydetmek gerekiyor
	'''

	
	hist=np.array(hist)

	
	
	hist = hist/(sum(hist)*1.0)
	


	f=open("train_img_his_k256_ss3.txt","a+")
	f.write("%s\r\n"  %( hist.tolist() ))

	

	train_img_histograms.append(hist)		   

#****************************************************************************************************


#labels=[]
		
BOF=[]
read_from_BOF(BOF)

BOF=np.array(BOF)

print len(BOF)


kmeans = MiniBatchKMeans(n_clusters=256) #CHANGE HERE FOR CLUSTER CENTER
kmeans.fit(BOF)
cluster_centers=kmeans.cluster_centers_ #cluster centerlar burda

for i in range(len(cluster_centers)):
	f=open("clus_centers_k256_ss3.txt","a+")
	f.write("%s\r\n"  %( cluster_centers[i].tolist() ))



train_img_hists=[]


#train_img_histograms(train_img_hists,kmeans,labels)
train_img_histograms(train_img_hists,kmeans)
print len(train_img_hists)