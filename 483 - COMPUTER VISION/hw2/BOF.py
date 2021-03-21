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







def BOF_SIFT():
	
	classes=["apple","aquarium_fish","beetle","camel","crab","cup","elephant","flatfish","lion","mushroom","orange","pear","road","skyscraper","woman"]
	#classes=["apple","elephant"]

	i=0
	while(i!=15):
		BOF_SIFT_helper(classes[i])
		i=i+1


def BOF_SIFT_helper(class_name):
	'''
	take images from dataset and find interest points usinf SIFT
	'''
	

	for i in range(101,501):
		

		strr= "0"+str(i)+".png"
		filepath = '/home/bs05/e2171379/Desktop/cv_hw2/the2_data/train/'+class_name+'/'+strr 

		img=cv2.imread(filepath)

		gray= cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
		sift = cv2.xfeatures2d.SIFT_create(nfeatures = 0,nOctaveLayers = 3,contrastThreshold = 0.0014,edgeThreshold = 10,sigma = 0.27 )
		
		kp = sift.detect(gray,None)
		
		kp,des = sift.compute(gray,kp)

		print ("-------training_img_features_BOF---------->",class_name, strr)
		
		
		if( type(des)!=np.ndarray): #DSIFT kullaniyoruz burda cunku SIFT ile descriptor bulamiyoruz

			step_size = 5   #CHANGE HERE FOR STEP_SIZE
			kp = [cv2.KeyPoint(x, y, step_size) for y in range(0, gray.shape[0], step_size) 
			                                    for x in range(0, gray.shape[1], step_size)]

			dense_feat,des = sift.compute(gray, kp)
			j=0
			while(j!=len(des)):

				f=open("BOF_ss5.txt","a+")
				f.write("%s\r\n"  %( des[j].tolist() ))
				
				j=j+1
			
			
			
		
		else:     #SIFT kullanarak descriptor buluyoruz
			j=0
			while(j!=len(des)):
				f=open("BOF_ss5.txt","a+")
				f.write("%s\r\n"  %( des[j].tolist() ))
				j=j+1







BOF_SIFT()  #BOF olusturuyor


