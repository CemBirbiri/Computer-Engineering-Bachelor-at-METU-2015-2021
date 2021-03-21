#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Attack damage 25
   * Heal power 0
   * Max HP 125
   * Goal Priorities -> {CHEST,TO_ALLY,ATTACK} in decreasing order
   * Class abbreviation -> "sc" or "SC"
   * Can move to all adjacent squares, including diagonals.
   * Can attack all adjacent squares, including diagonals.
   *
   */
Scout::Scout(uint id,int x, int y, Team team):Player(id,x,y,team){
	this->HP=125;
}
int Scout::getAttackDamage()const{
	return 25;
}
int Scout::getHealPower()const{
	return 0;
}
int Scout::getMaxHP()const{
	return 125;
}

std::vector<Goal> Scout::getGoalPriorityList(){
	return {CHEST,TO_ALLY,ATTACK}; }


const std::string Scout::getClassAbbreviation() const{
	if(this->getTeam()==BARBARIANS) return "SC";
	else return "sc";
	}
std::vector<Coordinate> Scout::getAttackableCoordinates(){ //?
	
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
std::vector<Coordinate> Scout::getMoveableCoordinates(){ //?

	
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
std::vector<Coordinate> Scout::getHealableCoordinates(){  
	return {};

}