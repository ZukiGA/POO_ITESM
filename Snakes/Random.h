/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 05/24/2020
Last modification date: 05/24/2020
File: Random.h
*/

#include <bits/stdc++.h>
#include <random>

using namespace std;

//CLASS RANDOM IS USED IN MANY PROCESESS
class Random{
private:
  //ATTRIBUTS
  int lowerRange, upperRange;
public:
  //RANDOM CONSTRUCTOR
  Random();
  //SETTER
  void setLowerRange(int);
  void setUpperRange(int);
  //METHOD
  int Randomize();
};
//CONSTRUCTOR
Random::Random(){
  lowerRange = 0;
  upperRange = 2;
}
//SETTERS
void Random::setLowerRange(int limitSent){
  lowerRange = limitSent;
}

void Random::setUpperRange(int limitSent2){
  upperRange = limitSent2;
}
//THIS METHOD RANDOMIZE A RANGE OF NUMBERS.
int Random::Randomize(){
  //Random device
  random_device randomNumber;
  //PROCESS
  mt19937 generator(randomNumber());
  uniform_int_distribution <> range(0,20);
  //THE POSSIBLE NUMBERS ARE BETWEEN THE LOWER AND UPPER RANGE
  uniform_int_distribution <> establishRange(lowerRange,upperRange);
  uniform_real_distribution <float> Range(floor(range(generator)),ceil(range(generator)));
  //HERE A NUMBER IS GENERATED
  return establishRange(generator);
}
