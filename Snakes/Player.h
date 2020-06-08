/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/24/2020
File: Player.h
*/
#include <bits/stdc++.h>
#include "Dice.h"
#include "Tile.h"
#include "Turn.hpp"

//Class Player manages the action of every player.
class Player {
private:
  //ATTRIBUTS
  int playerNumber, tile;
  Dice myDice;
public:
  //CONSTRUCTOR
  Player() {
    playerNumber = 1;
    tile = 1;
  }
  //SETTER
  void setPlayerNumber(int);
  int getTile();
  void play(unordered_map<int,Tile*>, int);

};

//SETTERS
void Player::setPlayerNumber(int playerNumb){
  playerNumber = playerNumb;
}

//GETTERS
int Player::getTile(){
  return tile;
}
//This method allows a player to throw the dice in order to move
//on the board, then it evaluates the tile in which the player
//falls, it could be a ladder (L), serpent (S) or a normal one (N).
//Finally, it returns the a string with the information about the
//player. It receive the board.
void Player::play(unordered_map<int,Tile*> boardPlaying, int turnPlaying){
  //VARIABLES
  int diceNumber = 0, move = 0;
  string info = "";
  char symbolTile = '0';
  Tile newTile, finalTile;
  //THROWING THE DICE
  diceNumber = myDice.roll();
  //MOVING ON THE BOARD
  newTile.setTileNumber(tile + diceNumber);
  //ADJUST THE POSITION
  if (newTile.getTileNumber()>=boardPlaying.size()) {
    newTile.setTileNumber(boardPlaying.size());
  }
  //DETERMINES THE MOVEMENT OF A PLAYER BY CHECKING THE TILE IN WHICH IT FALLS
  finalTile = newTile+*boardPlaying[newTile.getTileNumber()];
  //ADJUST THE POSITION
  if(finalTile.getTileNumber()<=0){
    finalTile.setTileNumber(1);
  } else if (finalTile.getTileNumber()>=boardPlaying.size()) {
    finalTile.setTileNumber(boardPlaying.size());
  }

  //STORE THE INFO ON A VARIABLE
  symbolTile=boardPlaying[newTile.getTileNumber()]->getSymbol();
  //Print the information
  Turn actualTurn(turnPlaying, playerNumber, tile, diceNumber, symbolTile, finalTile.getTileNumber());
  cout << actualTurn << endl;
  //RELOAD THE VALUE OF THE TILE IN WHICH THE PLAYER IS
  tile = finalTile.getTileNumber();

}
