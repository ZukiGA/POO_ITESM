/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Episode.h
*/
#include <bits/stdc++.h>
#include "Video.h"
#include "Serie.h"


using namespace std;

class Episode : public Video{
public:
  Episode(int, string, string, string);
  Episode();
};

Episode::Episode(int id, string na, string gen, string dura){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
}
Episode::Episode(){

};
