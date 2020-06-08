/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 06/02/2020
Last modification date: 06/02/2020
File: Turn.h
*/

#include <bits/stdc++.h>

class Turn{
  //ATTRIBUTS
  int turno, playerNumber, tile, diceNumber, finalTileValue;
  char symbolTile;
public:
  //CONSTRUCTOR
  Turn(int tu, int pN, int ti, int dN, char sT, int fT){
    turno = tu; playerNumber = pN; tile = ti; diceNumber = dN;
    symbolTile = sT; finalTileValue = fT;
  }
  //OPERATOR OVERLOADING
  friend ostream& operator <<(ostream& os, const Turn& tn);
};

//OPERATOR <<
ostream& operator<<(ostream& os, const Turn& tn) {
  os << tn.turno << ' ' << tn.playerNumber << ' ' << tn.tile << ' ' << tn.diceNumber << ' ' << tn.symbolTile << ' ' << tn.finalTileValue;
}
