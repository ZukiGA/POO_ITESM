/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Video.h
*/
#include <bits/stdc++.h>
#include "Multimedia.hpp"


using namespace std;

class Video : public Multimedia{
protected:
  int ID;
  string name, genre, duration;
public:
  Video(int, string, string, string);
  Video();
};

Video::Video(int id, string na, string gen, string dura){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
}

Video::Video(){

};
