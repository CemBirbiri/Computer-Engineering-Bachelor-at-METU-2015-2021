#include"Board.h"
#include<vector>

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/*

private:
	uint size;
	std::vector<Player*>* players;
	Coordinate chest;

*/
		
Board::Board(uint _size, std::vector<Player*>* _players, Coordinate chest):size(_size),chest(chest){
	

	this->players=_players;

	
	
	

}
std::vector<Player*>* Board::get_players(){
	return players;
}

Board::~Board(){
}
/**
	 * @return true if the coordinate is in the board limits, false otherwise.
	 */
bool Board::isCoordinateInBoard(const Coordinate& c){
	if(c.x < 0 || c.y < 0) return false; //negatif mi degil mi bakiyor
	else{
		if(c.x >= this->size) return false; //boardin icinde mi diye bakiyor
		else if(c.y >= this->size ) return false;
		else return true;
	}
}
/*

*/
/**
	 * @return true if there is a player on the given coordinate, false otherwise.
	 */
bool Board::isPlayerOnCoordinate(const Coordinate& c){
	if(isCoordinateInBoard(c)==false) return false;
	else{
		int i=0;
		for(; i< (*players).size() ; i++){
			if((*players)[i]->getCoord().x ==c.x &&(*players)[i]->getCoord().y==c.y){
				if((*players)[i] != NULL) return true;
				else return false;
			}
		}
	}
	/*if(isCoordinateInBoard(c)==true){ //verilen cordinate boardda mi diye bakiyor
		if(c==chest) return false; //chestin kordinatiysa false don
		else{
			if(players[c.x][c.y]==NULL) return false;
			else {

				//std::cout<<players[c.x][c.y]->getID()<<std::endl;
				return true;}
		}
	
}
	else return false; //coordinat boardda degilse false donuyor */

}

/**
	 * @return pointer to the player at the given coordinate. Return NULL if no
	 * player is there.
	 */
Player * Board::operator [](const Coordinate& c){
	if(isPlayerOnCoordinate(c)==true){
		
		int i=0;
		for(int i=0; i< (*players).size();i++){
			if((*players)[i] != NULL && (*players)[i]->getCoord().x ==c.x &&(*players)[i]->getCoord().y==c.y){
				return (*players)[i];
			}
		}return NULL;
	}
	else return NULL;


	
}

/**
	 * @return the chest coordinate
	 */
Coordinate Board::getChestCoordinates(){
	return chest;
}

/**
	  * Print the board with character ID's.
	  * For each empty square print two underscore characters.
		* For the squares with a player on it, print the board id of the player.
		* For the square with the chest, print the string "Ch".
		* If a character is on the square with the chest, only print the ID of the
		* character.
		* For each row print a new line, for each column print a space character.
		* Example:
		* __ __ 01 __
		* __ 02 __ 05
		*	Ch __ __ 03
		*	__ __ __ __
	  */
bool Board::is_one_digit(uint id){
	if(id<10 && id>=0) return true;
	return false;
}

std::string Board::give_id(int *x_cord,int *y_cord,uint *ids, int i, int j,int len){
	int k=0;
	for(; k<len; k++){
		if(x_cord[k]==i && y_cord[k]==j){ 
			
			if(is_one_digit(ids[k])==true){
				std::string str = std::to_string(ids[k]);

				str="0"+str;
				return str;
				
			}
			else{
				std::string str = std::to_string(ids[k]);
				return str;
				

			}
		}
	}
}
void Board::printBoardwithID(){
	uint   ids[(*players).size()];
	int x_cord[(*players).size()];
	int y_cord[(*players).size()];
	
	int i=0;
	for(;i<(*players).size(); i++){
		
		ids[i]=(*players)[i]->getID();
		x_cord[i]=(*players)[i]->getCoord().x;
		y_cord[i]=(*players)[i]->getCoord().y;
	}
	int j=0;
	

	 i=0;
	for (; i< size  ; i++){
		 j=0;

		for(; j< size; j++){


			if(is_in( x_cord, y_cord,ids,j,i,(*players).size())==true){

				std::cout<<give_id(x_cord, y_cord,ids,j,i,(*players).size());
			}
			else{
				Coordinate c=Coordinate(j,i);
				if(chest==c) std::cout<<"Ch";
				else std::cout<<"__";
			}
			std::cout<<" ";

			}
			
			std::cout<<""<<std::endl;
			

		}
	
	

}
bool Board::is_in(int *x_cord,int *y_cord,uint* ids, int i, int j,int len){
	int k=0;
	for(; k<len; k++){
		if(x_cord[k]==i && y_cord[k]==j) return true;

	}
	return false;
}
std::string Board::give_ab(int *x_cord,int *y_cord,std::string *abs, int i, int j,int len){
	int k=0;
	for(; k<len; k++){
		if(x_cord[k]==i && y_cord[k]==j){ 
			
			return abs[k];
					}
	}
}
/**
	 * For each empty square print two underscore characters.
	 * For the squares with a player on it, print the class abbreviation of the
	 * player.
	 * For the square with the chest, print the string "Ch".
	 * If a character is on the square with the chest, only print the abbreviation
	 * of the character.
	 * To separate each row print a new line, to separate each column print a
	 * space character.
	 * Example:
	 * __ __ PR __
	 * __ ar __ TA
	 * Ch __ __ fi
	 * __ __ __ __
	 */
void Board::printBoardwithClass(){
	uint   ids[(*players).size()];
	std::string abs[(*players).size()];
	int x_cord[(*players).size()];
	int y_cord[(*players).size()];
	
	int i=0;
	for(;i<(*players).size(); i++){
		
		abs[i]=(*players)[i]->getClassAbbreviation();
		x_cord[i]=(*players)[i]->getCoord().x;
		y_cord[i]=(*players)[i]->getCoord().y;
		ids[i]=(*players)[i]->getID();

	}
	int j=0;
	

	 i=0;
	for (; i< size  ; i++){
		 j=0;

		for(; j< size; j++){


			if(is_in( x_cord, y_cord,ids,j,i,(*players).size())==true){

				std::cout<<give_ab(x_cord, y_cord,abs,j,i,(*players).size());
			}
			else{
				Coordinate c=Coordinate(j,i);
				if(chest==c) std::cout<<"Ch";
				else std::cout<<"__";
			}
			std::cout<<" ";

			}
			
			std::cout<<""<<std::endl;
			

		}

}

std::vector<Player*> * Board::delete_player(Player *player){
	//std::vector<Player*> players_fake;

	

	//std::cout<<(*players)[0]->getID()<<(*players)[1]->getID()<<std::endl;

  	
	
	Player * temp;
	for(int i=0; i< (*players).size(); i++){
		
		
		
		if((*players)[i]==player) {
			
			temp=(*players)[i];
			
			
			(*players).erase((*players).begin()+i);
			
			delete temp;
			

		}
			
			
		
		/*else {

			(players_fake).push_back( (*players)[i] );
			
				
				}*/
			
			}
		
			/*(*players).clear();
			
			for(int i=0; i< (players_fake).size(); i++){
				(*players).push_back(players_fake[i]);
		
	}*/
		
			//(players_fake).clear();

	return players;
}


void Board::print(){
	for(int i=0; i< (*players).size(); i++){
		std::cout<<"55555555555-->"<<(*players)[i]->getID()<<std::endl;
	}
}


/*
std::vector<int>::iterator it;
	Player * temp;
	for(int i=0; i< (*players).size(); i++){
		if((*players)[i]==player) {
			temp=(*players)[i];
			std::cout<<"seg1?"<<std::endl;
			std::cout<<player->getID()<<std::endl;
		
			delete temp;
			it=i;
			(*players).erase(it);
			temp=NULL;
			//std::cout<<temp->getID()<<std::endl;
			std::cout<<"seg2?"<<std::endl;
			break;}
			std::cout<<"seg3?"<<std::endl;

	}
	std::cout<<"seg4?"<<std::endl;
	for(int i=0; i< (*players).size(); i++){
		std::cout<<"666666666666-->"<<(*players)[i]->getID()<<std::endl;
	}

*/
void Board::set_board(std::vector<Player*> *players){
	this->players=players;
}