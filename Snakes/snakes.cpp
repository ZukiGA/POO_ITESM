/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/24/2020
File: snakes.cpp
*/
#include <bits/stdc++.h>
#include "GameTypes.hpp"
#include "InvalidConfigurationException.h"

using namespace std;
//This is the main class of the game.
class MyGame {
private:
  //ATTRIBUTS
  char options[3];
  char action, gameType;
  char gameTypeOptions[2];
public:
  //CONSTRUCTOR
  MyGame();
  //METHODS
  void start();
  void main();
  int validateIntegers(string, int);
};
//CONSTRUCTOR
MyGame::MyGame() {
    action = 'C';
    options[0]= 'E';
    options[1]= 'C';
    options[2]= 'O';
    gameTypeOptions[0] = 'A';
    gameTypeOptions[1] = 'M';
    gameType = 'M';
}

//METHOD THAT CALLS TO THE CLASS EXCEPTION. PARAMETERS ARE
//VARIABLE AND LIMIT VALUE
int MyGame::validateIntegers(string str, int limit  ){
  int val = 2;
  bool check = false;
  cin.exceptions(istream::failbit);
  do {
    check = false;
    try {
      cin >> val;

      if (val>1&&val<limit){
        return val;
      } else {
        throw InvalidConfigurationException(str, val);
      }

    }
    catch (std::exception const &e){
      cout <<e.what() << endl;;
      check = true;
      exit(1);
    }
  } while (check);
}
//This method initialize the game by checking if the action of the user
//is continuing the game or ending the game. It is a void method, so it
//neither receives parameters nor returns something;
void MyGame::start() {
  //VARIABLES
  bool check = false;
  Manual M;
  int i = 0;
  //INSTRUCTIONS

  cout << "Press C to start the game; O to open the settings, or E to end the game: " << endl;

  do {

    check = false;

    try {

      cin >> action;
      //Converting to upper to avoid problems
      action = toupper(action);

      //BASED ON THE ACTION, THE GAME CONTINUES OR ENDS
      if (action == 'C'){
        M.continueGame();
      } else if (action=='E') {
        M.endGame(action);
        //THIS OPEN THE OPTIONS TO SET THE GAME
      } else if (action == 'O'){
        main();
      } else {
        i = i+1;
        throw InvalidOptionException("Invalid option, please press C to continue next turn, O to options or E to end the game");
      }
    }
    catch ( std::exception const& e) {
      cout << e.what() << endl;
      check = true;
      if (i == 5)
        check = false;
    }
  } while (check);

  M.endGame('F');
}

//This metod parametricize the game by asking for
//specific data.
void MyGame::main(){

  bool check = false;
  int i = 0;
  int tiles, snakes, ladders, penalty, reward, players, turns;
  Manual m;

  cout << "Enter the number of tiles on the board: ";
  tiles = validateIntegers("tiles",1000);
  cout << "Enter the number of snakes: ";
  snakes = validateIntegers("snakes",tiles);
  cout << "Enter the number of ladders: ";
  ladders = validateIntegers("ladders",tiles-snakes);
  cout << "How many tiles a player must go back when falling in a snake?  ";
  penalty = validateIntegers("penalty",tiles);
  cout << "How many additional tiles a player must go on when falling in a ladder? ";
  reward = validateIntegers("reward",tiles);
  cout << "Number of players: ";
  players = validateIntegers("players", 100);

  cout << "Number of turns: ";
  turns = validateIntegers("turns",10000);
  cout << "Game Type (A for automatic or M for manual): " << endl;

  //EXCEPTION HANDLE
  do {
    check = false;

    try {

      cin >> gameType;
      gameType = toupper(gameType);

      //THE GAMEMODE IS OPEN BY THIS LINES OF CODE.
      if (gameType=='A') {
        //INITIALIZE AUTOMATIC MODE
        Automatic A(tiles, snakes, ladders, penalty, reward, players, turns);
        A.continueGame();

      } else if (gameType='M'){
        //INITIALIZE MANUAL MODE
        Manual M(tiles, snakes, ladders, penalty, reward, players, turns);
        M.continueGame();

      } else {
        i = i+1;
        throw InvalidOptionException("Invalid option, please press A for automatic or M for manual mode");
      }
    }
    catch ( std::exception const& e) {
      cout << e.what() << endl;
      check = true;
      if (i == 5)
        m.endGame('F');
    }
  } while (check);
}


//MAIN
int main() {
  //GAME
  MyGame g;
  //THE GAME STARTS
  g.start();

  return 0;
}
