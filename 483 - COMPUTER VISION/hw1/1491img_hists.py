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
def find_index(value,bin):
	i=1
	kat=256.0/bin
	while (i<=bin+1):
		
		
		if (value < (kat*i)):
	 
			return i-1
		else:
			i=i+1
	return -1
def find_index_for_orientation(value,bin):
	i=1
	kat=180.0/bin
	while (i<=bin+1):
		
		
		if (value < (kat*i)):
	 
			return i-1
		else:
			i=i+1
	return -1
def Myhistogram_color(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	
	h=np.zeros((bin,bin,bin))
	

	for row in range(0,row_bound):
		for col in range(0,col_bound):
	
			index0=find_index(img[row][col][0],bin)

			index1=find_index(img[row][col][1],bin)
			index2=find_index(img[row][col][2],bin)
			
			h[index0][index1][index2]+=1

	
	return h
  
def Myhistogram_grayScale1(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])
	h=np.zeros((bin,1))
	for row in range(0,row_bound):
		for col in range(0,col_bound):
	
		
			index=find_index(img[row][col],bin)
			h[index][0]+=1	
	
	
		
	
	h=np.asarray(h)
	h=h/ h.sum()
	return h
def level3_hist_gradient(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,1))
	h2=np.zeros((bin,1))
	h3=np.zeros((bin,1))
	h4=np.zeros((bin,1))

	h5=np.zeros((bin,1))
	h6=np.zeros((bin,1))
	h7=np.zeros((bin,1))
	h8=np.zeros((bin,1))

	h9=np.zeros((bin,1))
	h10=np.zeros((bin,1))
	h11=np.zeros((bin,1))
	h12=np.zeros((bin,1))

	h13=np.zeros((bin,1))
	h14=np.zeros((bin,1))
	h15=np.zeros((bin,1))
	h16=np.zeros((bin,1))

	crop_img1 = img[0:(len(img)/4), 0:(len(img[0])/4)]	
	crop_img2 = img[0:(len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img3 = img[0:(len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img4 = img[0:(len(img)/4), (3*len(img)/4):(len(img))]

	crop_img5 = img[(len(img)/4):(len(img)/2), 0:(len(img[0])/4)]	
	crop_img6 = img[(len(img)/4):(len(img)/2), (len(img)/4):(len(img)/2)]
	crop_img7 = img[(len(img)/4):(len(img)/2), (len(img)/2):(3*len(img)/4)]
	crop_img8 = img[(len(img)/4):(len(img)/2), (3*len(img)/4):(len(img))]

	crop_img9 = img[(len(img)/2):(3*len(img)/4), 0:(len(img[0])/4)]	
	crop_img10 = img[(len(img)/2):(3*len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img11= img[(len(img)/2):(3*len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img12= img[(len(img)/2):(3*len(img)/4), (3*len(img)/4):(len(img))]

	crop_img13 = img[(3*len(img)/4):(len(img)), 0:(len(img[0])/4)]	
	crop_img14 = img[(3*len(img)/4):(len(img)), (len(img)/4):(len(img)/2)]
	crop_img15 = img[(3*len(img)/4):(len(img)), (len(img)/2):(3*len(img)/4)]
	crop_img16 = img[(3*len(img)/4):(len(img)), (3*len(img)/4):(len(img))]

	h1=gradient_grayscale_orientation(crop_img1,bin)
	h2=gradient_grayscale_orientation(crop_img2,bin)
	h3=gradient_grayscale_orientation(crop_img3,bin)
	h4=gradient_grayscale_orientation(crop_img4,bin)
	
	h5=gradient_grayscale_orientation(crop_img5,bin)
	h6=gradient_grayscale_orientation(crop_img6,bin)
	h7=gradient_grayscale_orientation(crop_img7,bin)
	h8=gradient_grayscale_orientation(crop_img8,bin)

	h9=gradient_grayscale_orientation(crop_img9,bin)
	h10=gradient_grayscale_orientation(crop_img10,bin)
	h11=gradient_grayscale_orientation(crop_img11,bin)
	h12=gradient_grayscale_orientation(crop_img12,bin)
	
	h13=gradient_grayscale_orientation(crop_img13,bin)
	h14=gradient_grayscale_orientation(crop_img14,bin)
	h15=gradient_grayscale_orientation(crop_img15,bin)
	h16=gradient_grayscale_orientation(crop_img16,bin)
	


	h1=h1/(row_bound*col_bound)
	h2=h2/(row_bound*col_bound)
	h3=h3/(row_bound*col_bound)
	h4=h4/(row_bound*col_bound)	

	h5=h5/(row_bound*col_bound)
	h6=h6/(row_bound*col_bound)
	h7=h7/(row_bound*col_bound)
	h8=h8/(row_bound*col_bound)	

	h9=h9/(row_bound*col_bound)
	h10=h10/(row_bound*col_bound)
	h11=h11/(row_bound*col_bound)
	h12=h12/(row_bound*col_bound)	

	h13=h13/(row_bound*col_bound)
	h14=h14/(row_bound*col_bound)
	h15=h15/(row_bound*col_bound)
	h16=h16/(row_bound*col_bound)	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)
	hist3=np.concatenate((h5,h6),1,)
	hist4=np.concatenate((h7,h8),1,)
	
	hist5=np.concatenate((h9,h10),1,)
	hist6=np.concatenate((h11,h12),1,)
	hist7=np.concatenate((h13,h14),1,)
	hist8=np.concatenate((h15,h16),1,)

	hh1=np.concatenate((hist1,hist2),1,)
	hh2=np.concatenate((hist3,hist4),1,)
	hh3=np.concatenate((hist5,hist6),1,)
	hh4=np.concatenate((hist7,hist8),1,)

	hhh1=np.concatenate((hh1,hh2),1,)
	hhh2=np.concatenate((hh3,hh4),1,)

	result=np.concatenate((hhh1,hhh2),1,)

	return result
def level2_hist_gradient(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,1))
	h2=np.zeros((bin,1))
	h3=np.zeros((bin,1))
	h4=np.zeros((bin,1))

	crop_img1 = img[0:(len(img)/2), 0:(len(img[0])/2)]	

	crop_img2 = img[(len(img)/2):(len(img)), 0:(len(img[0])/2)]
	
	crop_img3 = img[0:(len(img)/2), (len(img[0])/2):(len(img[0]))]
	
	crop_img4 = img[(len(img)/2):(len(img)), (len(img[0])/2):(len(img[0]))]

	h1=gradient_grayscale_orientation(crop_img1,bin)
	h2=gradient_grayscale_orientation(crop_img2,bin)
	h3=gradient_grayscale_orientation(crop_img3,bin)
	h4=gradient_grayscale_orientation(crop_img4,bin)
	
	h1=h1/(row_bound*col_bound)
	h2=h2/(row_bound*col_bound)
	h3=h3/(row_bound*col_bound)
	h4=h4/(row_bound*col_bound)	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)

	result=np.concatenate((hist1,hist2),1,)

	return result
def gradient_grayscale_orientation(img,bin):
	
	h=np.zeros((bin,1))

	kernel_dx=[[1 ,0 ,-1],[2, 0, -2],[1 ,0 ,-1]]
	kernel_dy=[[1 ,2 ,1],[0, 0, 0],[-1 ,-2 ,-1]]
	
	new_img_dx=ndimage.convolve(img, kernel_dx,None,'mirror',0,0)
	new_img_dy=ndimage.convolve(img, kernel_dy,None,'mirror',0,0)
	row_bound=len(img)
	col_bound=len(img[0])


	for row in range(0,row_bound):
		for col in range(0,col_bound):
			x=new_img_dx[row][col]
			y=new_img_dy[row][col]
					
			if(y==0):
				orientation=0
			else:
				orientation= math.degrees(math.atan(x/y))
				orientation+=90
			


			magnitude=(x**2+y**2)**(0.5)
			index=find_index_for_orientation(orientation,bin)
			h[index][0]+=magnitude
		
	return h


			
def level2_hist_grayscale(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,1))
	h2=np.zeros((bin,1))
	h3=np.zeros((bin,1))
	h4=np.zeros((bin,1))

	crop_img1 = img[0:(len(img)/2), 0:(len(img[0])/2)]	

	crop_img2 = img[(len(img)/2):(len(img)), 0:(len(img[0])/2)]
	
	crop_img3 = img[0:(len(img)/2), (len(img[0])/2):(len(img[0]))]
	
	crop_img4 = img[(len(img)/2):(len(img)), (len(img[0])/2):(len(img[0]))]

	h1=Myhistogram_grayScale1(crop_img1,bin)
	h2=Myhistogram_grayScale1(crop_img2,bin)
	h3=Myhistogram_grayScale1(crop_img3,bin)
	h4=Myhistogram_grayScale1(crop_img4,bin)
	
	h1=h1/(row_bound*col_bound)
	h2=h2/(row_bound*col_bound)
	h3=h3/(row_bound*col_bound)
	h4=h4/(row_bound*col_bound)	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)

	result=np.concatenate((hist1,hist2),1,)

	return result
def level3_hist_grayscale(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,1))
	h2=np.zeros((bin,1))
	h3=np.zeros((bin,1))
	h4=np.zeros((bin,1))

	h5=np.zeros((bin,1))
	h6=np.zeros((bin,1))
	h7=np.zeros((bin,1))
	h8=np.zeros((bin,1))

	h9=np.zeros((bin,1))
	h10=np.zeros((bin,1))
	h11=np.zeros((bin,1))
	h12=np.zeros((bin,1))

	h13=np.zeros((bin,1))
	h14=np.zeros((bin,1))
	h15=np.zeros((bin,1))
	h16=np.zeros((bin,1))

	crop_img1 = img[0:(len(img)/4), 0:(len(img[0])/4)]	
	crop_img2 = img[0:(len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img3 = img[0:(len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img4 = img[0:(len(img)/4), (3*len(img)/4):(len(img))]

	crop_img5 = img[(len(img)/4):(len(img)/2), 0:(len(img[0])/4)]	
	crop_img6 = img[(len(img)/4):(len(img)/2), (len(img)/4):(len(img)/2)]
	crop_img7 = img[(len(img)/4):(len(img)/2), (len(img)/2):(3*len(img)/4)]
	crop_img8 = img[(len(img)/4):(len(img)/2), (3*len(img)/4):(len(img))]

	crop_img9 = img[(len(img)/2):(3*len(img)/4), 0:(len(img[0])/4)]	
	crop_img10 = img[(len(img)/2):(3*len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img11= img[(len(img)/2):(3*len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img12= img[(len(img)/2):(3*len(img)/4), (3*len(img)/4):(len(img))]

	crop_img13 = img[(3*len(img)/4):(len(img)), 0:(len(img[0])/4)]	
	crop_img14 = img[(3*len(img)/4):(len(img)), (len(img)/4):(len(img)/2)]
	crop_img15 = img[(3*len(img)/4):(len(img)), (len(img)/2):(3*len(img)/4)]
	crop_img16 = img[(3*len(img)/4):(len(img)), (3*len(img)/4):(len(img))]

	h1=Myhistogram_grayScale1(crop_img1,bin)
	h2=Myhistogram_grayScale1(crop_img2,bin)
	h3=Myhistogram_grayScale1(crop_img3,bin)
	h4=Myhistogram_grayScale1(crop_img4,bin)
	
	h5=Myhistogram_grayScale1(crop_img5,bin)
	h6=Myhistogram_grayScale1(crop_img6,bin)
	h7=Myhistogram_grayScale1(crop_img7,bin)
	h8=Myhistogram_grayScale1(crop_img8,bin)

	h9=Myhistogram_grayScale1(crop_img9,bin)
	h10=Myhistogram_grayScale1(crop_img10,bin)
	h11=Myhistogram_grayScale1(crop_img11,bin)
	h12=Myhistogram_grayScale1(crop_img12,bin)
	
	h13=Myhistogram_grayScale1(crop_img13,bin)
	h14=Myhistogram_grayScale1(crop_img14,bin)
	h15=Myhistogram_grayScale1(crop_img15,bin)
	h16=Myhistogram_grayScale1(crop_img16,bin)
	


	h1=h1/(row_bound*col_bound)
	h2=h2/(row_bound*col_bound)
	h3=h3/(row_bound*col_bound)
	h4=h4/(row_bound*col_bound)	

	h5=h5/(row_bound*col_bound)
	h6=h6/(row_bound*col_bound)
	h7=h7/(row_bound*col_bound)
	h8=h8/(row_bound*col_bound)	

	h9=h9/(row_bound*col_bound)
	h10=h10/(row_bound*col_bound)
	h11=h11/(row_bound*col_bound)
	h12=h12/(row_bound*col_bound)	

	h13=h13/(row_bound*col_bound)
	h14=h14/(row_bound*col_bound)
	h15=h15/(row_bound*col_bound)
	h16=h16/(row_bound*col_bound)	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)
	hist3=np.concatenate((h5,h6),1,)
	hist4=np.concatenate((h7,h8),1,)
	
	hist5=np.concatenate((h9,h10),1,)
	hist6=np.concatenate((h11,h12),1,)
	hist7=np.concatenate((h13,h14),1,)
	hist8=np.concatenate((h15,h16),1,)

	hh1=np.concatenate((hist1,hist2),1,)
	hh2=np.concatenate((hist3,hist4),1,)
	hh3=np.concatenate((hist5,hist6),1,)
	hh4=np.concatenate((hist7,hist8),1,)

	hhh1=np.concatenate((hh1,hh2),1,)
	hhh2=np.concatenate((hh3,hh4),1,)

	result=np.concatenate((hhh1,hhh2),1,)

	return result
def level3_hist_color(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,1))
	h2=np.zeros((bin,1))
	h3=np.zeros((bin,1))
	h4=np.zeros((bin,1))

	h5=np.zeros((bin,1))
	h6=np.zeros((bin,1))
	h7=np.zeros((bin,1))
	h8=np.zeros((bin,1))

	h9=np.zeros((bin,1))
	h10=np.zeros((bin,1))
	h11=np.zeros((bin,1))
	h12=np.zeros((bin,1))

	h13=np.zeros((bin,1))
	h14=np.zeros((bin,1))
	h15=np.zeros((bin,1))
	h16=np.zeros((bin,1))

	crop_img1 = img[0:(len(img)/4), 0:(len(img[0])/4)]	
	crop_img2 = img[0:(len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img3 = img[0:(len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img4 = img[0:(len(img)/4), (3*len(img)/4):(len(img))]

	crop_img5 = img[(len(img)/4):(len(img)/2), 0:(len(img[0])/4)]	
	crop_img6 = img[(len(img)/4):(len(img)/2), (len(img)/4):(len(img)/2)]
	crop_img7 = img[(len(img)/4):(len(img)/2), (len(img)/2):(3*len(img)/4)]
	crop_img8 = img[(len(img)/4):(len(img)/2), (3*len(img)/4):(len(img))]

	crop_img9 = img[(len(img)/2):(3*len(img)/4), 0:(len(img[0])/4)]	
	crop_img10 = img[(len(img)/2):(3*len(img)/4), (len(img)/4):(len(img)/2)]
	crop_img11= img[(len(img)/2):(3*len(img)/4), (len(img)/2):(3*len(img)/4)]
	crop_img12= img[(len(img)/2):(3*len(img)/4), (3*len(img)/4):(len(img))]

	crop_img13 = img[(3*len(img)/4):(len(img)), 0:(len(img[0])/4)]	
	crop_img14 = img[(3*len(img)/4):(len(img)), (len(img)/4):(len(img)/2)]
	crop_img15 = img[(3*len(img)/4):(len(img)), (len(img)/2):(3*len(img)/4)]
	crop_img16 = img[(3*len(img)/4):(len(img)), (3*len(img)/4):(len(img))]


	
	h1=Myhistogram_color(crop_img1,bin)
	h2=Myhistogram_color(crop_img2,bin)
	h3=Myhistogram_color(crop_img3,bin)
	h4=Myhistogram_color(crop_img4,bin)
	
	h5=Myhistogram_color(crop_img5,bin)
	h6=Myhistogram_color(crop_img6,bin)
	h7=Myhistogram_color(crop_img7,bin)
	h8=Myhistogram_color(crop_img8,bin)

	h9=Myhistogram_color(crop_img9,bin)
	h10=Myhistogram_color(crop_img10,bin)
	h11=Myhistogram_color(crop_img11,bin)
	h12=Myhistogram_color(crop_img12,bin)
	
	h13=Myhistogram_color(crop_img13,bin)
	h14=Myhistogram_color(crop_img14,bin)
	h15=Myhistogram_color(crop_img15,bin)
	h16=Myhistogram_color(crop_img16,bin)
	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)
	hist3=np.concatenate((h5,h6),1,)
	hist4=np.concatenate((h7,h8),1,)
	
	hist5=np.concatenate((h9,h10),1,)
	hist6=np.concatenate((h11,h12),1,)
	hist7=np.concatenate((h13,h14),1,)
	hist8=np.concatenate((h15,h16),1,)

	hh1=np.concatenate((hist1,hist2),1,)
	hh2=np.concatenate((hist3,hist4),1,)
	hh3=np.concatenate((hist5,hist6),1,)
	hh4=np.concatenate((hist7,hist8),1,)

	hhh1=np.concatenate((hh1,hh2),1,)
	hhh2=np.concatenate((hh3,hh4),1,)

	result=np.concatenate((hhh1,hhh2),1,)

	return result

def level2_hist_color(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h1=np.zeros((bin,bin,bin))
	h2=np.zeros((bin,bin,bin))
	h3=np.zeros((bin,bin,bin))
	h4=np.zeros((bin,bin,bin))

	crop_img1 = img[0:(len(img)/2), 0:(len(img[0])/2)]	

	crop_img2 = img[(len(img)/2):(len(img)), 0:(len(img[0])/2)]
	
	crop_img3 = img[0:(len(img)/2), (len(img[0])/2):(len(img[0]))]
	
	crop_img4 = img[(len(img)/2):(len(img)), (len(img[0])/2):(len(img[0]))]


	h1=Myhistogram_color(crop_img1,bin)
	h2=Myhistogram_color(crop_img2,bin)
	h3=Myhistogram_color(crop_img3,bin)
	h4=Myhistogram_color(crop_img4,bin)
	
	h1=h1/(row_bound*col_bound)
	h2=h2/(row_bound*col_bound)
	h3=h3/(row_bound*col_bound)
	h4=h4/(row_bound*col_bound)	

	hist1=np.concatenate((h1,h2),1,)
	hist2=np.concatenate((h3,h4),1,)

	result=np.concatenate((hist1,hist2),1,)

	return result
def Myhistogram_2(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	
	h=np.zeros((bin,1))
	

	for row in range(0,row_bound):
		for col in range(0,col_bound):

			index3=find_index(img[row][col][2],bin)
			h[index3][0]+=1	
	return h
def Myhistogram_0(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	
	h=np.zeros((bin,1))


	for row in range(0,row_bound):
		for col in range(0,col_bound):
			index0=find_index(img[row][col][0],bin)
			h[index0][0]+=1	
	return h
def Myhistogram_1(img,bin):
	row_bound=len(img)
	col_bound=len(img[0])

	h=np.zeros((bin,1))
	

	for row in range(0,row_bound):
		for col in range(0,col_bound):
	
		
			index1=find_index(img[row][col][1],bin)
			h[index1][0]+=1	
	return h
def my_best(img_color,img_grayscale,bin):
	
	h_0=np.zeros((bin,1))
	h_1=np.zeros((bin,1))	
	h_2=np.zeros((bin,1))
	
	h_gray=np.zeros((bin,1))

	h_0=Myhistogram_0(img_color,bin)
	h_1=Myhistogram_1(img_color,bin)
	h_2=Myhistogram_2(img_color,bin)
	
	h_gray=Myhistogram_grayScale1(img_grayscale,bin)
	
	temp1=np.concatenate((h_0,h_1),1)
	temp2=np.concatenate((h_2,h_gray),1)
	result=np.concatenate((temp1,temp2),1)
	
	return result
#****************************************************************************************************************************************************************************************************
'''
images.dat dan okunan imagei datasette bulup --mybest_1491()-- fonsiyonunun oldugu yere uygun fonksiyonu yazarak 1491 image icin istedigimiz histogrami buluyor
'''
def find_in_dataset_1491():
	 
	filepath = '/home/bs05/e2172195/Downloads/hw/images.dat' 
	with open(filepath) as fp:  
	   line = fp.readline()
	   
	   while line:
	       
	       find_in_dataset_1491_helper( line.strip())
	       #print type(line.strip() )
	       line = fp.readline()
       



def find_in_dataset_1491_helper(strr): #1491 fotografi original datasetten bulup grayscale/color/gradient histogramini cikartiyor.

	filepath = '/home/bs05/e2172195/Downloads/hw/dataset/' + strr
	
	img1 = cv2.imread(filepath,1)
	img2=cv2.imread(filepath,0)
	f=open("mybest_1491.txt","a+")
	f.write("%s %s\r\n"  %( strr, mybest_1491(img1,img2,10).tolist() ))
	
find_in_dataset_1491()

#****************************************************************************************************************************************************************************************************



        
        



     