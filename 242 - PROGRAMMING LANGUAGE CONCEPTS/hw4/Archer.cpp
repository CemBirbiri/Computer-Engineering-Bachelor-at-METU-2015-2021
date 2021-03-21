#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
 /**
   * Attack damage 50
   * Heal power 0
   * Max HP 200
   * Goal Priorities -> {ATTACK}
   * Class abbreviation -> "ar" or "AR"
   * Not able to move at all.
   * Can attack to a range of 2 squares directly up, down, left or right, from
   * its coordinate.
   *
   */



/*Archer::~Archer(){
	std::cout<<"bura?"<<std::endl;
	delete this; }*/
Archer::Archer(uint id,int x, int y, Team team):Player(id,x,y,team){
	this->HP=200;
}


int Archer::getAttackDamage()const{
	return 50;
}
int Archer::getHealPower() const{
	return 0;
}
int Archer::getMaxHP() const{
	return 200;
}

std::vector<Goal> Archer::getGoalPriorityList(){
	return {ATTACK}; }


const std::string Archer::getClassAbbreviation() const{
	if(this->getTeam()==BARBARIANS) return "AR";
	else return "ar";
	}
std::vector<Coordinate> Archer::getAttackableCoordinates(){ //?
	
	Coordinate c1 = Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 = Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 = Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 = Coordinate(this->getCoord().x ,this->getCoord().y-1);

	Coordinate c5 = Coordinate(this->getCoord().x+2 ,this->getCoord().y);
	Coordinate c6 = Coordinate(this->getCoord().x ,this->getCoord().y+2);
	Coordinate c7 = Coordinate(this->getCoord().x-2 ,this->getCoord().y);
	Coordinate c8 = Coordinate(this->getCoord().x ,this->getCoord().y-2);

	
	

	return {c1,c2,c3,c4,c5,c6,c7,c8};

	}
std::vector<Coordinate> Archer::getMoveableCoordinates(){

	return {};
}
std::vector<Coordinate> Archer::getHealableCoordinates(){  
	return {};
}