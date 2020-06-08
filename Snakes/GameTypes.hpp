/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/25/2020
File: GameTypes.hpp
*/

// This program emulates the famous game "Snakes and ladders".
#include <bits/stdc++.h>
#include "Player.h"
#include "Exception.h"

using namespace std;
//MANUAL TYPE
class Manual {
protected:
  //ATTRIBUTS
  int tiles, snakes, ladders, penalty, reward, players, turns;
  char action;
  int turn;
  char options[2];
  unordered_map <int, Player> gamers;
  unordered_map <int, Tile*> board;
public:
  //CONSTRUCTOR
  Manual();
  //OVERLOADING
  Manual(int, int, int, int, int, int, int);
  //METHODS
  virtual void continueGame();
  void endGame(char);
  void endGame(int);
  void main();
  void makeBoard();
  void validateTurns();
};

//CONSTRUCTOR
Manual::Manual(){
  //These values are from the normal mode.
  tiles = 30;
  snakes = 3;
  ladders = 3;
  penalty = 3;
  reward = 3;
  players = 2;
  action = 'C';
  turns = 20;
  turn = 0;
  options[0]= 'E';
  options[1]= 'C';

  gamers[1].setPlayerNumber(1);
  gamers[2].setPlayerNumber(2);
  makeBoard();

}
// CONSTRUCTOR
Manual::Manual(int t, int s, int l, int p, int r, int nP, int ts){
//When the user enters the values, then this Constructor is called.
  tiles = t;
  snakes = s;
  ladders = l;
  penalty = p;
  reward = r;
  players = nP;
  action = 'C';
  turns = ts;
  turn = 0;
  options[0]= 'E';
  options[1]= 'C';

  for(int j=1; j<=players; j++){
    gamers[j].setPlayerNumber(j);
  }

  makeBoard();

}

//This is a simple method that validaes the entrys of the
//users by chechink if the element exists on a list.
void Manual::validateTurns(){
  cin >> action;
  //Converting to upper to avoid problems
  action = toupper(action);
  //SEARCH FOR THE ACTION INTO THE ARRAY WITH THE OPTIONS
  char* checkAction = find(begin(options),end(options),action);
  //UNTIL THE USER INTRODUCES A VALID OPTION, THE LOOP WILL STOP
  for (int i=0; i<5; i++){
    if (action=!options[0]||action=!options[1]){
      throw Exception("Invalid option, please press C to continue next turn or E to end the game");
    } else if (i==4){
      action = 'S';
      endGame(action);
    } if (action=='E') {
      endGame(action);
    }
  }
//  while (checkAction == end(options)) {
//    cout <<  << endl;
//    cin >> action;
//    action = toupper(action);
//    checkAction = find(begin(options),end(options),action);
//  }
  //IF THE USER INTRODUCES THE ACTION E, THEN THE GAME ENDS

}

//THIS METHOD MANAGE ALL THE GAME, BECAUSE IT CONNECTS WITH
//THE INFORMATION OF THE PLAYERS, AND INCREASE THE TURN BY 1
//EVERY ITERATION. Neither recieves parameters, nor returns anything.
void Manual::continueGame() {
  //VARIABLES
  string playerInformation = "";

  while (action=='C') {
    for (int g = 1; g<=gamers.size(); g++){
      //TURN +1
      turn+=1;
      //CALL THE METHOD OF THE CLASS PLAY()
      gamers[g].play(board, turn);
      //THE CONDITIONAL CHECKS IF THE GAME HAS ENDED
      if (gamers[g].getTile()>=tiles) {
        //IF A PLAYER WINS, THEN THE NUMBER OF THE PLAYER IS
        //DISPLAYED
        endGame(g);
      } else if (turn>=turns) {
        endGame(action);
      }
      //THE METHOD VALIDATES THE ENTRYS

      try
      {
        validateTurns();
      }

      catch( std::exception const& e)
      {
        std::cout << e.what() << '\n';
        repetir = true;
      }
    } while( repetir );

    }
  }
  //REPEATING THE PROCESS
}


//THIS FUNCTION CREATES THE BOARD, BY SAVING THE OBJECTS
//INTO A MAP, THEN, THE REWARDS OR PENALTYS ARE DEFINED.
void Manual::makeBoard(){
  //OBJETS DECLARATION
  Normal *N = new Normal();
  Ladder *L = new Ladder();
  Snake *S = new Snake();
  //OBJECT RANDOM TO DISTRIBUTE THE OBJECTS OVER THE BOARD
  Random randomTile;
  //RANDOM CHOISE VARIABLE
  int randomTileChoise=0;
  //VECTOR WITH TITLES ORDERED BY TYPE.
  vector <Tile*> possibleTiles;
  //OBJECTS ARE INTRODUCED INTO THE VECTOR
  for (int k=0; k<snakes; k++) {
    possibleTiles.push_back(S);
  }

  for (int l=snakes; l<ladders+snakes; l++) {
    possibleTiles.push_back(L);
  }

  for (int n=ladders+snakes; n<tiles; n++){
    possibleTiles.push_back(N);
  }

  //INITIAL VALUES ARE DECLEARED, THE LAST AND THE first
  //TILES HAVE TO BE NORMAL TILES.
  board[1] = N;
  board[1]->setTileNumber(0);
  board[tiles]= N;
  board[tiles]->setTileNumber(0);
  //THE RANDOM DISTRIBUTION IS MADE BY THIS LOOP
  for (int r=2; r<tiles; r++){
    //USING SETTERS, THE LIMITS OF THE RANDOM GENERATOR ARE
    //ESTABLISH
    randomTile.setLowerRange(0);
    randomTile.setUpperRange(tiles-r-1);
    //THE RANDOM NUMBER IS STORED IN A VARIABLE
    randomTileChoise = randomTile.Randomize();
    //NOW, THE OBJECTS ARE STORED IN THE MAP BY NUMBER
    board[r]=possibleTiles[randomTileChoise];
    //THIS CONDITIONAL SETS THE REWARD OR PENALTY BASED ON
    //THE SYMBOL
    if (board[r]->getSymbol()=='L') {
      board[r]->setTileNumber(reward);
    } else if (board[r]->getSymbol()=='S') {
      board[r]->setTileNumber(-penalty);
    } else{
      board[r]->setTileNumber(0);
    }
    //IN ORDER TO NO REPEAT THE OBJECTS ON THE BOARD, THESE
    //ELEMENTS ARE ERASED FROM THE VECTOR.
    possibleTiles.erase(possibleTiles.begin()+randomTileChoise);
    }

}

//THE METHOD IS USED TO PRINT THE FINAL MESSAGES BASED ON SOME
//CONDITIONS. THEN ENDS THE GAME. AS THIS METHOD IS A VOID FUNCTION
//IT DOESN'T RETURNS ANYTHING. IT IS BASED ON THE ACTION DONE.
void Manual::endGame(char action ) {
  cout << "-- GAME OVER --" << endl;
  //WHETER THE PLAYER ENDS THE GAME OR THE NUMBER OF TURNS IS REACHED,
  //THE CONDITIONAL PRINTS THE FINAL MESSAGES
  if (action=='E'||turn>=turns) {
    if (turn>=turns) {
      cout << "The maximum number of turns has been reached" << endl;
    }
    cout << "Thanks for playing!!!" << endl;
  } else if (action=='S'){
    cout << "Invalid menu choice exceeded" << endl;
  }
  //GAME OVER
  exit(1);
}

//THE METHOD IS USED TO PRINT THE FINAL MESSAGES BASED ON SOME
//CONDITIONS. THEN ENDS THE GAME. AS THIS METHOD IS A VOID FUNCTION
//IT DOESN'T RETURNS ANYTHING. iT IS BASED ON THE WINNER NUMBER.
void Manual::endGame(int winner ) {
  cout << "-- GAME OVER --" << endl;
  //THE PLAYER WINS
  cout << "Player " << winner << " is the winner!!!" << endl;

  //GAME OVER
  exit(1);
}


//THIS CLASS IS A DERIVATED CLASS FROM MANUAL, IT HAS THE
//SAME ATTRIBUTS, BUT HAS A OVERRIDE FUNCTION.
class Automatic : public Manual {
public:
  //CONSTRUCTORS
  Automatic();
  Automatic(int, int, int, int, int, int, int);
  //OVERRIDE METHOD
  void continueGame();

};
//CONSTRUCTOR
  Automatic::Automatic(){
}

//CONSTRUCTOR WITH PARAMETERS
Automatic::Automatic(int t, int s, int l, int p, int r, int nP, int ts){
  tiles = t;
  snakes = s;
  ladders = l;
  penalty = p;
  reward = r;
  players = nP;
  turns = ts;

  for(int j=1; j<=players; j++){
    gamers[j].setPlayerNumber(j);
  }

  makeBoard();

}

//THIS METHOD MANAGE ALL THE GAME, BECAUSE IT CONNECTS WITH
//THE INFORMATION OF THE PLAYERS, AND INCREASE THE TURN BY 1
//EVERY ITERATION. Neither recieves parameters, nor returns anything.
void Automatic::continueGame() {
  //VARIABLES
  string playerInformation = "";

  while (action=='C') {
    for (int g = 1; g<=gamers.size(); g++){
      turn+=1;
      //CALL THE METHOD OF THE CLASS PLAY()
      gamers[g].play(board, turn);
      //THE CONDITIONAL CHECKS IF THE GAME HAS END
      if (gamers[g].getTile()>=tiles) {
        endGame(g);
      } else if (turn>=turns) {
        endGame(action);
      }
      action = 'C';
    }
  }
  //REPEATING THE PROCESS
}
