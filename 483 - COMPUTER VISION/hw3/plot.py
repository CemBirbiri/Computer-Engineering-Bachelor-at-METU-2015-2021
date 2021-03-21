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

from utils import read_image
import sys

import matplotlib.pyplot as plt
import pickle
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
    val_set = hw3utils.HW3ImageFolder(root=os.path.join(data_root,'test'),device=device)
    val_loader = torch.utils.data.DataLoader(val_set, batch_size=1, shuffle=False, num_workers=0)
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
        x = torch.tanh(self.conv2_bn(self.conv2(x) ))
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
total_training_loss=[]

total_validation_loss=[]

margin12error=[]

total_train_loss=0

total_val_loss=0
for epoch in range(max_num_epoch):  
    running_loss = 0.0 # training loss of the network

    total_train_loss=0
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
        
        total_train_loss += loss.item()

        print_n = 100 # feel free to change this constant
        if iteri % print_n == (print_n-1):    # print every print_n mini-batches
            print('[%d, %5d] network-loss: %.3f' %
                  (epoch + 1, iteri + 1, running_loss / 100))

            
            running_loss = 0.0
            # note: you most probably want to track the progress on the validation set as well 
            #(needs to be implemented)

        if (iteri==0) and VISUALIZE: 
            hw3utils.visualize_batch(inputs,preds,targets)
    
    total_training_loss.append(total_train_loss)
    
    net.eval()
    marginloss=0.0

    if( epoch % 5 == 0  ):
        estimations=[]
        total_val_loss=0
        vl=0.0
        for i,data2 in enumerate(val_loader,0):
            
            val_inputs, val_targets =  data2           
            val_preds = net(val_inputs)
            val_los = criterion(val_preds, val_targets)
            vl+=val_los.item()


            cur=(val_targets+1)*127.5
            est=(val_preds+1)*127.5
            cur = cur.cpu().detach().numpy().reshape(-1).astype(np.int64)
            est = est.cpu().detach().numpy().reshape(-1).astype(np.int64)
            acc = (np.abs(cur - est) < 12).sum() / cur.shape[0]
            
            err=(np.abs(cur-est) >=12).sum()/cur.shape[0]
            if acc > 0.70:
                print(i)
                print(cur)
                print(est)
                print(acc)
                hw3utils.visualize_batch(val_inputs,val_preds,val_targets)
                
            marginloss+=err
            
            total_val_loss +=val_los.item()

       
    vl/= (i+1)
    marginloss /=(i+1)
    margin12error.append(marginloss)


    
    total_validation_loss.append(total_val_loss)

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


#np.save('estimations_validation',estimations)



with open ('total_training_loss.pickle','wb') as f:
    pickle.dump(total_training_loss,f, protocol=pickle.HIGHEST_PROTOCOL)
with open ('margin_eror.pickle','wb') as f:
    pickle.dump(margin12error,f, protocol=pickle.HIGHEST_PROTOCOL)




def run():


    with open('total_training_loss.pickle', 'rb') as f:
        trainLoss = pickle.load(f)

    fig = plt.figure()
    plt.plot(range(0, len(trainLoss)), trainLoss)
    plt.title("Training Loss vs. Epochs")
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.legend('Training Loss')



    plt.show()

    with open('margin_eror.pickle', 'rb') as f:
        margin_error = pickle.load(f)

    plt.plot(range(0, len(margin_error)*5, 5), margin_error)
    plt.title('Margin Error vs Epochs')
    plt.xlabel('Epoch')
    plt.ylabel('Margin Error')

    plt.show()

if __name__ == "__main__":
    run()