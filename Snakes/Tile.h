/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 06/2/2020
File: Tile.h
*/

#include <bits/stdc++.h>

//TILE IS CLASS WHICH EMULATES A TILE ON A BOARD
class Tile {
protected:
  //ATTRIBUTS
  int tileNumber;
  char symbol;

public:
  //CONSTRUCTOR
  Tile();
  //SETTER
  void setTileNumber(int);
  //GETTER
  char getSymbol();
  int getTileNumber();
  //OPERATOR OVERLOADING
  Tile operator + (const Tile& tileNormal){
    Tile n;
    n.setTileNumber(this->tileNumber+tileNormal.tileNumber);
    return n;
  }
};
//CONSTRUCTOR
Tile::Tile(){
  tileNumber = 1;
}
//SETTER
void Tile::setTileNumber(int tiNum){
  tileNumber = tiNum;
}
//GETTER
char Tile::getSymbol(){
  return symbol;
}

int Tile::getTileNumber(){
  return tileNumber;
}

//SNAKE IS DERIVATED FROM TILE.
class Snake : public Tile{
public:
  //CONSTRUCTOR
  Snake(){
    symbol = 'S';
  }
};

//LADDER IS DERIVATED FROM TILE
class Ladder : public Tile{
public:
  //CONSTRUCTOR
  Ladder(){
    symbol = 'L';
  }
};

//NORMAL IS DERIVATED FROM TILE
class Normal : public Tile{
public:
  //CONSTRUCTOR
  Normal(){
    symbol = 'N';
  }
};
