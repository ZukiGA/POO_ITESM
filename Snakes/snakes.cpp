/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/24/2020
File: snakes.cpp
*/
#include <bits/stdc++.h>
#include "GameTypes.hpp"

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

//This method initialize the game by checking if the action of the user
//is continuing the game or ending the game. It is a void method, so it
//neither receives parameters nor returns something;
void MyGame::start() {
  //INSTRUCTIONS
  cout << "Press C to start the game; O to open the settings, or E to end the game: " << endl;
  cin >> action;
  //Converting to upper to avoid problems
  action = toupper(action);
  //SEARCH FOR THE ACTION INTO THE ARRAY WITH THE OPTIONS
  char* checkAction = find(begin(options),end(options),action);
  //UNTIL THE USER INTRODUCES A VALID OPTION, THE LOOP WILL STOP
  while (checkAction == end(options)) {
    cout << "Invalid option, please press C to continue next turn or E to end the game" << endl;
    cin >> action;
    action = toupper(action);
    checkAction = find(begin(options),end(options),action);
  }

  Manual M;
  //BASED ON THE ACTION, THE GAME CONTINUES OR ENDS
  if (action == 'C'){
    M.continueGame();
  } else if (action=='E') {
    M.endGame(action);
    //THIS OPEN THE OPTIONS TO SET THE GAME
  }else if (action == 'O'){
    main();
  }
}

//This metod parametricize the game by asking for
//specific data.
void MyGame::main(){
  int tiles, snakes, ladders, penalty, reward, players, turns;
  cout << "Enter the number of tiles on the board: ";
  cin >> tiles;

  cout << "Enter the number of snakes: ";
  cin >> snakes;
  cout << "Enter the number of ladders: ";
  cin >> ladders;
  cout << "How many tiles a player must go back when falling in a serpent?  ";
  cin >> penalty;
  cout << "How many additional tiles a player must go on when falling in a ladder? ";
  cin >> reward;
  cout << "Number of players: ";
  cin >> players;

  cout << "Number of turns: ";
  cin >> turns;
  cout << "Game Type (A for automatic or M for manual): " << endl;
  cin >> gameType;
  gameType = toupper(gameType);
  //SEARCH FOR THE TYPE INTO THE ARRAY WITH THE OPTIONS
  char* checkGameType = find(begin(gameTypeOptions),end(gameTypeOptions),gameType);
  //UNTIL THE USER INTRODUCES A VALID OPTION, THE LOOP WILL STOP
  while (checkGameType == end(gameTypeOptions)) {
    cout << "Invalid option, please press A for automatic or M for manual mode" << endl;
    cin >> gameType;
    gameType = toupper(gameType);
    checkGameType = find(begin(gameTypeOptions),end(gameTypeOptions),gameType);
  }
  //THE GAMEMODE IS OPEN BY THIS LINES OF CODE.
  if (gameType=='A') {
    //INITIALIZE AUTOMATIC MODE
    Automatic A(tiles, snakes, ladders, penalty, reward, players, turns);
    A.continueGame();
  } else if (gameType='M'){
    //INITIALIZE MANUAL MODE
    Manual M(tiles, snakes, ladders, penalty, reward, players, turns);
    M.continueGame();
  }
}


//MAIN
int main() {
  //GAME
  MyGame g;
  //THE GAME STARTS
  g.start();

  return 0;
}
