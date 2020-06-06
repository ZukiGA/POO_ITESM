/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Video.hpp
*/
#include <bits/stdc++.h>
#include "Time.h"

using namespace std;

class Video{
protected:
  long ID;
  string name, genre;
  Time duration;
public:
  Video(long, name, genre, duration);
};

Video::Video(long id, string na, string gen, Time dura){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
}
