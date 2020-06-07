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
private:
  int ID;
  float score;
  string name, duration, genre;
  vector <Episode> episodes;
public:
  Serie();
  Serie(int id, string na, string gen, float sc);
  void setEpisode(Episode*);
  int getID();
  vector <Episode> getEpisode();
  friend ostream& operator <<(ostream& os, const Serie& s);
};

Serie::Serie(){
  ID = 0;
};

Serie::Serie(int id, string na, string gen, float sc){
  ID = id;
  name = na;
  genre = gen;
  score = sc;
  duration = "";
};

void Serie::setEpisode(Episode *E){
  E->setID(ID);
  E->setGenre(genre);
  episodes.push_back(*E);
}
vector <Episode> Serie::getEpisode(){
  return episodes;
}

int Serie::getID(){
  return ID;
}

ostream& operator<<(ostream& os, const Serie& s) {
  os << "ID: " << s.ID << endl << "Name: " << s.name << endl
  << "Genre: " << s.genre << endl << "Duration: " << s.duration
  << endl << "Score: " << s.score << endl;

}
