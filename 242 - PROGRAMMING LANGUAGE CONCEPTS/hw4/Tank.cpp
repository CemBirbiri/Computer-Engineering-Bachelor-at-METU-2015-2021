#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Attack damage 25
   * Heal power 0
   * Max HP 1000
   * Goal Priorities -> {TO_ENEMY,ATTACK,CHEST} in decreasing order
   * Class abbreviation -> "ta" or "TA"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */
Tank::Tank(uint id,int x, int y, Team team):Player(id,x,y,team){
	this->HP=1000;
}

int Tank::getAttackDamage()const{
	return 25;
}
int Tank::getHealPower()const{
	return 0;
}
int Tank::getMaxHP()const{
	return 1000;
}

std::vector<Goal> Tank::getGoalPriorityList(){
	return {TO_ENEMY,ATTACK,CHEST}; }


const std::string Tank::getClassAbbreviation() const{
	if(this->getTeam()==BARBARIANS) return "TA";
	else return "ta";
	}
std::vector<Coordinate> Tank::getAttackableCoordinates(){ //?
	Coordinate c1 =Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 =Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 =Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 =Coordinate(this->getCoord().x ,this->getCoord().y-1);

	

	
	

	return {c1,c2,c3,c4};
	}
std::vector<Coordinate> Tank::getMoveableCoordinates(){ //?

	Coordinate c1 =Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 =Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 =Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 =Coordinate(this->getCoord().x ,this->getCoord().y-1);

	

	
	

	return {c1,c2,c3,c4};
}
std::vector<Coordinate> Tank::getHealableCoordinates(){  
	return {};
}