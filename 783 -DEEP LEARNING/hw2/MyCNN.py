import torch.nn as nn

class Net(nn.Module):
  #This defines the structure of the NN.
    def __init__(self):
        super(Net, self).__init__()
        self.conv1 = nn.Conv2d(1, 10, kernel_size=5)
        self.conv1_bn = nn.BatchNorm2d(10)
        
        self.conv2 = nn.Conv2d(10, 20, kernel_size=5)
        self.conv2_bn = nn.BatchNorm2d(20)
        #self.conv2_drop = nn.Dropout2d()  #Dropout
        
        self.fc11 = nn.Linear(180, 64)
        self.fc12 = nn.Linear(320, 64)
        self.fc13 = nn.Linear(500, 64)
        self.fc2 = nn.Linear(64, 10)
        self.pool = nn.MaxPool2d(2)
        self.relu = nn.ReLU()
        

    def forward(self, x):
        #x = self.pool(self.relu(self.conv1(x)))
        x = self.pool(self.relu(self.conv1_bn( self.conv1(x) )) )
        #x = self.pool(self.relu(self.conv2(x)))
        x = self.pool(self.relu(self.conv2_bn( self.conv2(x) )) )
        
        
        
        if((x.shape[0]*x.shape[1]*x.shape[2]*x.shape[3]) == 180):
          
          x = x.view(-1, 180)
          x = self.relu(self.fc11(x))
          #x = F.dropout(x, training=self.training)
          x = self.fc2(x)
        
        elif((x.shape[0]*x.shape[1]*x.shape[2]*x.shape[3]) == 320):
          
          x = x.view(-1, 320)
          x = self.relu(self.fc12(x))
          #x = F.dropout(x, training=self.training)
          x = self.fc2(x)
          
        elif((x.shape[0]*x.shape[1]*x.shape[2]*x.shape[3]) == 500):
          
          x = x.view(-1, 500)
          x = self.relu(self.fc13(x))
          #x = F.dropout(x, training=self.training)
          x = self.fc2(x)
          
        
        
        return x