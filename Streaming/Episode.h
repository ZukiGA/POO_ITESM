/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Episode.h
*/
#include <bits/stdc++.h>



using namespace std;

class Episode : public Video{
private:
  int season;
  string IDChapter;
public:
  Episode(string, string, string, int, int);
  Episode();
  friend ostream& operator <<(ostream& os, const Episode& e);
};

Episode::Episode(string id, string na, string dura, int sc, int tp){
  IDChapter = id;
  name = na;
  duration = dura;
  score = sc;
  season = tp;
}
Episode::Episode(){
  ID = 0;
};

ostream& operator<<(ostream& os, const Episode& e) {
  os << "ID: " << e.IDChapter << endl << "Name: " << e.name << endl
  << "Duration: " << e.duration << endl << "Season: " << e.season
  << endl << "Score: " << e.score << endl;

}
