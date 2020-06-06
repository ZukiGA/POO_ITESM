/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Movie.h
*/
#include <bits/stdc++.h>
#include "Video.h"


using namespace std;

class Movie : public Video{
public:
  Movie(int, string, string, string);
  Movie();
};

Movie::Movie(int id, string na, string gen, string dura){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
}
Movie::Movie(){

};
