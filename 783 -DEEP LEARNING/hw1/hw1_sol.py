import numpy as np

def f(x,w,b): # do not change this line!
    # implement the function f() here
    # x is a N-by-D numpy array
    # w is a D dimensional numpy array
    # b is a scalar
    # Should return three things:
    # 1) the output of the f function, as a N dimensional numpy array,
    # 2) gradient of f with respect to w,
    # 3) gradient of f with respect to b


    x= np.asarray(x)

    t1 = np.dot( x , w) 

    

    output = np.zeros( t1.shape )
    
    
    df_dw = x
    

    df_db = np.zeros( t1.shape )

    for i in range(0,len(x)):
        
        
        if t1[i] <= (-1):
            
            output[i]=0
            df_dw[i] = 0
            df_db[i] = 0

        elif (-1) < t1[i] < 1 :

            output[i] = (t1[i]/2) + 0.5
            
            

            df_dw[i] = df_dw[i] * 0.5

            
            
            df_db[i] = 1 * (0.5)     
        
        elif t1[i] >= 1:

            output[i] = 1
            df_dw[i] = 0
            df_db[i] = 0

    
    
    
    return output , df_dw , df_db





def l2loss(x,y,w,b): # do not change this line!
    # implement the l2loss here
    # x is a N-by-D numpy array
    # y is a N dimensional numpy array
    # w is a D dimensional numpy array
    # b is a scalar
    # Should return three items:
    # 1) the L2 loss which is a scalar,
    # 2) the gradient of the loss with respect to w,
    # 3) the gradient of the loss with respect to b

    
    #w= np.reshape( w, (len(w),1) )
   

    #t = np.zeros( (len(x) ,1) )
    t = np.dot( x , w) 

      
    f_result , df_dw , df_db = f(x,w,b)



    
    dL2_dw = np.zeros(w.shape)
    dL2_db = 0 
    loss = 0


 

    for i in range(0, len(t)):
        #t[i] = np.sum(x[i]* w) +b
        #t[i] = np.sum( x[i] * w) +b 


        loss += np.sum( y[i] - f_result[i] ) * np.sum( y[i] - f_result[i] )


        if t[i] <= (-1):
            
            
            dL2_dw += 0
            
            dL2_db += 0
        
        elif (-1) < t[i] < 1:
            


            dL2_dw +=  np.sum(f_result[i] - y[i])  * df_dw[i]
            #dL2_dw += ( y[i] - f_result[i] ) * f_result[i] * (1- f_result[i]) * x[i]


            
            

            dL2_db += np.sum( f_result[i] - y[i]) * df_db[i]
        
        elif t[i] >=1:

            
            dL2_dw += 0
            dL2_db += 0

    dL2_dw = dL2_dw  / len(y)
    dL2_db = dL2_db  /len(y)
    loss = loss /len(y)

    return loss, dL2_dw , dL2_db


def minimize_l2loss(x,y,w,b, num_iters=1000, eta=0.0001): # do not change this line!
    # implement the gradient descent here
    # x is a N-by-D numpy array
    # y is a N dimensional numpy array
    # w is a D dimensional numpy array
    # b is a scalar
    # num_iters (optional) is number of iterations
    # eta (optional) is the stepsize for the gradient descent
    # Should return the final values of w and b
    
    for i in range(0,num_iters):
        loss , dL2_dw , dL2_db = l2loss(x,y,w,b)
        
        w = w - (eta * dL2_dw)
        b = b - (eta * dL2_db) 

    return w,b