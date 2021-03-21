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
max_num_epoch = 100
hps = {'lr':0.1}
#epoch_loss_difference=0.02

# ---- options ----
DEVICE_ID = 'cpu' # set to 'cpu' for cpu, 'cuda' / 'cuda:0' or similar for gpu.
LOG_DIR = 'checkpoints'
VISUALIZE = False # set True to visualize input, prediction and the output from the last batch
LOAD_CHKPT = False


# --- imports ---
import torch
import torchvision.models as models
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

def test_loader(batch_size,device):
    data_root = 'ceng483-s19-hw3-dataset' 
    test_set = hw3utils.HW3ImageFolder(root=os.path.join(data_root,'test'),device=device)
    test_loader = torch.utils.data.DataLoader(test_set, batch_size=batch_size, shuffle=False, num_workers=0)
    return test_loader


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
        #x = torch.tanh(self.conv2_bn(self.conv2(x) ))     # this is for tanh tries
        
        x = F.relu(self.conv1_bn( self.conv1(grayscale_image) ))
        x = self.conv2_bn(self.conv2(x) )
        return x



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

test_loader=test_loader(batch_size,device)


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
np.save('estimations',estimations)


estimations_test=[]

#checkpoint = torch.load('./checkpoints/checkpoint.pt')
#net.load_state_dict(checkpoint['net_state_dict'])
#net.load_state_dict(os.path.join(LOG_DIR,'checkpoint.pt'))
#net.load_state_dict(torch.load(os.path.join(LOG_DIR,'checkpoint.pt')))

for i,data3 in enumerate(test_loader,0):
            
            test_inputs, test_targets =  data3
           
            test_preds = net(test_inputs)
            for i in range(0,16):
                x = test_preds[i]
                
                y = x.detach().numpy()

                z= np.transpose(y , (1,2,0))
                z= (z+1) * 127.5
                
                estimations_test.append(z)


        
estimations_test = np.asarray(estimations_test)
np.save('estimations_test',estimations_test)