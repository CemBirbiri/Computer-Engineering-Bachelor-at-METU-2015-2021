#include"Game.h"
 #include<vector>


/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
/**
   * Costructor for Game class.
   * Game manages the memory allocated for future contents the vector (added players).
   * Pass a pointer to the players vector to board constructor so that the board will
   * not miss the addition of players to the game.
   * @param maxTurnNumber turn number to end the game
   * @param boardSize size of the board
   * @param chest coordinate of the chest
   */
//Board(uint _size, std::vector<Player*>* _players, Coordinate chest):size(_size),chest(chest)
  Game::Game(uint maxTurnNumber, uint boardSize, Coordinate chest):board(boardSize,&players,chest){
  		this->maxTurnNumber=maxTurnNumber;
  		this->turnNumber=1;
  		 
  		/* std::vector<Player*> * p= &players;
  		
  		Board *board=new Board(boardSize,p,chest);
  		board= &this->board;*/

  }
/*
private:          //GAME
  Board board;
  uint turnNumber;
  uint maxTurnNumber;
  std::vector<Player*> players;
*/
  Game::~Game(){
  	for(int i=0; i< players.size(); i++){
  		delete players[i];
  	}



  }
/*

private:           //BOARD
	uint size;
	std::vector<Player*>* players;
	Coordinate chest;

*/
 

  /**
   * Add a new player to the game. Add a pointer to the new player to the this->players vector.
   * Do not forget that Game will manage the memory allocated for the players.
   * @param id ID of the new player.
   * @param x x coordinate of the new player.
   * @param y y coordinate of the new player.
   * @param team team of the new player.
   * @param cls class of the new player as string, One of "ARCHER", "FIGHTER",
   * "PRIEST", "SCOUT", "TANK".
   *
   */
  void Game::addPlayer(int id, int x, int y, Team team, std::string cls){
  	if(cls=="ARCHER") {Player * new_player=new Archer(id,x,y,team);
  						players.push_back(new_player);}
  	
  	else if(cls=="FIGHTER") {Player * new_player=new Fighter(id,x,y,team);
  						players.push_back(new_player);}
  	
  	else if(cls=="PRIEST") {Player * new_player=new Priest(id,x,y,team);
  						players.push_back(new_player);}
  	
  	else if(cls=="SCOUT") {Player * new_player=new Scout(id,x,y,team);
  						players.push_back(new_player);}
  	
  	else {Player * new_player=new Tank(id,x,y,team);
  						players.push_back(new_player);}

  	

  	
  }

  /**
   * The game ends when either of these happens:
   * - All barbarians die (knight victory)
   * - All knights die (barbarian victory)
   * - A barbarian gets to the square containing the chest (barbarian victory)
   * - maxTurnNumber of turns played (knight victory)
   *
   * If the game ends announce it py printing the reason, turn number and the victor
   * as in the following examples:
   *
   * Game ended at turn 13. All barbarians dead. Knight victory.
   * Game ended at turn 121. All knights dead. Barbarian victory.
   * Game ended at turn 52. Chest captured. Barbarian victory.
   * Game ended at turn 215. Maximum turn number reached. Knight victory.
   *
   * @return true if any of the above is satisfied, false otherwise
   *
   */
  bool Game::isGameEnded(){
  	int flag=0;
  	int knights=0;
  	int barbarians=0;
  	for(int i=0; i< players.size(); i++){
  		if(players[i]->getTeam()==BARBARIANS) barbarians+=1;
  		if(players[i]->getTeam()==KNIGHTS) knights+=1;

  	}
  	if(knights ==0 && barbarians !=0 ){
  		std::cout<<"Game ended at turn "<<this->turnNumber-1<<". All knights dead. Barbarian victory."<<std::endl;
  		return true;
  	}
  	else if(knights !=0 && barbarians ==0 ){
  		std::cout<<"Game ended at turn "<<this->turnNumber-1<<". All barbarians dead. Knight victory."<<std::endl;
  		return true;
  	}
  	else if(maxTurnNumber== turnNumber-1 ){
  		std::cout<<"Game ended at turn "<<this->maxTurnNumber<<". Maximum turn number reached. Knight victory."<<std::endl;
  		return true;
  	}
  	else{
  		for(int j=0; j< players.size(); j++){
  			if(players[j]->getTeam()==BARBARIANS && players[j]->getCoord()==this->board.getChestCoordinates()) flag=1;
  		}
  		if(flag==1){
  			std::cout<<"Game ended at turn "<<this->turnNumber-1<<". Chest captured. Barbarian victory."<<std::endl;
  			return true;
  		}
  		else{
  			return false;
  		}
  	}

  }
 
bool Game::is_in_mins(std::vector<int> mins , int id){
	for(int i=0; i<mins.size(); i++ ){
		if(mins[i]==id) return true;

	}
	return false;
}
Player * Game::find_min(std::vector<Player*> players , std::vector<int> mins){
	int min=99999;
	for(int i=0; i< players.size() ; i++){
		if(is_in_mins(mins, players[i]->getID())==false && players[i]->getID() < min){
			min=players[i]->getID();
		}
	}
	for(int i=0; i< players.size() ; i++){
		if(players[i]->getID() == min) return players[i];
	}
	return NULL;
}
/*
private:          //GAME
  Board board;
  uint turnNumber;
  uint maxTurnNumber;
  std::vector<Player*> players;
*/
  /**
   * Play a turn for each player.
   * Actions are taken in the order of ID numbers of players (player with
   * smaller ID acts first).
   * At the start of the turn it announces that the turn has started by printing
   * to stdout. Turn numbers starts with 1.
   * Ex: "Turn 13 has started."
   * Call playTurnForPlayer for every player.
   *
   */
std::vector<int> Game::delete_from_mins(std::vector<int> mins,int id){
	std::vector<int> new_mins;
	for(int i=0; i< mins.size(); i++){
		if(mins[i]!=id) new_mins.push_back(mins[i]);
		else{;}
	}
	return new_mins;
} 
 void Game::playTurn(){
  	std::cout<<"Turn "<<this->turnNumber<<" has started."<<std::endl;
  	Player* deneme;
  	int j;
  	int temp2=players.size();
  	
  	std::vector<int> mins;
  	
  	int min=99999;
  	//std::cout<<"burda1 "<<players.size()<<std::endl;
  	
  	for(int i=0; i< players.size(); i++){
		
  		if(players[i]->getID()< min) min=players[i]->getID();
  	}
  	
  	mins.push_back(min);
  	for(int i=0; i< players.size(); i++){
  		if(players[i]->getID() == min){ 
  			playTurnForPlayer(players[i]);//min id li player oynuyor

  			break;

  		}
  	}
  	if(players.size()==1){
	  			playTurnForPlayer(players[0]);
	  			turnNumber=turnNumber+1;
	  		}
	 else{
  	if(temp2==players.size()+1){
  		mins.pop_back();
	  	//std::cout<<"burda222 "<<players.size()<<std::endl;
	  	//std::cout<<"burda3333 "<<players[0]->getID()<<std::endl;
	  	
	  	turnNumber=turnNumber+1;
	  	//if(temp2=players.size()+1) j=0;
	  	//else j=1;
	  	j=0;
	  	int temp1=0;
	  	int id;
	  	while(j<players.size()){
	  		
	  		//if(players[1]->getHP()==0)
	  		temp1=players.size();
	  		

	  		
	  		//std::cout<<"a1"<<std::endl;

	  		//std::cout<<"*************************************************"<<players[j]->getID()<<std::endl;
	  		
	  		//if(isGameEnded()){ break;}
	  		
	  		deneme=find_min(players , mins) ;
	  		id=deneme->getID();
	  		
	  		//std::cout<<"------------------id---------------------->"<<deneme->getID()<<std::endl;
	  		//std::cout<<"------------------hp---------------------->"<<deneme->getHP()<<std::endl;
	  		//std::cout<<"------------------jj----------------------->"<<j<<std::endl;
	  		//std::cout<<"------------------size--------------------->"<<players.size()<<std::endl;
	  		//std::cout<<"------------------temp1---------------------->"<<temp1<<std::endl;
	  		
	  		//if(deneme->getID()==3) std::cout<<deneme->getGoalPriorityList()[0]<<std::endl;
	  		
	  		playTurnForPlayer(deneme);
	  		//playTurnForPlayer( find_min(players , mins) );
	  		//std::cout<<"a2"<<std::endl;

	  		//std::cout<<"**********************************************************************************"<<std::endl;
	  		//std::cout<<"0000000000000000000000000000000111111----->"<<players.size()<<std::endl;
	  		//std::cout<<"000000000000000000000000000000222222----->"<<players[j]->getID()<<std::endl;
	  		//std::cout<<"------------------id---------------------->"<<deneme->getID()<<std::endl;
	  		//std::cout<<"------------------hp----------------------->"<<deneme->getHP()<<std::endl;
	  		//std::cout<<"------------------jj----------------------->"<<j<<std::endl;
	  		//std::cout<<"------------------size--------------------->"<<players.size()<<std::endl;
	  		//std::cout<<"------------------temp1---------------------->"<<temp1<<std::endl;
	  		
	  		if(temp1 ==players.size()+1){;
	  			
	  		}
	  		else{
	  			mins.push_back(find_min(players,mins)->getID());
	  			j=j+1;}

	  	}
	  	
	  
  	}//new if
  	else{

	  	//std::cout<<"burda222 "<<players.size()<<std::endl;
	  	//std::cout<<"burda3333 "<<players[0]->getID()<<std::endl;
	  	if(players.size()==1){
	  			playTurnForPlayer(players[0]);
	  		}
	  	turnNumber=turnNumber+1;
	  	//if(temp2=players.size()+1) j=0;
	  	//else j=1;
	  	j=1;
	  	int temp1=0;
	  	int id;
	  	while(j<players.size()){
	  		
	  		//if(players[1]->getHP()==0)
	  		temp1=players.size();
	  		

	  		
	  		//std::cout<<"a1"<<std::endl;

	  		//std::cout<<"*************************************************"<<players[j]->getID()<<std::endl;
	  		
	  		//if(isGameEnded()){ break;}
	  		
	  		deneme=find_min(players , mins) ;
	  		id=deneme->getID();
	  		
	  		//std::cout<<"------------------id---------------------->"<<deneme->getID()<<std::endl;
	  		//std::cout<<"------------------hp---------------------->"<<deneme->getHP()<<std::endl;
	  		//std::cout<<"------------------jj----------------------->"<<j<<std::endl;
	  		//std::cout<<"------------------size--------------------->"<<players.size()<<std::endl;
	  		//std::cout<<"------------------temp1---------------------->"<<temp1<<std::endl;
	  		
	  		//if(deneme->getID()==3) std::cout<<deneme->getGoalPriorityList()[0]<<std::endl;
	  		
	  		playTurnForPlayer(deneme);
	  		//playTurnForPlayer( find_min(players , mins) );
	  		//std::cout<<"a2"<<std::endl;

	  		//std::cout<<"**********************************************************************************"<<std::endl;
	  		//std::cout<<"0000000000000000000000000000000111111----->"<<players.size()<<std::endl;
	  		//std::cout<<"000000000000000000000000000000222222----->"<<players[j]->getID()<<std::endl;
	  		//std::cout<<"------------------id---------------------->"<<deneme->getID()<<std::endl;
	  		//std::cout<<"------------------hp----------------------->"<<deneme->getHP()<<std::endl;
	  		//std::cout<<"------------------jj----------------------->"<<j<<std::endl;
	  		//std::cout<<"------------------size--------------------->"<<players.size()<<std::endl;
	  		//std::cout<<"------------------temp1---------------------->"<<temp1<<std::endl;
	  		
	  		if(temp1 ==players.size()+1){;
	  			
	  		}
	  		else{
	  			mins.push_back(find_min(players,mins)->getID());
	  			j=j+1;}

	  	}
	  	
  	}
  	}
  }

std::vector<Coordinate>  Game::valid_coords_attack_inboard(std::vector<Coordinate> coords,Coordinate self){
	std::vector<Coordinate>  new_cords;
	for(int i=0; i< coords.size(); i++){
		if(board.isCoordinateInBoard(coords[i])==true && coords[i]!=self ){
			new_cords.push_back(coords[i]);
		}
	}
	return new_cords;
} 

std::vector<Coordinate>  Game::valid_coords_move(std::vector<Coordinate> coords,Coordinate self){
	std::vector<Coordinate>  new_cords;
	for(int i=0; i< coords.size(); i++){
		if(board.isCoordinateInBoard(coords[i])==true && coords[i]!=self && board.isPlayerOnCoordinate(coords[i])==false){
			new_cords.push_back(coords[i]);
		}
	}
	return new_cords;
}

void Game::delete_in_game_players(Player *player){
	for(int i=0; i< players.size(); i++){

		//std::cout<<"takip1.1"<<std::endl;
		if(players[i]==player) {

			//std::cout<<"takip1.11"<<std::endl;
			//std::cout<<player->getID()<<std::endl;

			delete player;
			//std::cout<<"takip1.12"<<std::endl;

			break;}

	}
}
  /**
   * Play a turn for the given player.
   * If the player is dead announce its death by printing the boardID of the player
   * as in "Player 07 died.". Remove that player from the board and release its resources.
   *
   * Each player has a goal list sorted by its priority for that player.
   * When a player plays a turn it iterates over its goal list and tries to take
   * an action. Valid actions are attack, move and heal. A player can take only
   * one action in a turn, and if there is no action it can take it stops and does nothing.
   * Before moving a player you must check if the coordinate to move is valid.
   * Meaning that, the coordinate is in the bounds of the board and there are no
   * players there.
   *
   * IMPORTANT NOTE: every usage of the word nearest is referencing smallest the manhattan
   * distance, which is formulated as (abs(x_1-x_2) + abs(y_1-y_2)). operator-
   * overloaded in Coordinate.h computes exactly that, so you can use that method to
   * calculate the distance between two coordinates.
   *
   * Below are the explanations for goals:
   *
   * ATTACK:
   *   - If there are any enemies in the attack range of the player attack to it.
   *     If there are more than 1 enemy in the range attack to the one with
   *     lowest ID. If there is no one to attack try the next goal.
   *
   * CHEST:
   *   - Move to the direction of the chest, if both vertical and horizontal moves
   *     are available, pick the horizontal one. If the horizontal move is blocked
   *     but the vertical move is not, move vertically. If all directions towards
   *     the chest is blocked try the next goal.
   *
   * TO_ENEMY:
   *   - Move towards the nearest enemy. If there are more than one enemies with the same distance
   *     move towards the one with the smallest ID. If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an enemy is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected enemy is blocked, try the next goal.
   *
   * TO_ALLY:
   *   - Move towards the nearest ally. If there are more than one allies with the same distance
   *     move towards the one with the smallest ID.  If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an ally is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected ally is blocked, try the next goal.
   *
   * HEAL:
   *   - If there are any allies in the healing range heal all of them. if there
   *     is no one to heal try the next goal.
   *
   *
   * @return the goal that the action was taken upon. NO_GOAL if no action was taken.
   */


  Goal Game::playTurnForPlayer(Player* player){
  	//std::cout<<"geldi"<<std::endl;
   	
   	//std::cout<<player->getID()<<" "<<"a"<<std::endl;
   	
   	//std::cout<<player->getGoalPriorityList().empty()<<std::endl;

   	//std::cout<<"adddddddddddd"<<std::endl;
  	
  	int flag=0;
  	Player * temp;
  	
  	std::vector<Player*> enemies;
  	if(player->getHP()<=0){
  			
	  				std::cout<<"Player "<<control_id(player->getID())<<" has died."<<std::endl;
	  				//board.set_board(board.delete_player( player));//en son burdayim , delete player yapamadim
	  				
	  				
	  				for(int m=0; m<players.size(); m++){
	  					if(players[m]->getID()==player->getID()){
	  						//std::cout<<"adddddddddddd"<<std::endl;
	  						
	  						players.erase(players.begin()+m);
	  						delete player;
	  					}
	  				}
	  				//board.print();

	  			

	  				
	  				

	  				

	  			}
	 else{
  	//std::cout<<"geldi1"<<std::endl;
  	
  	for(int i=0; i< player->getGoalPriorityList().size(); i++){

  		//std::cout<<"geldi2"<<std::endl;
  		
  		if(player->getGoalPriorityList()[i]==ATTACK){  //*****************ATTACK*******************************************
  			//std::cout<<"attack"<<std::endl;
  			Player* enemy;

  			std::vector<Coordinate> attack_coords= player->getAttackableCoordinates();//attackable kordinatlari al
  			
  			attack_coords= valid_coords_attack_inboard( attack_coords,player->getCoord()); //valid mi degil mi diye bak

  			
  			
  			for(int j=0; j< attack_coords.size(); j++){
  				if( board.isPlayerOnCoordinate(attack_coords[j])==true && board[attack_coords[j]]->getTeam()!=player->getTeam() ){//attackable cordinatlarda attack edebilecegimiz player var mi
  					enemies.push_back(board[attack_coords[j]]);
  				}
  			}
  			if(enemies.empty()!=true){

  				

	  			int min = 9999;
	  			for(int j=0; j< enemies.size(); j++){
	  				if(enemies[j]->getID()< min) min=enemies[j]->getID();
	  			}
	  			for(int j=0; j<enemies.size(); j++){//id si en dusuk playeri bul
	  				if(enemies[j]->getID()== min){ 
	  					enemy=enemies[j];}
	  			}
	  			player->attack(enemy); //saldir
	  			
	  			//std::cout<<"track0"<<std::endl;
	  			break;}
  			else {

  				//std::cout<<"track1"<<std::endl;
  				continue;}



  		}
  		else if(player->getGoalPriorityList()[i]==CHEST){ //*********************CHEST***************************************
  			Coordinate cord_go(0,0);
  			std::vector<int> distances;
  			int min_distance=0;
  			std::vector<Coordinate> last_cs;
  			
  			std::vector<Coordinate> move_coords= player->getMoveableCoordinates(); //hareket edebilecegi kordinatlari al
  			move_coords=valid_coords_move( move_coords,player->getCoord()); //valid mi degil mi diye bak

  			if(move_coords.empty()==true) ;
  			else{
  				for(int j=0; j< move_coords.size(); j++){
  					distances.push_back(move_coords[j]-board.getChestCoordinates()); //cheste en yakin kordinatlari al
  				}
  				min_distance=find_min_distance(distances); //min distancelara sahip kordinatlari bul
  				for(int j=0; j< move_coords.size(); j++){
  					if(distances[j]==min_distance) last_cs.push_back(move_coords[j]); //
  				}
  				
	  			cord_go= find_uygun_cord( board.getChestCoordinates(), last_cs, player->getCoord());
	  			if(cord_go.x==-99){
  					;
  				}
  				
  				else {
  					player->movePlayerToCoordinate(cord_go);

  					break;}

  			}
  		}
  		else if(player->getGoalPriorityList()[i]==TO_ENEMY){ //**********************TO_ENEMY****************************
  			
  			Coordinate cord_go(0,0);

  			std::vector<Coordinate> enemy_coords;
  			std::vector<int> distances;
  			int min_distance=999;
  			Player * enemy=NULL;
  			
  			std::vector<Coordinate> move_coords= player->getMoveableCoordinates(); //hareket edebilecegi kordinatlari al
  			move_coords=valid_coords_move( move_coords,player->getCoord());//valid olanlari al
  			
  			if(move_coords.empty()==true) ;
  			else{
  				
  				
  				std::vector<Player*>* players=board.get_players();
  				
  				
  				
  				
  				//.............................................................
  				
  				
  				for(int j=0; j< (*players).size() ; j++){
  					if( player->getCoord() - (*players)[j]->getCoord() != 0 && (*players)[j]->getTeam()!= player->getTeam()) {
  					distances.push_back( player->getCoord() - (*players)[j]->getCoord() ); 
  					}//boarddaki eneymlerin distancelarini bul,kendisi haric
  					else{ distances.push_back( 999 ); } //kendisi ile distancei 999 olsun
  				}

  				
  				min_distance=find_min_distance(distances); //find min distance
  				for(int j=0; j< distances.size(); j++){
  					if(distances[j]==min_distance) enemy_coords.push_back((*players)[j]->getCoord()); 
  					//min distancea sahip eneymleri topluyoruz
  				}
  				Coordinate min_id_cord=Coordinate(99,99);
  				int min_id=999;
  				

  				//min distancea sahip enemy coordinatlari elimizde

  				for(int j=0; j< enemy_coords.size(); j++){ //min id'ye sahip eneymyi buluyoruz
  					if(board[enemy_coords[j]]->getID() < min_id){
  						min_id =board[enemy_coords[j]]->getID();
  						min_id_cord= board[enemy_coords[j]]->getCoord();
  					}
  				}
  				cord_go= find_uygun_cord( min_id_cord, move_coords, player->getCoord());

  				if(cord_go.x==-99){
  					;
  				}
  				
  				else {
  					player->movePlayerToCoordinate(cord_go);

  					break;}

  				
  				
  				

  			}
  			
  			
  		}//to enemy
  		else if(player->getGoalPriorityList()[i]==TO_ALLY){ //**********************TO_ALLY****************************
  			
  			Coordinate cord_go(0,0);

  			std::vector<Coordinate> ally_coords;
  			std::vector<int> distances;
  			int min_distance=0;
  			Player * ally=NULL;
  			
  			std::vector<Coordinate> move_coords= player->getMoveableCoordinates(); //hareket edebilecegi kordinatlari al
  			move_coords=valid_coords_move( move_coords,player->getCoord());//valid olanlari al
  			
  			if(move_coords.empty()==true) ;
  			else{
  				
  				
  				std::vector<Player*>* players=board.get_players();
  				
  				
  				
  				
  				//.............................................................
  				
  				
  				for(int j=0; j< (*players).size() ; j++){
  					if( player->getCoord() - (*players)[j]->getCoord() != 0 && (*players)[j]->getTeam()== player->getTeam()) {
  					distances.push_back( player->getCoord() - (*players)[j]->getCoord() ); 
  					}//boarddaki allylarin distancelarini bul,kendisi haric
  					else{ distances.push_back( 999 ); } //kendisi ile distancei 999 olsun
  				}

  				
  				min_distance=find_min_distance(distances); //find min distance
  				for(int j=0; j< distances.size(); j++){
  					if(distances[j]==min_distance) ally_coords.push_back((*players)[j]->getCoord()); 
  					//min distancea sahip allyleri topluyoruz
  				}
  				Coordinate min_id_cord=Coordinate(99,99);
  				int min_id=999;
  				

  				//ally coordinatlari elimizde

  				for(int j=0; j< ally_coords.size(); j++){ //min id'ye sahip allyyi buluyoruz
  					if(board[ally_coords[j]]->getID() < min_id){
  						min_id =board[ally_coords[j]]->getID();
  						min_id_cord= board[ally_coords[j]]->getCoord();
  					}
  				}
  				cord_go= find_uygun_cord( min_id_cord, move_coords, player->getCoord());

  				if(cord_go.x==-99){
  					;
  				}
  				
  				else {
  					player->movePlayerToCoordinate(cord_go);

  					break;}
  				
  				

  			}
  			
  			
  		}//to ally
  		else if(player->getGoalPriorityList()[i]==HEAL){  //HEAL

  			/*HEAL:
   			*   - If there are any allies in the healing range heal all of them. if there
   			*     is no one to heal try the next goal.*/
  			std::vector<Coordinate> heal_coords= player->getHealableCoordinates(); //heal edebilecegi kordinatlari al
  			heal_coords=valid_coords_attack_inboard( heal_coords,player->getCoord());//burda boardda mi degil mi diye kontrol etmek yeter
  			std::vector<Player*> allies;
  			for(int j=0; j< heal_coords.size(); j++){
  				if(board.isPlayerOnCoordinate(heal_coords[j])==true && board[heal_coords[j]]->getTeam()==player->getTeam()){ 
  				//healable coordinatlardaki allyleri buluyoruz
  					allies.push_back(board[heal_coords[j]]);
  				}
  			}
  			if(allies.empty()==true){

  				
  				continue;
  				;}
  			else{

	  			/*for(int j=0; j< allies.size(); j++){
	  				player->heal(allies[j]);//iyilestiriyor
  					}*/

std::vector<int> mins;
int min=99999;

for(int i=0; i< allies.size(); i++){
  		
  		
  		
  		if(allies[i]->getID()< min) min=allies[i]->getID();

  	}
for(int i=0; i< allies.size(); i++){
  	if(allies[i]->getID() == min){ 
  		mins.push_back(min);
  		player->heal(allies[i]);
  		break;
  	}
}
for(int i=0; i< allies.size(); i++){
	if(allies[i]->getID()!=min){
		player->heal(find_min(allies,mins));
		mins.push_back(find_min(allies,mins)->getID());
	}
}





  			}
  			break;
  		}//heal
  		else{;} //NO_GOAL

  		
  	}

  }
}
Coordinate Game::find_uygun_cord(Coordinate min_id_cord, std::vector<Coordinate> move_coords, Coordinate self){
	std::vector<Coordinate> xs;
	std::vector<Coordinate> ys;
	std::vector<Coordinate> others;

	std::vector<int> dx;
	std::vector<int> dy;
	std::vector<int> d0;

	Coordinate temp(0,0);
	Coordinate uygunsuz(-99,-99);

	int min_dist=999;
	
	for(int i=0; i< move_coords.size(); i++){
		if(move_coords[i].x == self.x+1) xs.push_back(move_coords[i]);
		if(move_coords[i].x == self.x-1) xs.push_back(move_coords[i]);
		if(move_coords[i].x == self.x-2) xs.push_back(move_coords[i]);
		if(move_coords[i].x == self.x+2) xs.push_back(move_coords[i]);
	
		if(move_coords[i].y == self.y+1) ys.push_back(move_coords[i]);
		if(move_coords[i].y == self.y-1) ys.push_back(move_coords[i]);
		if(move_coords[i].y == self.y-2) ys.push_back(move_coords[i]);
		if(move_coords[i].y == self.y+2) ys.push_back(move_coords[i]);
		else others.push_back(move_coords[i]);
	}
	for(int i=0; i< xs.size(); i++){
		dx.push_back(xs[i]-min_id_cord);
	}
	for(int i=0; i< ys.size(); i++){
		dy.push_back(ys[i]-min_id_cord);
	}
	for(int i=0; i< others.size(); i++){
		d0.push_back(others[i]-min_id_cord);
	}
	int min=999;
	for(int i=0; i< dx.size(); i++){
		if(dx[i]< min) min=dx[i];
	}
	for(int i=0; i< dy.size(); i++){
		if(dy[i]< min) min=dy[i];
	}
	for(int i=0; i< d0.size(); i++){
		if(d0[i]< min) min=d0[i];
	}
	//*****
	for(int i=0; i< dx.size(); i++){
		if(dx[i]== min) { 
			if((xs[i]-min_id_cord) >= (self-min_id_cord) ){
				return uygunsuz;
			}

			else return xs[i];
		}
	}
	for(int i=0; i< dy.size(); i++){
		if(dy[i]== min) { 
			if((ys[i]-min_id_cord) >= (self-min_id_cord) ){
				return uygunsuz;
			}

			else return ys[i];
		}
	}
	for(int i=0; i< d0.size(); i++){
		if(d0[i]== min) { 
			if((others[i]-min_id_cord) >= (self-min_id_cord) ){
				return uygunsuz;
			}

			else return others[i];
		}
	}


}
int Game::find_min_distance(std::vector<int> distances){
	
	int min=9999;
	for(int i=0; i < distances.size(); i++){
		if(distances[i] < min) min= distances[i];
	}
	return min;

}
std::vector<Player*>* Game::kik_same_team(std::vector<Player*>* players,Team team){
	std::vector<Player*>* oyuncular;

	

	for(int i=0; i< (*players).size(); i++) {
		
		if((*players)[i]->getTeam()!= team) {
			
			
			
			(*oyuncular).push_back((*players)[i]);
			
			

		}
	
	}
	
	return (oyuncular);
}






std::string Game::control_id(uint id){
	if(is_one_digit(id)==true){
		std::string str = std::to_string(id);

		str="0"+str;
		return str;
	}
	else{
		std::string str = std::to_string(id);

		
		return str;
		

	}

}

bool Game::is_one_digit(uint id){
	if(id<10 && id>=0) return true;
	return false;
}






