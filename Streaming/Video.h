/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Video.hpp
*/
#include <bits/stdc++.h>


using namespace std;

class Video{
protected:
  int ID;
  string name, genre, duration;
public:
  Video(int, string, string, string);
};

Video::Video(int id, string na, string gen, string dura){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
}
