import numpy as np
import cv2
import scipy.signal
from scipy.signal import convolve2d
import math
import os
import glob
import ast

from os import listdir
from os.path import isfile, join


def euclidean_distance(hist1,hist2):
	
	
	hist1=np.asarray(hist1)
	hist2=np.asarray(hist2)
	
	hist1=hist1/hist1.sum()
	hist2=hist2/hist2.sum()

	hist=(hist1-hist2)*(hist1-hist2)

	result= (hist.sum())**(0.5)
	return result
	
'''
datasetteki 1491 image'in ve 400 imagein histogramlari ciktiktan sonra result.txt dosyasini hazirlamaya yariyor. result.txt dosyasi da convert_eval.py de kullaniliyor
'''


def query_images400():
	#filepath2 = '/home/bs05/e2171379/Desktop/src/color_histograms/deneme2.txt' 

	filepath2 = '/home/bs05/e2172195/Downloads/hw/mybest_100.txt' 
	with open(filepath2) as fp:  
		line = fp.readline()
		
		   
		while line:


			new_line= line.strip()
			name=new_line[:15]
			
			new_line=new_line[15:]
			
			histogram_400=ast.literal_eval(new_line)
			
						
			f=open("mybest_result.txt","a+")
			#f=open("sorted.txt","a+")
			
			f.write("%s: " %(name) )
			

			query_images1491(histogram_400,f)
			
			f.write("\r\n"   )		   
			line = fp.readline()

			
def query_images1491(histogram,f):#resut.txt dosyasini bastirmak icin
	
	filepath1 = '/home/bs05/e2171379/Downloads/hw/mybest_1491.txt'
	 
	with open(filepath1) as fp:  
		line = fp.readline()
		   
		while line:


		       
			new_line= line.strip()
			name=new_line[:15]
			new_line=new_line[15:]

			hist_1491=ast.literal_eval(new_line)
			#print euclidean_grayscale(histogram,hist_1491)
					    
					    
			
			f.write("%s %s" %(euclidean_distance((histogram),(hist_1491)), name)  )

			#f.write("%s  " %(euclidean_grayscale1(histogram,hist_1491), name)  )
			
						
			line = fp.readline()		


query_images400()








