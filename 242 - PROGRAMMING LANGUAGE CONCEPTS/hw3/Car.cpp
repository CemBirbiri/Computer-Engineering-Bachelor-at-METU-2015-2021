#include "Car.h"


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
/*
private:
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/


    /**
     * Constructor.
     *
     * @Important: set the performance variable of the car by using Utilizer::generatePerformance()
     * 
     * @param std::string The Car's driver name.
     */
Car::Car(std::string driver_name){
	
	this->performance = Utilizer::generatePerformance();
	this->driver_name=driver_name;
	head==NULL;
	next==NULL;
}
    
    /**
     * Copy Constructor.
     *
     * @param rhs The car to be copied.
     */
Car::Car(const Car& rhs){
	this->driver_name=rhs.driver_name;
	this->performance=rhs.performance;
	
	this->next=rhs.next;
	if(rhs.head==NULL){
		this->head=NULL;
	}
	else{
		this->head= new Laptime(rhs.head->get_laptime());
		Laptime * current=this->head;
		Laptime * rhsc= rhs.head;
		
		while(rhsc->get_next()!=NULL){
			Laptime *newnode= new Laptime(rhsc->get_next()->get_laptime());
			
			current->set_next(newnode);
			current=current->get_next();
			rhsc=rhsc->get_next();
			
		}


	}
}
/*
private:
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
    
Car::~Car(){

	next=NULL;
	Laptime * current= this->head;
	Laptime * garbage=NULL;
	
	
	if(current) {

		while(garbage!=NULL){
		
		garbage= current;

		garbage= garbage->get_next();
		

		
		if(current!=NULL) {
			current->set_next(NULL);
			delete current;
		
		}
		
	}
}

	
}
/*delete []next;
	
	Laptime * current= this->head;
	
	while(current!=NULL){
		Laptime * garbage = current;
		current= current->get_next();
		delete garbage;
		garbage=NULL;
	}
	head=NULL;
	current=NULL;
	*/
    /**
     * Gets the drivers name
     * 
     * 
     * @returns: drivers name
     */

std::string Car::getDriverName() const{

	return this->driver_name;
}

    /**
     * 
     * Gets the performance
     * 
     * @returns the performance
     * 
     */
double Car::getPerformance() const{
	return this->performance;
}

    /**
     * Sets the next chain for this Car.
     * Adds a new car behind existing car 
     * You should insert the given  Car to the object which the method is called upon
     * Important: Car does NOT "own" next.
     *
     * @param next The next Car.
     */
void Car::addCar(Car *next){
	this->next=next;
}


    /**
     * Less than overload.
     *
     * True if total laptime of this Car is less than the rhs Car.
     *
     * Important: 
     *
     * @param rhs The Car to compare.
     * @return True if this car's total laptime is smaller, false otherwise.
     */
bool Car::operator<(const Car& rhs) const{
	Laptime *tmp1 = this->head;
	
	Laptime *tmp2 = rhs.head;
	int total1=0;
	while(tmp1){
		total1 = total1 + tmp1->get_laptime();
		tmp1 = tmp1->get_next();
	}
	
	int total2=0;
	while(tmp2){
		total2 = total2+tmp2->get_laptime();
		tmp2=tmp2->get_next();
	}
	if(total1 < total2 ) return true;
	else return false;
	
}

    /**
     * Greater than overload.
     *
     * True if total laptime of this Car is greater than the rhs Car.
     *
     * Important: 
     *
     * @param rhs The Car to compare.
     * @return True if this car's total laptime is greater, false otherwise.
     */
bool Car::operator>(const Car& rhs) const{
	Laptime *tmp1 = this->head;
	int total1=0;
	while(tmp1){
		total1=total1 + tmp1->get_laptime();
		tmp1=tmp1->get_next();
	}
	Laptime *tmp2 = rhs.head;
	int total2=0;
	while(tmp2){
		total2=total2+tmp2->get_laptime();
		tmp2=tmp2->get_next();
	}
	if(total1 > total2 ) return true;
	else return false;
}
    

    /**
     * Indexing.
     *
     * Find the laptime of the given lap.
     * You will use 0 based indexing.
     * For example, after 20 lap your car should have 20 laptimes. To get 15th laptime you will give 14 as the input parameter.
     * 
     * @return The Laptime with the given lap. Laptime with zero time if given lap does not exists.
     */
Laptime Car::operator[](const int lap) const{
	int i=0;
	Laptime *tmp = this->head;
	while(i!=lap){
		tmp=tmp->get_next();
		i=i+1;
	}
	return tmp->get_laptime();
}

    /**
     * Car completes one lap and records its laptime
     * 
     * @Important: Based on your cars performance calculate some variance to add average_laptime
     * Use  Utilizer::generateLaptimeVariance(performance) then add it to average_laptime
     * 
     * @param: Car takes average_laptime of the race 
     * 
     */
void Car::Lap(const Laptime& average_laptime){
	int laptime_variance = Utilizer::generateLaptimeVariance(this->performance);
	laptime_variance+=average_laptime.get_laptime();
	
	Laptime *newnode= new Laptime(laptime_variance );
	newnode->set_next(NULL);
	//average_laptime.set_next(newnode);
	//int a =average_laptime.get_laptime() + laptime_variance;
	//average_laptime.SetLaptime(0);
}

    /**
     * Stream overload.
     *
     * What to stream:
     * First Three letters of the drivers surname(Capitalized)--Latest Laptime--Fastest Laptime--Total Laptime
     * Example:
     * For Lewis Hamilton
     * HAM--1:19.235--1:18.832--90:03.312
     *
     * @Important: for lap numbers smaller in size you have to put zeros as much as neccasary
     * @Important: you can use Laptime ostream when neccessary
     * 
     * @param os Stream to be used.
     * @param car Car to be streamed.
     * @return The current Stream.
     */

std::ostream& operator<<(std::ostream& os, const Car& car){
	int fastest=0;
	
	string s = car.driver_name;
	string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
    	token = s.substr(0, pos);
    	
    	s.erase(0, pos + delimiter.length());
	}
	string surname=s;
	
	string h=surname.substr(0, 3);

 for(auto& x: h)
        x = toupper(x);
    std::cout << h<<endl;

    Laptime *tmp1 = car.get_head();
   
	int total=0;
	int latest=0;
	
	if(tmp1){
	fastest=tmp1->get_laptime();}
	

	
	while(tmp1){
		total=total+tmp1->get_laptime();
		if(tmp1->get_laptime() < fastest) fastest=tmp1->get_laptime();
		
		latest=tmp1->get_laptime();
		tmp1=tmp1->get_next();
	}
	
	
	os<<h<<"--"<<latest<<"--"<<fastest<<"--"<<total<<endl;
	
    return os;

}

Laptime *Car::get_head() const{
	return this->head;
}
void Car::set_head(Laptime &a) {
	 this->head=&a;
}

void Car::set_head(Laptime *a) {
	 this->head=a;
}

Car * Car::get_next(){
	return this->next;
}

void Car::set_next(Car * next) {
	this->next=next;

}
void Car::set_next(Car car) {
	this->next=&car;

}

/*
private:
    std::string driver_name;
    double performance;
    Laptime *head;
    Car *next;
*/
/*int main(){

	
	Car alonso("Fernando Alonso");
	Laptime a(13);
	alonso.set_head(a);
	
	//alonso.get_head()->set_next(b);

	

	
	cout<<"bitis"<<endl;
	return 0;
}

*/