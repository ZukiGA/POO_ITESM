/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Serie.h
*/
#include <bits/stdc++.h>

#include "Episode.h"


using namespace std;

class Serie{
  int ID, score;
  string name, duration, genre;
  Episode e;
public:
  Serie();
  Serie(int id, string na, string gen, int sc);
  void setEpisode(Episode*);
};

Serie::Serie(){

};

Serie::Serie(int id, string na, string gen, int sc){
  ID = id;
  name = na;
  genre = gen;
  score = sc;
};

void Serie::setEpisode(Episode *E){
  e = *E;
}
