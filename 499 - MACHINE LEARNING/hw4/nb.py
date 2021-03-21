#UFUK CEM BİRBİRİ
#e2171379


#Loading data on Google Colab:
#!wget http://user.ceng.metu.edu.tr/~artun/ceng499/hw4_files.zip
#!unzip hw4_files.zip

import numpy as np


def is_in(element, listt):
  for i in range(0,len(listt)):
    if listt[i]==element:
      return 1
  return 0

def vocabulary(data):
  """
  Creates the vocabulary from the data.
  :param data: List of lists, every list inside it contains words in that sentence.
                len(data) is the number of examples in the data.
  :return: Set of words in the data
  """
  vocab=[]
  for i in range(0,len(data)):
    for j in range(0,len(data[i])):
      if is_in(data[i][j], vocab)==0:
        vocab.append(data[i][j])

  vocab=set(vocab)

  

  return vocab

def find_classes(train_labels):
  classes=[]
  for i in range(0,len(train_labels)):
    if is_in(train_labels[i],classes)==0:
      classes.append(train_labels[i])
  return classes

def make_theta(class_name,train_data, train_labels, vocab):
  bow={}
  len_vocab=0
  for k1 in vocab:
    bow[k1]=0
    len_vocab+=1

  total_words=0
  for i in range(0,len(train_labels)):
    if class_name==train_labels[i]:
      for j in range(0,len(train_data[i])):
        total_words+=1
        bow[train_data[i][j]]+=1

  for k2 in vocab:
    bow[k2]=(bow[k2]+1)/(total_words+len_vocab)
  return bow


def train(train_data, train_labels, vocab):
  #print("train girdi")
  
  #1- Convert every example into bag of words
  bag_of_words=[]
  for i in range(0,len(train_data)):
    vocab_dic= {}
    for k in vocab:
      vocab_dic[k]=0  
    for j in range(0,len(train_data[i])):    
      vocab_dic[train_data[i][j]]+=1
    bag_of_words.append(vocab_dic)
    
  #2- Find classes
  classes=find_classes(train_labels)

  #3- Create pi
  pi_temp=[]
  for i in range(0,len(classes)):
    pi_temp.append([classes[i],0])

  for i in range(0,len(pi_temp)):
    for j in range(0,len(train_labels)):
      if train_labels[j]==pi_temp[i][0]:
        pi_temp[i][1]+=1
  for i in range(0,len(pi_temp)):
    pi_temp[i][1]= pi_temp[i][1]/len(train_labels)
  pi={}
  for k in classes:
      pi[k]=0
  for i in range(0,len(pi_temp)):
    pi[pi_temp[i][0]]=pi_temp[i][1]

  #4- Create theta
  theta={}
  for k in classes:
      theta[k]=make_theta(k,train_data, train_labels, vocab)

  return theta, pi


def test(theta, pi, vocab, test_data):
  #print("teste girdi")



  #1- Detect classes
  classes=[]
  for k1 in pi:
    classes.append(k1)
  #2- Detect words in vocab
  words_in_vocab=[]
  for k5 in vocab:
    words_in_vocab.append(k5)

  #3-
  scores=[]
  #print("score-1")
  bow=[]
  for i in range(0,len(test_data)):#For every element in test data,
    #create a bag of words.
    bag_of_words={}
    for k in vocab:
      bag_of_words[k]=0
    for j in range(0,len(test_data[i])):
      #Check whether the word is in vocab, if not then skip
      if is_in(test_data[i][j], words_in_vocab)==1:
        bag_of_words[test_data[i][j]]+=1
    bow.append(bag_of_words)
  #print("score-2")
  for i in range(0,len(test_data)): 
    #############
    temp=[]
    for c in classes:#For every class,
      summ=0
      score=0
      for k2 in vocab:       
        summ = summ + (bow[i][k2]* np.log(theta[c][k2]))
      score = np.log(pi[c]) + summ #calculate score
      temp.append((score,c))
    scores.append(temp)
  #print(scores)
  #print("len(scores)test ici=", len(scores))


  return scores






import numpy as np
#from nb import vocabulary, train, test

def is_in(element,listt):
  for i in range(0,len(listt)):
    if listt[i]==element:
      return 1
  return 0

train_data_path="/content/hw4_files/hw4_data/news/train_data.txt"
train_labels_path="/content/hw4_files/hw4_data/news/train_labels.txt"
test_data_path="/content/hw4_files/hw4_data/news/test_data.txt"
test_labels_path="/content/hw4_files/hw4_data/news/test_labels.txt"

######### train_data#########
file1 = open(train_data_path, 'r')
train_data=[] 
while True:
  line = file1.readline() 
  if not line:
    break
  line = line.strip()
  #print(line)
  listt=[".", ",", "(", ")", ":", ";", "[" ,"]", "‘" ,"!" ,"*" ]
  new_line=""
  for i in range(0,len(line)):
    if is_in(line[i], listt)==0:
      new_line=new_line+line[i]
  new_line=new_line.split(" ")
  #print(new_line)
  new_line2=[]
  for i in range(0,len(new_line)):
    if new_line[i]!="":
      new_line2.append(new_line[i])
  #print(new_line2)
  train_data.append(new_line2)
file1.close()


######### train_labels #########
file1 = open(train_labels_path, 'r')
train_labels=[] 
while True:
  line = file1.readline() 
  if not line:
    break
  line = line.strip()
  train_labels.append(line)
file1.close()

#print(len(train_data))
#print(len(train_labels))

######### test_data #########
file1 = open(test_data_path, 'r')
test_data=[] 
while True:
  line = file1.readline() 
  if not line:
    break
  line = line.strip()
  #print(line)
  listt=[".", ",", "(", ")", ":", ";", "[" ,"]", "‘" ,"!" ,"*" ]
  new_line=""
  for i in range(0,len(line)):
    if is_in(line[i], listt)==0:
      new_line=new_line+line[i]
  new_line=new_line.split(" ")
  #print(new_line)
  new_line2=[]
  for i in range(0,len(new_line)):
    if new_line[i]!="":
      new_line2.append(new_line[i])
  #print(new_line2)
  test_data.append(new_line2)
file1.close()

######### test_labels #########
file1 = open(test_labels_path, 'r')
test_labels=[] 
while True:
  line = file1.readline() 
  if not line:
    break
  line = line.strip()
  test_labels.append(line)
file1.close()

#print(len(test_data))
#print(len(test_labels))



vocab = vocabulary(train_data)
theta, pi = train(train_data, train_labels, vocab)
#print("theta bitti")
scores = test(theta, pi, vocab, test_data),
#print("scores bitti")
#print("len(scores) =",len(scores))
#print("len(scores) =",len(scores[0]))
#print("len(test_labels) =",len(test_labels))
scores=scores[0]
#print("scores[0]=",scores[0])
predicted=[]
for i in range(0,len(scores)):
  max=-99999
  predicted_class=""
  for j in range(0,len(scores[i])):
    if scores[i][j][0]> max:
      max=scores[i][j][0]
      predicted_class=scores[i][j][1]
  predicted.append(predicted_class)

#print("len(predicted) =",len(predicted))
#print("len(test_labels) =",len(test_labels))
true=0
false=0
for i in range(0,len(predicted)):
  if predicted[i]==test_labels[i]:
    true+=1
  else:
    false+=1

print("ACCURACY=", ((1.0)* true)/ (true+false))