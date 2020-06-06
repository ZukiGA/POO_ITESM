/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Video.h
*/
#include <bits/stdc++.h>



using namespace std;

class Video {
protected:
  int ID, score;
  string name, duration, genre;
public:
  Video(int, string, string, string, int);
  Video();
  friend ostream& operator <<(ostream& os, const Video& v);
};

Video::Video(int id, string na, string dura, string gen, int sc){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
  score = sc;
}

Video::Video(){

};
ostream& operator<<(ostream& os, const Video& v) {
  os << "ID: " << v.ID << endl << "Name: " << v.name << endl
  << "Genre: " << v.genre << endl << "Duration: " << v.duration
  << endl << "Score: " << v.score << endl;

}
