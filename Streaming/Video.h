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
  int ID;
  float score;
  string name, duration, genre;
public:
  Video(int, string, string, string, float);
  Video();
  void setScore(float);
  int getID();
  int getScore();
  string getGenre();
  string getName();
  virtual void rate(float)=0;
  friend ostream& operator <<(ostream& os, const Video& v){
    os << "ID: " << v.ID << endl << "Title: " << v.name << endl
    << "Genre: " << v.genre << endl << "Duration: " << v.duration
    << endl << "Score: " << v.score << endl;
  }
};

Video::Video(int id, string na, string dura, string gen, float sc){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
  score = sc;
}

Video::Video(){
  ID = 0;
};

void Video::setScore(float s){
  score = s;
}

int Video::getID(){
  return ID;
}

int Video::getScore(){
  return score;
}

string Video::getGenre(){
  return genre;
}

string Video::getName(){
  return name;
}
