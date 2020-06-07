/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Movie.h
*/
#include <bits/stdc++.h>



using namespace std;

class Movie : public Video{
public:
  Movie(int, string, string, string, float);
  Movie();

};

Movie::Movie(int id, string na, string dura, string gen, float sc){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
  score = sc;
}
Movie::Movie(){
  ID = 0;
};
