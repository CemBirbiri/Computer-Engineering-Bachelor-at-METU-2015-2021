#include "Race.h"



/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
/*
private:
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/

    /**
     * Constructor.
     *
     * @Important: Generate average_laptime by using Utilizer::generateAverageLaptime()
     * 
     * @param std::string The name of the Race.
     */
    Race::Race(std::string race_name){
    	this->race_name=race_name;
    	
        int new_avg_laptime= Utilizer::generateAverageLaptime();
    	
        //this->average_laptime.SetLaptime(new_avg_laptime) ;
    	
        head=NULL;



    }
    /**
     * Copy Constructor.
     * 
     * @Important just copy the names and performances of the cars
     * without any laptime.
     * Cars should be deep copied

     * 
     * @param rhs The race to be copied.
     */
    Race::Race(const Race& rhs){;
    	this->race_name=rhs.race_name;
    	this->average_laptime=rhs.average_laptime;
        
        if(rhs.head==NULL) this->head=NULL;
        else{
            Car * rhsc=rhs.head;
            Car * current = new Car(rhs.head->getDriverName());
            while(rhsc->get_next()){
                Car * newnode=new Car(rhsc->get_next()->getDriverName());
                current->set_next(newnode);
                current=newnode;
                rhsc=rhsc->get_next();
                newnode=NULL;
            }
        }

    	

    }
    /*
private:
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
    Race::~Race(){

    Car * current= this->head;
    
    while(current!=NULL){
        Car * garbage = current;
        current= current->get_next();
        delete garbage;
        garbage=NULL;
    }
head=NULL;



    }

std::string Race::getRaceName() const{
        return this->race_name;
    }
    /*
private: RACE
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
    /*
private: CAR
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
    /**
     * Add a new car to race. 
     * 
     * @Important: At the start of the race their ordering is not important
     * 
     * No parameter means that you will generate your own car in 
     * this function(with a random name)and add it to your Cars
     */

    void Race::addCartoRace(){

// double new_performance = Utilizer::generatePerformance();
// Car newCar = Car("blabla", new_performance);

    
    Car * newcar= new Car("JonSnow");
    Car * current=this->head;
    if(this->head==NULL){
        head=newcar;
    }
    else{
        cout<<"bura1"<<endl;
        while(current){
            cout<<"bura2"<<endl;
            if(current->get_next()==NULL){
                cout<<"bura3"<<endl;
                current->set_next(newcar);
                break;
            }
            else{ current=current->get_next();
                    cout<<"bura4"<<endl;
            }
        }
    }
}

/*
private:
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
    /**
     * Add a new car to race. 
     * 
     * @Important: At the start of the race their ordering is not important
     * 
     * @param: car Add given Car to others
     */
    void Race::addCartoRace(Car& car){
        

        Car *newcar=new Car(car.getDriverName());
        
        //newcar=&car;
        Car * current=this->head;
       

   if(current==NULL){
        head=newcar;
    }
    else{
       cout<<"seqqqqq"<<endl;
        while(current->get_next()){
            cout<<"sekkk"<<endl;
            
           current=current->get_next();
           
           cout<<"sekkk222"<<endl;
           cout<<"-->"<<*current<<endl;

        }
        cout<<"srrrr"<<endl;
        current->set_next(newcar);
    }

    }

    /**
     * Information About how much car is in the race
     * 
     * @returns number of cars
     * 
     */
    int Race::getNumberOfCarsinRace(){

        Car * current = this->head;
        int i=0;

        while(current){
            cout<<"vardi"<<endl;
            i=i+1;
            current=current->get_next();
        }

        return i;
    }

    /**
     * Return state of everything to desired lap's state
     * 
     * Your Race will have many laps in the course of its life. In each lap, 
        your cars will have new Laptimes etc.
     * For example, if you have 20 Laps in your Race, but let's say you want to redo last 10 laps of it. 
        By using goBacktoLap,
     * you will take your Race back to 10th Lap. This will also make changes in your Cars.
        
        Your cars will have only the information of the first 10 laps. 
     
     * Lap numbers start from zero. If 5 is given as int lap, you will take Race back to 6th lap.
     * @Important: this will also apply to cars and leaderboard too
     * 
     * @param lap to return
     * 
     */
    void Race::goBacktoLap(int lap){

        Car * current=this->head;
        while(current){
            goBacktoLap_helper(current,lap);
            current=current->get_next();
        }

    }
/*private: CAR
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
void Race::goBacktoLap_helper(Car *car,int lap){
        int i=0;
        Laptime * current=car->get_head();
        while(i<lap){
            if(current->get_next()) current=current->get_next();
            i=i+1;

        }
        Laptime * son=current;

        current=current->get_next();
        son->set_next(NULL);
    while(current!=NULL){
        Laptime * garbage = current;
        current= current->get_next();
        delete garbage;
        garbage=NULL;
    }


    }
void Race::add_one_more_lap(Car *car){
    int laptime_variance = Utilizer::generateLaptimeVariance(242);
    Laptime * current=car->get_head();
    
    if(current!=NULL){ //head null degilse
        while(current->get_next()!=NULL) current=current->get_next();
        Laptime * newnode= new Laptime(laptime_variance);
        newnode->set_next(NULL);
        current->set_next(newnode);
    }
    
    else{ //head null ise
        Laptime * newnode= new Laptime(laptime_variance);
        
        car->set_head(newnode); //buralarda bi olaylar dondu,iki tane car->set_head fonksiyonu var
        newnode->set_next(NULL);
    }
}
int Race::give_car_number(Car *head){
    int i=0;
    Car * current=head;
    while(current){
        i=i+1;
        current=current->get_next();
    }
    return i;
}
Car * Race::find_min_prev(Car * old_head){
    Car * temp=old_head;
    Car * min=NULL;
    int minn=999999999;
    if(temp==find_min(temp)) return NULL;
    else{
    
    while(temp->get_next()){
        if(find_total_laptime(temp->get_next())< minn){
            minn=find_total_laptime(temp->get_next());
            min=temp->get_next();
            temp=temp->get_next();
        }
        else temp=temp->get_next();
    }
}
    return min;
}
    /**
     * Prefix addition overload
     * 
     * add one more lap to all cars
     * 
     * @Important: Update the order of the cars so that the fastest one stays at the front
     * 
     */
void Race::operator++(){
        Car * current= this->head;
        while(current){
            add_one_more_lap(current);
            current=current->get_next();
        }
        int len=give_car_number(head);
        current=head;
        Car * next=NULL;
        Car * prev=NULL;
        Car * min=NULL;
        Car * old_min=NULL;

        head=find_min(current);
        

        int i=0;

        while(i!= len){
            
            if(find_min(current)==current){
                current=current->get_next();
            }
            else {
            min=find_min(current);
            prev=find_min_prev(current);
            next=min->get_next();
            prev->set_next(next);
            min->set_next(current);
            
            //current=prev;
            
            if(old_min) old_min->set_next(min);
            old_min=min;
            

                    }

            i=i+1;

        }
        next=NULL;
        prev=NULL;
        min=NULL;
        old_min=NULL;
        current=NULL;

    }
int Race::find_total_laptime(Car * temp){
    int total=0;
    Laptime * current=temp->get_head();
    while(current){
        total=total+current->get_laptime();
        current=current->get_next();
    }
    return total;

}
Car * Race::find_min(Car * old_head){
    Car * temp=old_head;
    Car * min=NULL;
    int minn=999999999;
    while(temp){
        if(find_total_laptime(temp)< minn){
            minn=find_total_laptime(temp);
            min=temp;
            temp=temp->get_next();
        }
        else temp=temp->get_next();
    }
    return min;
}
/*
private:
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
/*private: CAR
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/

void Race::remove_one_more_lap(Car *car){
    
    Laptime * current=car->get_head();

    if(current==NULL){;}
    else if(current->get_next()==NULL) {

        delete []current;
        current=NULL;
        head=NULL;}

    else if(current->get_next()){ 
        
        while(current->get_next()->get_next()) current=current->get_next();
        
        delete []current->get_next();
        current->set_next(NULL);
    }
    
    else{ 
        ;
    }
}
    /**
     *  Prefix decrement overload
     * 
     * remove one lap from all cars
     * 
     * @Important: Update the order of the cars so that the fastest one stays at the front
     * 
     */
    void Race::operator--(){

         Car * current= this->head;
        while(current){
            remove_one_more_lap(current);
            current=current->get_next();
        }
        int len=give_car_number(head);
        current=head;
        Car * next=NULL;
        Car * prev=NULL;
        Car * min=NULL;
        Car * old_min=NULL;

        head=find_min(current);
        

        int i=0;

        while(i!= len){
            
            if(find_min(current)==current){
                current=current->get_next();
            }
            else {
            min=find_min(current);
            prev=find_min_prev(current);
            next=min->get_next();
            prev->set_next(next);
            min->set_next(current);
            
            //current=prev;
            
            if(old_min) old_min->set_next(min);
            old_min=min;
            

                    }

            i=i+1;

        }
        next=NULL;
        prev=NULL;
        min=NULL;
        old_min=NULL;
        current=NULL;
    }
/*
private: RACE
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
/*private: CAR
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
    /**
     * 
     * Indexing overload
     * 
     * This function will not be tested for the cases in which Car in given position does not exist.
     * 
     * @param: car_in_position Car in the given position
     * @returns the car in the desired position in the current lap
     */
    Car Race::operator[](const int car_in_position){
        int i=0;
        Car * current=head;
        while(i != car_in_position){
            current=current->get_next();
            i=i+1;

        }
        return *current;
    }

    /**
     * 
     * Indexing overload
     * 
     * This function will not be tested for the cases in which Car with given driver_name does not exist.
     * 
     * @param: driver_name driver's name of the desired car
     * @returns the car whose driver named as the given @param
     */
    Car Race::operator[](std::string driver_name){
         
        Car * current=head;
        while(current){
            if(current->getDriverName()==driver_name) return *current;
            current=current->get_next();

            

        }
        
    }
    /*
private: RACE
    std::string race_name;
    Laptime average_laptime;
    Car *head;

*/
/*private: CAR
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
    /**
     * Assignment
     * 
     * @param rhs The Race to assign into this race
     * @return The assigned Race
     */
    Race& Race::operator=(const Race& rhs){
        this->race_name=rhs.race_name;
        this->average_laptime=rhs.average_laptime;
        if(rhs.head==NULL) this->head=NULL;
        else{
            temizle(this->head);
            this->head= new Car(rhs.head->getDriverName());
            Car* current=this->head;
            Car * rhsc=rhs.head;
            
            while(rhsc->get_next()!=NULL){
                Car * newcar= new Car(rhsc->get_next()->getDriverName());

                current->set_next(newcar);
                current=newcar;
                rhsc=rhsc->get_next();

            }
            rhsc=NULL;
            current=NULL;


        }

    }
    

void Race::temizle(Car * head){
    Car * current= this->head;
    
    while(current!=NULL){
        Car * garbage = current;
        current= current->get_next();
        delete garbage;
        garbage=NULL;
    }
    head=NULL;

}

    /**
     * Stream overload.
     *
     * What to stream:
     * Position--*Driver Name(leader of the race)--Latest Laptime--Fastest Laptime of the Driver--Sum of Laptimes
     (in display Laptime format)--Points--ExtraPoint(If applicable)
     
     * ...
     * Position--*Driver Name(last place of the race)--Latest Laptime--Fastest Laptime of the Driver--Sum of Laptimes
     (in display Laptime format)--Points--ExtraPoint(If applicable)
     
     *
     * Example:
     * 001--TUF--1:19.461--1:18.935--60:35.193--25
     * 002--UTA--1:19.335--1:18.335--60:37.321--18--1
     * 003--GRT--1:20.223--1:19.932--60:45.184--15
     * ...
     * 099--CEI--1:21.005--1:19.867--63:47.293
     * 100--ECH--1:23.213--1:21.331--64:00.123
     *
     * @Important: for driver numbers smaller in size you have to put zeros as much as neccasary to their beginning
     * Example: if there is 11 racers first position should be 01
     * @Important. you can use Laptime ostream when neccessary
     * @Important: You should order the racers according to their total laptime
     * @Important: There are two different point types for F1
     * First one is the Fastest Lap point which is 1 point and it is given the fastest car if it is in top 10
     * Other one is normal racing points and they are 25-18-15-12-10-8-6-4-2-1 in this order
     *
     * @param os Stream to be used.
     * @param car Car to be streamed.
     * @return The current Stream.
     */
    std::ostream& operator<<(std::ostream& os, const Race& race){;
    }

    // DO NOT MODIFY THE UPPER PART
    // ADD OWN PUBLIC METHODS/PROPERTIES BELOW