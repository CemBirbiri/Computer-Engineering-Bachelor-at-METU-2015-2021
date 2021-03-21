#UFUK CEM BİRBİRİ
#e2171379


import numpy as np

def forward(A, B, pi, O):
  """
    Calculates the probability of an observation sequence O given the model(A, B, pi).
    :param A: state transition probabilities (NxN)
    :param B: observation probabilites (NxM)
    :param pi: initial state probabilities (N)
    :param O: sequence of observations(T) where observations are just indices for the 
    columns of B (0-indexed)
        N is the number of states,
        M is the number of possible observations, and
        T is the sequence length.
    :return: The probability of the observation sequence and the calculated alphas 
    in the Trellis diagram with shape (N, T) which should be a numpy array.
  """
  alphas= np.zeros((len(A), len(O)))
  for i in range(0,len(O)):
    if i==0:
      for j in range(0,len(A)):
        alpha0= pi[j] * B[j] [O[i]]
        alphas[j][0]= alpha0
      #print(alphas)
    else:
      
      for j in range(0,len(A)):
        summ=0
        for k in range(0,len(A)):   
          summ+= alphas[k][i-1] *A[k][j]* B[j][O[i]]
          #print(summ, alphas[k][i-1] ,A[k][j], B[j][O[i]]) 
        alphas[j][i]= summ
        #print(alphas)
  
  probability=0
  for a in range(0,len(alphas)):
    probability+=alphas[a][-1]
  return probability, alphas




def viterbi(A, B, pi, O):
  """
    Calculates the most likely state sequence given model(A, B, pi) and observation sequence.
    :param A: state transition probabilities (NxN)
    :param B: observation probabilites (NxM)
    :param pi: initial state probabilities(N)
    :param O: sequence of observations(T) where observations are just indices for the 
    columns of B (0-indexed)
        N is the number of states,
        M is the number of possible observations, and
        T is the sequence length.
    :return: The most likely state sequence with shape (T,) and the calculated deltas in the 
    Trellis diagram with shape (N, T). They should be numpy arrays.
  """
  deltas= np.zeros((len(A), len(O)))
  ks=[]
  for i in range(0,len(A)):
    ks.append([])
  for i in range(0,len(O)):
    if i==0:
      for j in range(0,len(A)):
        delta0= pi[j] * B[j] [O[i]]
        deltas[j][0]= delta0
      #print(deltas)
    else:
      
      for j in range(0,len(A)):
        maxx=-99999
        k_temp=0
        for k in range(0,len(A)):
          if  (deltas[k][i-1] *A[k][j]* B[j][O[i]])> maxx:
            maxx= deltas[k][i-1] *A[k][j]* B[j][O[i]]
            k_temp=k
          #print(summ, deltas[k][i-1] ,A[k][j], B[j][O[i]]) 
        deltas[j][i]= maxx
        ks[j].append(maxx)
        ks[j].append(k_temp)
        

        #print(deltas)
  
  #print(ks)
  #print("*******1")
  maxx=-99999
  max_index=0
  for a in range(0,len(deltas)):
    if deltas[a][-1]> maxx:
      maxx=deltas[a][-1]
      max_index=a
  path=[]
  for i in range(0,len(ks)):
    if ks[i][-2]==maxx:
      break
  #print(i)
  for j in range(1,len(ks[i]),2):
    path.append(ks[i][j])
  #print(path)
  path.append(max_index)
  path=np.array(path)
  
  return path, deltas

