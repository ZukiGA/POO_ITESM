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
  int getID();

};

Video::Video(int id, string na, string dura, string gen, int sc){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
  score = sc;
}

Video::Video(){
  ID = 0;
};

int Video::getID(){
  return ID;
}
