#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/**
   * Attack damage 0
   * Heal power 50
   * Max HP 150
   * Goal Priorities -> {HEAL,TO_ALLY,CHEST} in decreasing order
   * Class abbreviation -> "pr" or "PR"
   * Can move to all adjacent squares, including diagonals.
   * Can heal all adjacent squares, including diagonals.
   *
   */
//virtual ~Player() = default;
Priest::Priest(uint id,int x, int y, Team team):Player(id,x,y,team){
	this->HP=150;
}

int Priest::getAttackDamage()const{
	return 0;
}
int Priest::getHealPower()const{
	return 50;
}
int Priest::getMaxHP()const{
	return 150;
}

std::vector<Goal> Priest::getGoalPriorityList(){
	return {HEAL,TO_ALLY,CHEST}; }


const std::string Priest::getClassAbbreviation() const{
	if(this->getTeam()==BARBARIANS) return "PR";
	else return "pr";
	}
std::vector<Coordinate> Priest::getAttackableCoordinates(){ 
	return {};

	}
std::vector<Coordinate> Priest::getMoveableCoordinates(){ //?

	Coordinate c1 = Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 = Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 = Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 =  Coordinate(this->getCoord().x ,this->getCoord().y-1);

	Coordinate c5 = Coordinate(this->getCoord().x+1 ,this->getCoord().y+1);
	Coordinate c6 = Coordinate(this->getCoord().x+1 ,this->getCoord().y-1);
	Coordinate c7 = Coordinate(this->getCoord().x-1 ,this->getCoord().y+1);
	Coordinate c8 = Coordinate(this->getCoord().x-1 ,this->getCoord().y-1);

	
	

	return {c1,c2,c3,c4,c5,c6,c7,c8};
}
std::vector<Coordinate> Priest::getHealableCoordinates(){  //?
	
	Coordinate c1 = Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 = Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 = Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 = Coordinate(this->getCoord().x ,this->getCoord().y-1);

	Coordinate c5 = Coordinate(this->getCoord().x+1 ,this->getCoord().y+1);
	Coordinate c6 = Coordinate(this->getCoord().x+1 ,this->getCoord().y-1);
	Coordinate c7 = Coordinate(this->getCoord().x-1 ,this->getCoord().y+1);
	Coordinate c8 = Coordinate(this->getCoord().x-1 ,this->getCoord().y-1);

	
	

	return {c1,c2,c3,c4,c5,c6,c7,c8};
}