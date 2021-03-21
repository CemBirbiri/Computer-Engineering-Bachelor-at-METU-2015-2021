#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Attack damage 100
   * Heal power 0
   * Max HP 400
   * Goal Priorities -> {ATTACK,TO_ENEMY,CHEST} in decreasing order
   * Class abbreviation -> "fi" or "FI"
   * Can move to adjacent up, down, left or right square
   * Can attack to adjacent up, down, left or right square
   *
   */
//virtual ~Player() = default;
Fighter::Fighter(uint id,int x, int y, Team team):Player(id,x,y,team){
	this->HP=400;
}

int Fighter::getAttackDamage()const{
	return 100;
}
int Fighter::getHealPower()const{
	return 0;
}
int Fighter::getMaxHP()const{
	return 400;
}

std::vector<Goal> Fighter::getGoalPriorityList(){
	return {ATTACK,TO_ENEMY,CHEST}; 
}


const std::string Fighter::getClassAbbreviation() const{
	if(this->getTeam()==BARBARIANS) return "FI";
	else return "fi";
	}
std::vector<Coordinate> Fighter::getAttackableCoordinates(){ //?
	Coordinate c1 = Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 = Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 = Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 = Coordinate(this->getCoord().x ,this->getCoord().y-1);

	

	
	

	return {c1,c2,c3,c4};

	}
std::vector<Coordinate> Fighter::getMoveableCoordinates(){//?

	Coordinate c1 = Coordinate(this->getCoord().x+1 ,this->getCoord().y);
	Coordinate c2 = Coordinate(this->getCoord().x ,this->getCoord().y+1);
	Coordinate c3 = Coordinate(this->getCoord().x-1 ,this->getCoord().y);
	Coordinate c4 = Coordinate(this->getCoord().x ,this->getCoord().y-1);

	

	
	

	return {c1,c2,c3,c4};
}
std::vector<Coordinate> Fighter::getHealableCoordinates(){  
	return {};
}