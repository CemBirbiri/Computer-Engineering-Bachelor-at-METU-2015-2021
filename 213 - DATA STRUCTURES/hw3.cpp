#include "hw3.h"
#define MAX_LOAD_FACTOR 0.65
#define EMPTY "EMPTY"
#define DELETED "DELETED"

AccessControl::AccessControl(int table1Size, int table2Size){
	
	//table.resize(table_size);
	table1= new std::pair<std::string, std::string>[table1Size];//registered users
	table2= new std::string[table2Size];//active users
	this->table1Size= table1Size;
	this->table2Size= table2Size;
	for(int i=0 ; i< table1Size ; i++){
		table1[i].first= EMPTY;
		table1[i].second=EMPTY;
	}
	for(int j=0; j< table2Size ; j++){
		table2[j]=EMPTY;
	}
	n=0;
	n1=0;
}
AccessControl::~AccessControl(){
	delete [] table1;
	delete [] table2;
}
int AccessControl::find1(std::string username, std::string pass){
    std::cout<<"finndayiz"<<std::endl;
	for(int i=0; i< table1Size ; i++){
		if(table1[i].first==username && table1[i].second==pass) {
		    std::cout<<"return 1 mı?"<<std::endl;
		    
		}

	}
	return 0;
}

void AccessControl::clear_expandead(){
	for(int i=0; i< expanded.size(); i++) {expanded[i]="";}

}
void AccessControl::expandead(){

	for(int i=0; i< expanded.size() ; i++){
		std::cout<<"expandead-<>"<<expanded[i]<<std::endl;
	}

}
int AccessControl::is_in(std::string username){
	for(int i=0 ; i< expanded.size() ; i++){
		if(username==expanded[i]) return 1;
	}
	return 0;
}
void AccessControl::print_table1(){

	for(int i=0; i< table1Size ; i++){
		std::cout<<"USERNAME -->"<<table1[i].first<<"  PASS-->"<<table1[i].second<<std::endl;
	}

}
void AccessControl::print_old_table( std::pair<std::string, std::string> * table_old, int old_size1 ){

	for(int i=0; i< old_size1 ; i++){
		std::cout<<"old table username -->"<<table_old[i].first<<"  old table pass->"<<table_old[i].second<<std::endl;
	}

}
void AccessControl::print_users(){
	for(int i=0; i< users.size() ; i++){
		std::cout<<"USERRRR"<<users[i]<<std::endl;
	}
}

void AccessControl::expand_table1()
{	
	int old_size1 = table1Size;

    table1Size = nextPrimeAfter(2*old_size1);

    std::pair<std::string, std::string> * table_old = table1;

    table1 = new std::pair<std::string,  std::string>[table1Size];
    
    for(int t = 0; t< table1Size; ++t){
        table1[t].first = EMPTY;
        table1[t].second = EMPTY;
    }
  
    
     n=0;
    int index1;
    int new_index=0;
    int index;

    for(int i=0 ; i< old_size1 ; i++ ){
    		
    		if(table_old[i].first!= EMPTY && table_old[i].first!= DELETED && is_in(table_old[i].first)==0){
    			
    			print_old_table(table_old ,old_size1 );
    			
    				
    				for(int j=0; j<old_size1  ; j++ ){
			    		index =hashFunction(table_old[i].first , old_size1, j);
			    		
			    		
			    		if(table_old[index].first == table_old[i].first){
			    				
			    			
			    			for(int d=0; d< table1Size ; d++){
			    				index1 =hashFunction(table_old[i].first , table1Size,d);
			    				if(table1[index1].first==EMPTY || table1[index1].first==DELETED){
			    					table1[index1].first= table_old[index].first;
			    					table1[index1].second=table_old[index].second;
			    					n++;
			    					break;
			    				}
			    				else{;}
			    			}

			    			
			    			

			    			
			    			
			    		}
			    		else{
			    		;}
			    		
			    		


			    		
			  			}
			  		expanded.push_back(table_old[i].first);
			  		//expandead();
    			
    		}
    		else{;} //old tableda top'tan bottoma dolasirken EMPTY/DELETED seye rastladı

    	//if( is_in(table_old[i].first)==0 )

    }


    clear_expandead();
  
}
bool AccessControl::isPrime( int n ) const
{
    if( n%2 == 0 ) return false;
    for( int i=3; i*i<=n; i+=2 )
        if( n%i == 0 )
            return false;
    return true;
}
/* Finds the first prime number just after
    integer n */
int AccessControl::nextPrimeAfter( int n ) const
{
    for( int i=n+1; ; i++ )
        if( isPrime(i) )
            return i;
}
double AccessControl::getLoadFactor1() const
{   
    return (double)n/table1Size;
}
double AccessControl::getLoadFactor2() const
{   
    return (double)n1/table2Size;
}


int  AccessControl::addUsers(std::string filePath){

	    int registered_users=0;

	    ifstream file;
        string line;
     	

      	file.open(filePath.c_str()); 

        while(file.good()){
            getline(file,line);
            if(file.good()==0) break;
           
        
           
           line +=' ';
           
            
            
            
            string delimiter = " ";
           size_t pos = 0;
            
            string token;
            int i=0;
            string a="",b="";
           
            while ((pos = line.find(delimiter)) !=  string::npos && i!=2) {
                       token = line.substr(0, pos);
                       
                       if(i==0) a=token;
                       if(i==1) b=token;
                        
                        i++;
                     
                        
                        line.erase(0, pos + delimiter.length());
                    }
                    
           if(addUser(a, b)){
           registered_users++;}

   
           
    
    
        }
        file.close();



	    return registered_users;
	}
//Remove a user from registered users and put all passwords of given user to oldPasswords variable.
//Return 1 if the user is registered else just return 0. You should delete all entries of that user. Put
//<“DELETED”, “DELETED”> as deleted entry. The vector, oldPasswords, should be sorted from
//oldest password to the newest password.
int  AccessControl::delUser(std::string username, std::vector<std::string>& oldPasswords){
		int flag=0;
		int index;
	    for(int i=0; i< table1Size ; i++){
	    	index =hashFunction(username, table1Size, i);  

	    	if(table1[index].first==username){
	    		flag=1;
	    		oldPasswords.push_back(table1[index].second);
	    		table1[index].first=DELETED;
	    		table1[index].second=DELETED;
	    		n--;
	    	}
	    	else{;}
	    }
	    if(flag==1) return 1;
	    else return 0;
	}
//Change the password of the given user if user is registered and oldpass is equal the current password.
//While changing the password keep the old entries <username, oldpassword> in the table, and add
//new entry <username, newpass> to the next empty cell that is found with the hash function. Last
//entry added is the current password of that user. If operation is successful return 1, else return 0
int  AccessControl::changePass(std::string username, std::string oldpass, std::string newpass){
	    int index,new_index;
	    int flag=0;
		for(int i=0; i< table1Size ;  i++){
			index =hashFunction(username, table1Size, i); 
			if(table1[index].first==username && table1[index].second==oldpass){
				

				
				for(int j=i+1; j< table1Size ; j++){
					new_index=hashFunction(username, table1Size, j); 

					
					
					if(table1[new_index].first==EMPTY || table1[new_index].first==DELETED){
						
						table1[new_index].first=username;
						table1[new_index].second=newpass;
						n++;
						
						flag=1;
						break;
				}
				}
			}
			else{//hashlemeye devam et, oldpassi bulana kadar 
				;}
		}
		
		if(getLoadFactor1() > MAX_LOAD_FACTOR){
								   	    
							        expand_table1();
							        clear_expandead();
							    }


	    if(flag==1) return 1;
	    else return 0;

	   
	    
	}


int AccessControl::addUser(std::string username, std::string pass){
	int index=0;
     	if(getLoadFactor1() > MAX_LOAD_FACTOR){
 			 expand_table1();
    }
	 for(int i=0; i< table1Size; i++){
      	index =hashFunction(username, table1Size, i);
	    	
	    	if(table1[index].first != username) {
        	    	
        	    	if(table1[index].first==EMPTY){  //empty-> insert

        	    		
        	    		index =hashFunction(username, table1Size, i);
        	    		table1[index].first = username;
        	            table1[index].second = pass;
        	            n++;
        	            
        	            users.push_back(username);

        	            	if(getLoadFactor1() > MAX_LOAD_FACTOR){
							   	    
						        expand_table1();
						        clear_expandead();
						    }
        	            return 1;}
        
        	        else if(table1[index].first==DELETED){   //deleted-> insert
        	    		table1[index].first = username;
        	            table1[index].second = pass;
        	            n++;

        	            users.push_back(username);

        	            	if(getLoadFactor1() > MAX_LOAD_FACTOR){
	   	    
								expand_table1();
								clear_expandead();}
        	            return 1;}
        	            
        	        else {;}
	    	}
	    	else { //table1[index].first == username
	    	        if(table1[index].second==pass) return 0;
	    	        else {return 0;} //table1[index].second != pass
    	}
	    }
return 0;


}
void AccessControl::expand_table2()
{	
	int old_size2 = table2Size;

    table2Size = nextPrimeAfter(2*old_size2);
    std::string* old_table =table2;

    
    table2 = new std::string[table2Size];
    
    
    for(int t = 0; t< table2Size; ++t){
        table2[t] = EMPTY;
        
    }
  
    
     n1=0;
    int index;

    for(int i=0 ; i< old_size2 ; i++ ){
    	if(old_table[i]!= EMPTY || old_table[i]!= DELETED){
    		for(int j=0; j< table2Size ; j++){

    			index = hashFunction(old_table[i], table2Size, j); 
    			if(table2[index]==EMPTY || table2[index]==DELETED){
    				table2[index]=old_table[i];
    				n1++;
    			}
    			else{;}
    		}
    	}
    	else{;}
    		
    		}
  
}
//If the user is registered and pass is the current password of 
//given user log the user in and return 1,
//if not do nothing and return 0.
int  AccessControl::login(std::string username, std::string pass){
		int index1,index2,flag=0;
		string username1, pass1;
	   
	   for(int i=0; i< table1Size ; i++){
	   		index1 =hashFunction(username, table1Size, i); 
	   		
	   		if(table1[index1].first==username){
	   			username1=table1[index1].first;
	   			pass1=table1[index1].second;
	   			
	   			}

	   		
	   		else {;} 
	 	}

	 	if(username1==username && pass1==pass){
	 		for(int j=0; j< table2Size ; j++){
	   				
	   				index2 =hashFunction(username, table2Size, j); 
	   				
	   				if(table2[index2]==EMPTY || table2[index2]==DELETED){
	   					
	   					table2[index2]=username;
	   					flag=1;
	   					n1++;
	   					if(getLoadFactor2() > MAX_LOAD_FACTOR){
							   	    
						        expand_table2();
						       
						    }
	   					break;
	   				}
	   				else{;}

	 	}
	 	
}

if(flag==1) return 1;
	 	else return 0;
}






//If the given user is logged in log that user out 
//and return 1, if not return 0. Put “DELETED” for
//logged out users.	
int  AccessControl::logout(std::string username){
	int index;
	int flag=0;
	    for(int i=0; i< table2Size ; i++){
	    	index=hashFunction(username, table2Size, i); 
	    	if(table2[index]==username){
	    		table2[index]=DELETED;
	    		n1--;
	    		flag=1;
	    	}
	    	else{;}
	    }
	  if(flag==1) return 1;
	  else return 0;
	    
	}

float  AccessControl::printActiveUsers(){
	    for(int i=0; i< table2Size ; i++){
	    	if(table2[i]==EMPTY) std::cout<<"EMPTY"<<std::endl;
	    	else if(table2[i]==DELETED) std::cout<<"DELETED"<<std::endl;
	    	else std::cout<<table2[i]<<std::endl;
	    }
	   
	    return n1;
	    
	}
float AccessControl::printPasswords(){
   
	for(int i=0; i< table1Size ;i++){
	    
	    
	 
		if(table1[i].first==EMPTY){ 
		    
		    
		    std::cout<<"EMPTY EMPTY"<<std::endl;}
		else if(table1[i].first==DELETED){ 
		    
		    std::cout<<"DELETED DELETED"<<std::endl;}
		
		else{ 
		    
		    std::cout<<table1[i].first<<" "<<table1[i].second<<std::endl;
		    
		}
	}
	
	
	return n;
}

int main()
{
  AccessControl ac(20, 3);
  // register users
  std::cout << "User Add: Sarah "   << ac.addUser("Sarah", "Sarahspass")        << std::endl;
  std::cout << "User Add: Morgan "  << ac.addUser("Morgan", "morganspass")      << std::endl;
  std::cout << "User Add: Ellie "   << ac.addUser("Ellie", "elspassword")       << std::endl;
  std::cout << "User Add: Vicky "   << ac.addUser("Vicky", "vickypass")         << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  //ac.printPasswords();
  std::cout << std::endl;

  // Cannot login or logout (No entry named Chuck)
  std::cout << "Login: Chuck "    << ac.login("Chuck", "chuckspass")      << std::endl;
  std::cout << "Logout: Chuck "   << ac.logout("Chuck")                   << std::endl;
  // Shouldn't login either (wrong pass)
  std::cout << "Login: Ellie "   << ac.login("Ellie", "wrongpass")       << std::endl;
  // Should login
  std::cout << "Login: Ellie "   << ac.login("Ellie", "elspassword")       << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  std::cout << "Logout: Ellie "   << ac.logout("Ellie")                   << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  std::cout << "Change Pass: Sarah "   << ac.changePass("Sarah", "Sarahspass", "Sarahsnewpass")  << std::endl;
  // Shouldn't login either (wrong pass)
  std::cout << "Login: Sarah "   << ac.login("Sarah", "Sarahspass")       << std::endl;
  // Should login
  std::cout << "Login: Sarah "   << ac.login("Sarah", "Sarahsnewpass")       << std::endl;
  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Active Users" << std::endl;
  ac.printActiveUsers();
  std::cout << std::endl;

  // Use Print Functions
  std::cout << "---------" << std::endl;
  std::cout << "Passwords" << std::endl;
  ac.printPasswords();
  std::cout << std::endl;

  return 0;
}















