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
  int temporada;
  string IDChapter;
public:
  Episode(string, string, string, int, int);
  Episode();
};

Episode::Episode(string id, string na, string dura, int sc, int tp){
  IDChapter = id;
  name = na;
  duration = dura;
  score = sc;
  temporada = t
}
Episode::Episode(){

};
