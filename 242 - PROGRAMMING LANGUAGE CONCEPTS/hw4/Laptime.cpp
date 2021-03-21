#include "Laptime.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
/*
private:
    int laptime;

    Laptime *next;
*/

/**
     * Constructor.
     *
     * @param int value in laptime.
     */
Laptime::Laptime(int laptime){
	this->laptime=laptime;
	next=NULL;

}

/**
     * Copy Constructor.
     *
     * @param rhs The laptime to be copied.
     */
Laptime::Laptime(const Laptime& rhs){
	this->laptime=rhs.laptime;
	
	this->next=rhs.next;
	
}

Laptime::~Laptime(){
	delete next;
}
 /**
     * Sets the next chain for this Laptime.
     * You should insert the given Laptime to the object which the method is called upon
     *
     * @param next The next Laptime.
     */
void Laptime::addLaptime(Laptime *next){
    Laptime * tmp=this->next->next;
	this->next=next;
    next->next=tmp;
}


/**
     * Less than overload.
     *
     * True if this Laptime less than the rhs Laptime.
     *
     * @param rhs The Laptime to compare.
     * @return True if this laptime is smaller, false otherwise.
     */
bool Laptime::operator<(const Laptime& rhs) const{

	if(rhs.laptime > this->laptime) return true;
	else return false;
}
/**
     * Greater than overload.
     *
     * True if this Laptime greater than the rhs Laptime.
     *
     * @param rhs The Laptime to compare.
     * @return True if this laptime is bigger, false otherwise.
     */
bool Laptime::operator>(const Laptime& rhs) const{
	if(rhs.laptime < this->laptime) return true;
	else return false;
}
/**
     *  Plus overload
     * 
     *  Add two Laptime and return the lhs Laptime
     * 
     *  @param Laptime to add
     *  @returns Summation of the two laptime
     */
Laptime& Laptime::operator+(const Laptime& rhs){
	Laptime result(rhs.laptime);
	//result.SetLaptime(this->laptime);
	int a=0;
	
	a+=result.get_laptime();
	a+=this->laptime;
	result.SetLaptime(a);
	this->SetLaptime(result.get_laptime());

	this->next=rhs.next; //bu gerekli olmayabilir
	
	return *this;
	
	
}
 /**
     * Stream overload.
     *
     * What to stream:
     * minute:second.miliseconds
     *
     * Example:
     * 1:19.125
     *
     * @important Your laptime variable is representation in terms of miliseconds 
     * and you have to turn it to desired outcome type
     * Print the Laptime of the object which the method is called upon.
     * @param os Stream to be used.
     * @param laptime Laptime to be streamed.
     * @return The current Stream.
     */
 std::ostream& operator<<(std::ostream& os, const Laptime& laptime){


 		int second= (laptime.laptime *1.0)/1000.0;
 		int kalan= (laptime.laptime % 1000);
 		
 		int temp=second;
 		int i=0;
 		for(;1;i++){
 			if(temp-60 < 0 ) break;
 			else {
 				temp=temp-60;

 			}
 			

 		}
 		if(temp<10) os<<i<<":"<<0<<temp<<"."<<kalan<<endl;
    	else os<<i<<":"<<temp<<"."<<kalan<<endl;
    	return os;
    }
/*
private:
    int laptime;

    Laptime *next;
*/
int Laptime::get_laptime(){
	return this->laptime;
}
int Laptime::get_laptime() const {
    return this->laptime;
}
void Laptime::SetLaptime(int laptime){
	this->laptime = laptime;
}
Laptime *Laptime::get_next(){
	return this->next;
}

void Laptime::set_next(Laptime * next) {
	this->next=next;
}
Laptime::Laptime(){
	next=NULL;
}


