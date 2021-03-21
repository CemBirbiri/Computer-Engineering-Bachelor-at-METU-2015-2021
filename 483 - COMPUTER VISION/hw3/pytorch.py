

from __future__ import print_function
import torch
import numpy as np

# magic command to produce plots directly below the plotting code
# %matplotlib inline

x = torch.Tensor(5, 3)

x = torch.randn(4, 4)
#print(x)
y = x.view(16)
#print(y)
z = x.view(-1, 8)  # the size -1 is inferred from other dimensions
#print(z)
#print(x)
#print(z)
#print(x.size(), y.size(), z.size())

'''

a1 = torch.ones(5)
b1 = a1.numpy()
a2 = np.ones(5)
b2 = torch.from_numpy(a2)
np.add(a2, 1, out=a2)
print ("--------------------------------------------")

a = torch.ones(2, 2)
a[0][0]=3
#print (a)
#print (a*a)
a = ((a * 3) / (a - 1))
#print(a.requires_grad)
a.requires_grad_(True)
#print(a.requires_grad)
b = (a * a).sum()
#print(b.grad_fn)
print ("-------------------------------------------")

x = torch.ones(2, 2, requires_grad=True)
y=x+2
#print(y.grad_fn)
z = y * y * 3
out = z.mean()
print(out)

out.backward()
#print(x.grad)

print (x.grad)
print ("--------------------------------------------")


x = torch.randn(3, requires_grad=True)
print(x)

'''

import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision
import torchvision.transforms as transforms


class Net(nn.Module):

    def __init__(self):
        super(Net, self).__init__()
        # 1 input image channel, 6 output channels, 3x3 square convolution
        # kernel


        self.conv1 = nn.Conv2d(1, 6, 3)


        self.conv2 = nn.Conv2d(6, 16, 3)
        # an affine operation: y = Wx + b
        self.fc1 = nn.Linear(16 * 6 * 6, 120)  # 6*6 from image dimension
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):
        # Max pooling over a (2, 2) window
        print("-------------------------------------------1  ", x.size())  #torch.Size([1, 1, 32, 32])

        #x=F.relu(self.conv1(x))    #torch.Size([1, 6, 30, 30])

        x = F.max_pool2d(F.relu(self.conv1(x)), (2, 2))  #torch.Size([1, 6, 15, 15])

        print("-------------------------------------------2", x.size())

        # If the size is a square you can only specify a single number
        
        #x=F.relu(self.conv2(x))                         #torch.Size([1, 16, 13, 13])

        x = F.max_pool2d(F.relu(self.conv2(x)), 2)      #torch.Size([1, 16, 6, 6])

        print("------------------------------------------3", x.size())

        x = x.view(-1, self.num_flat_features(x))       #torch.Size([1, 576])
        
        print("-----------------------------------------4", x.size())

        x = F.relu(self.fc1(x))                          #torch.Size([1, 120])
        
        print("-----------------------------------------5", x.size())

        x = F.relu(self.fc2(x))                         #torch.Size([1, 84])
        
        print("-----------------------------------------6", x.size())

        x = self.fc3(x)                                  #torch.Size([1, 10])

        print("-----------------------------------------7", x.size())
        return x

    def num_flat_features(self, x):
        size = x.size()[1:]  # all dimensions except the batch dimension
        num_features = 1
        for s in size:
            num_features *= s
        return num_features

'''
net = Net()
#print(net)

input = torch.randn(1,1 ,32, 32)

print(input.size())


output = net(input)
print(output)

#net.zero_grad()
#out.backward(torch.randn(1, 10))


target = torch.randn(10)  # a dummy target, for example
target = target.view(1, -1)  # make it the same shape as output
criterion = nn.MSELoss()

loss = criterion(output, target)
print("losss->  ",loss)

net.zero_grad()     # zeroes the gradient buffers of all parameters

print('conv1.bias.grad before backward')
print(net.conv1.bias.grad)

loss.backward()

print('conv1.bias.grad after backward')
print(net.conv1.bias.grad)'''


x = torch.randn(3, 80,80)
y = x.numpy()


z= np.transpose(y , (1,2,0))


x= torch.from_numpy(z)



for i in range(0,2000):
	f=open("val_images.txt","a+")
	f.write("%s\r\n"  %( "./ceng483-s19-hw3-dataset/val/images/"+str(i)+".jpg"))









'''

# Feel free to change / extend / adapt this source code as needed to complete the homework, 
#based on its requirements.
# This code is given as a starting point.
#
# REFEFERENCES
# The code is partly adapted from pytorch tutorials, including https://pytorch.org/tutorials/beginner/blitz/cifar10_tutorial.html

# ---- hyper-parameters ----
# You should tune these hyper-parameters using:
# (i) your reasoning and observations, 
# (ii) by tuning it on the validation set, using the techniques discussed in class.
# You definitely can add more hyper-parameters here.

batch_size = 16
max_num_epoch = 50
hps = {'lr':0.1}
#epoch_loss_difference=0.02

# ---- options ----
DEVICE_ID = 'cpu' # set to 'cpu' for cpu, 'cuda' / 'cuda:0' or similar for gpu.
LOG_DIR = 'checkpoints'
VISUALIZE = False # set True to visualize input, prediction and the output from the last batch
LOAD_CHKPT = False

# --- imports ---
import torch
import os
import matplotlib.pyplot as plt
import numpy as np
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import torchvision.transforms as transforms
import hw3utils
torch.multiprocessing.set_start_method('spawn', force=True)
# ---- utility functions -----
def get_loaders(batch_size,device):
    data_root = 'ceng483-s19-hw3-dataset' 
    train_set = hw3utils.HW3ImageFolder(root=os.path.join(data_root,'train'),device=device)
    train_loader = torch.utils.data.DataLoader(train_set, batch_size=batch_size, shuffle=True, num_workers=0)
    val_set = hw3utils.HW3ImageFolder(root=os.path.join(data_root,'val'),device=device)
    val_loader = torch.utils.data.DataLoader(val_set, batch_size=batch_size, shuffle=False, num_workers=0)
    # Note: you may later add test_loader to here.
    return train_loader, val_loader

# ---- ConvNet -----
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        
        #self.conv1 = nn.Conv2d(1, 8, 5, stride=1, padding=2)
        #self.conv2 = nn.Conv2d(8, 3, 5, stride=1, padding=2)
       

        self.conv1 = nn.Conv2d(1, 8, 3, stride=1, padding=1)
        self.conv1_bn = nn.BatchNorm2d(8)
            
        self.conv2 = nn.Conv2d(8, 3, 3, stride=1, padding=1)
        self.conv2_bn = nn.BatchNorm2d(3)
        
        #self.conv3 = nn.Conv2d(8, 8, 5,stride=1, padding=2)
        #self.conv4 = nn.Conv2d(8, 3, 5,stride=1, padding=2)

    def forward(self, grayscale_image):
            
        #x = F.relu(self.conv1(grayscale_image))

        #x = F.relu( self.conv1(grayscale_image) )
        
        #x=self.conv1(grayscale_image)
        #x = F.relu(self.conv2(x))
        #x = F.relu(self.conv3(x))
        
        #x = self.conv2(x)
        
        x = F.relu(self.conv1_bn( self.conv1(grayscale_image) ))
        x = self.conv2_bn(self.conv2(x) )
        return x


'''
#BATCH NORMALIZATION 
 def __init__(self):
    self.conv1 = nn.Conv2d(1, 8, 5, stride=1, padding=2)
    self.conv1_bn = nn.BatchNorm2d(8)
            
    self.conv2 = nn.Conv2d(8, 3, 5, stride=1, padding=2)
    self.conv2_bn = nn.BatchNorm2d(3)
****
def forward(self, grayscale_image):
     x = F.relu(self.conv1_bn( self.conv1(grayscale_image) ))
     x = self.conv2_bn(self.conv2(x) )

'''


# ---- training code -----

def should_stop(loss1,loss2,loss3):
    if(loss1< loss2 < loss3):
        return 1
    else:
        return 0

device = torch.device(DEVICE_ID)
print('device: ' + str(device))
net = Net().to(device=device)
criterion = nn.MSELoss()
optimizer = optim.SGD(net.parameters(), lr=hps['lr'])
train_loader, val_loader = get_loaders(batch_size,device)

#print("?????????",len(val_loader),type(val_loader),type(train_loader))


if LOAD_CHKPT:
    print('loading the model from the checkpoint')
    model.load_state_dict(os.path.join(LOG_DIR,'checkpoint.pt'))

print('training begins')
loss1=0
loss2=0
loss3=0
estimations=[]
for epoch in range(max_num_epoch):  
    running_loss = 0.0 # training loss of the network


    for iteri, data in enumerate(train_loader, 0):
        inputs, targets = data # inputs: low-resolution images, targets: high-resolution images.
        
        
        optimizer.zero_grad() # zero the parameter gradients

        # do forward, backward, SGD step
        preds = net(inputs)

        loss = criterion(preds, targets)
        loss.backward()
        optimizer.step()

        # print loss
        running_loss += loss.item()
        
       

        print_n = 100 # feel free to change this constant
        if iteri % print_n == (print_n-1):    # print every print_n mini-batches
            print('[%d, %5d] network-loss: %.3f' %
                  (epoch + 1, iteri + 1, running_loss / 100))

            
            running_loss = 0.0
            # note: you most probably want to track the progress on the validation set as well 
            #(needs to be implemented)

        if (iteri==0) and VISUALIZE: 
            hw3utils.visualize_batch(inputs,preds,targets)
    
    net.eval()
    if( epoch % 5 == 0  ):
        estimations=[]
        vl=0.0
        for i,data2 in enumerate(val_loader,0):
            
            val_inputs, val_targets =  data2
           
            val_preds = net(val_inputs)
            for i in range(0,16):
                x = val_preds[i]
                
                y = x.detach().numpy()

                z= np.transpose(y , (1,2,0))
                z= (z+1) * 127.5
                
                estimations.append(z)


            val_los = criterion(val_preds, val_targets)
            vl+=val_los.item()
            
        print("---------------_>",vl/100)
        if(loss1==0):
            loss1=vl
        elif(loss2==0):
            loss2=vl
        else:
            loss1=loss2 #her bir val loss kontrolunde loss'lar bir kayiyor
            loss2=loss3
            loss3=vl
    net.train()
    if(should_stop(loss1,loss2,loss3)==1):
        break

    

    
    
  

    print('Saving the model, end of epoch %d' % (epoch+1))
    if not os.path.exists(LOG_DIR):
        os.makedirs(LOG_DIR)
    torch.save(net.state_dict(), os.path.join(LOG_DIR,'checkpoint.pt'))
    hw3utils.visualize_batch(inputs,preds,targets,os.path.join(LOG_DIR,'example.png'))

print('Finished Training')


estimations = np.asarray(estimations)
print(estimations.shape)

print(len(estimations[0][0][0]))
print(estimations[0][0][0])

np.save('estimations_validation',estimations)






'''