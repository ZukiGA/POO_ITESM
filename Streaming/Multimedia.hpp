/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Multimedia.hpp
*/

#include <bits/stdc++.h>
#include "Video.h"
#include "Serie.h"
#include "Movie.h"


class Multimedia {
private:
  Movie M;
  Serie S;

public:
  Multimedia();
  Multimedia(Movie*);
  Multimedia(Serie*);
  void saveEpisode(Episode*);
};
Multimedia::Multimedia(){

}
Multimedia::Multimedia(Movie * m){
  M = *m;
};
Multimedia::Multimedia(Serie * s){
  S = *s;
};
void Multimedia::saveEpisode(Episode * e){
  S.setEpisode(e);
}
