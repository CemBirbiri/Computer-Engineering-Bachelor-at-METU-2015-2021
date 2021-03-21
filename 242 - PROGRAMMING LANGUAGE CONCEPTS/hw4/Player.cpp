#include"Player.h"
using namespace std;

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

/*
protected:
	const uint id;
	Coordinate coordinate;
	int HP;
	Team team;

*/


	/**
	 * Main constructor
	 *
	 * @param id id of the player.
	 * @param x x-coordinate of the player
	 * @param y y-coordinate of the player
	 * @param team team of the player, BARBARIAN or KNIGHT
	 *
	 */



Player::Player(uint id,int x, int y, Team team):id(id),team(team),coordinate(Coordinate(x,y)){

	//Coordinate c = Coordinate(x,y);
	//Coordinate c(x,y);
	//this->coordinate =c;
	
}

uint Player::getID() const{
	return this->id;
}
const Coordinate& Player::getCoord() const{
	return this->coordinate;
}

int Player::getHP() const{
	return this->HP;
}
/*
protected:
	const uint id;
	Coordinate coordinate;
	int HP;
	Team team;

*/
Team Player::getTeam() const{
	return this->team;
}

	/**
	 * @return the board ID of the player, If the ID is single digit add a prefix
	 * 0, otherwise just turn it into a string.
	 *
	 * Example:
	 * 3 -> "03"
	 * 12 -> "12"
	 *
	 */
bool Player::is_one_digit(uint id){
	if(id<10 && id>=0) return true;
	return false;
}
std::string Player::getBoardID(){
	if(is_one_digit(this->id)==true){
		std::string str = std::to_string(id);

		str="0"+str;
		return str;
	}
	else{
		std::string str = std::to_string(id);
		return str;
		

	}
}







	/**
	 * For each subclass of Player there are different priority lists defined
	 * that controls the next action to take for that Player. It is given in the
	 * header of the subclasses.
	 *
	 * @return the goal priority list for the Player
	 */
std::vector<Goal> Player::getGoalPriorityList(){ //VIRTUAL FUNCTION
	;
	//return {}; 

}
/*
protected:
	const uint id;
	Coordinate coordinate;
	int HP;
	Team team;

*/
	/**
	 * @return the class abbreviation of player, if the player is on the barbarian
	 * team, the abbreviation will consist of uppercase characters, otherwise it
	 * will consist of lowercase characters.
	 *
	 */

const std::string Player::getClassAbbreviation() const{ //VIRTUAL FUNCTION
	;
	//return "";

}

	/**
	 * Attack the given player.
	 * Enemy HP should decrease as much as the attack damage of attacker. Print
	 * the boardID of the attacker and the attack and the amount of damage as below.
	 * "Player 01 attacked Player 05 (75)"
	 *
	 * @param enemy player that is attacked.
	 * @return true if the opponent is dead false if alive.
	 */
bool Player::attack(Player *enemy){
	int new_hp=enemy->getHP()-this->getAttackDamage();
	
	enemy->set_hp(new_hp);
	std::cout<<"Player "<<control_id(this->getID())<<" attacked Player "<<control_id(enemy->getID())<<" ("<<this->getAttackDamage()<<")"<<std::endl;
	return enemy->isDead();
}

	/**
	 * Heal the given player by the adding amount of heal power of this character
	 * to the HP of ally. Print the boardID of the healer and healed players as
	 * below.
	 * "Player 01 healed Player 05"
	 * Healed player should not have more HP than its max HP.
	 */

void Player::heal(Player *ally){
	int new_hp=ally->getHP()+ this->getHealPower();
	ally->set_hp(new_hp);
	std::cout<<"Player "<<control_id(this->getID())<<" healed Player "<<control_id(ally->getID())<<endl;
	if(ally->getHP() > ally->getMaxHP()){
		ally->set_hp(ally->getMaxHP());
	}

}
	/**
	 * @Important The coordinates may not be on the board.
	 *
	 * @return the coordinates that the unit is able to attack given the position
	 * of the unit. Empty vector if the unit cannot attack.
	 */

std::vector<Coordinate> Player::getAttackableCoordinates(){ //VIRTUAL FUNCTION
	;
	//return {};
}

	/**
	 * @Important The coordinates may not be on the board.
	 *
	 * @return the coordinates the unit is able to move given the position of the
	 * unit. Empty vector if the unit cannot move.
	 */
std::vector<Coordinate> Player::getMoveableCoordinates(){ //VIRTUAL FUNCTION
	;
	//return {};
}

	/**
	 *
	 * @return the coordinates the unit is able to heal allies given the position of the
	 * unit. Empty vector if none available.
	 */
std::vector<Coordinate> Player::getHealableCoordinates(){  //VIRTUAL FUNCTION
	;
}

	/**
	 * Move player to coordinate. Print the boardID of the player and the old and new
	 * coordinates as below:
	 * "Player 01 moved from (0/1) to (0/2)"
	 * @Important before calling this method you must verify that this coordinate
	 * is valid to move
	 */

std::string Player::control_id(uint id){
	if(is_one_digit(this->id)==true){
		std::string str = std::to_string(id);

		str="0"+str;
		return str;
	}
	else{
		std::string str = std::to_string(id);

		
		return str;
		

	}

}
void Player::movePlayerToCoordinate(Coordinate c){
	if(c.x < 0 || c.y <0){;} //board size'a ulasamadigim icin sadece negatif mi degil mi ona bakiyorum
	else{
		std::cout<<"Player "<<control_id(this->getID())<<" moved from ("<<this->getCoord().x<<"/"<<this->getCoord().y<<")"<<" to "<<"("<<c.x<<"/"<<c.y<<")"<<endl;
		this->set_coordinate(c);
	}


}



	/**
	* Decide whether the player is dead.
	*
	* @return true if the player's HP <= 0, false otherwise.
	*/
bool Player::isDead() const{
	if(this->getHP()<=0) return true;
	else return false;
}
/*
protected:
	const uint id;
	Coordinate coordinate;
	int HP;
	Team team;

*/
void Player::set_hp(int new_hp){
	this->HP=new_hp;
}
void Player::set_coordinate(Coordinate new_c){
	this->coordinate=new_c;
}
