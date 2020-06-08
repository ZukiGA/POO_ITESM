/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/24/2020
File: Dice.h
*/
#include <bits/stdc++.h>
#include "Random.h"

using namespace std;

class Dice{
  //Initial values
private:
  //Attributs
  int dice;
public:
  //Constructor
  Dice() {
    dice = 0;
  }

  //Methods
  int roll() {
    //HERE A NUMBER IS GENERATED
    Random randomDice;
    randomDice.setUpperRange(6);
    randomDice.setLowerRange(1);
    dice = randomDice.Randomize();

    return dice;
  }

};
