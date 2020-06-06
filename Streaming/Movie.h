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
  Movie(int, string, string, string, int);
  Movie();
  friend ostream& operator <<(ostream& os, const Movie& v);
};

Movie::Movie(int id, string na, string dura, string gen, int sc){
  ID = id;
  name = na;
  genre = gen;
  duration = dura;
  score = sc;
}
Movie::Movie(){
  ID = 0;
};

ostream& operator<<(ostream& os, const Movie& v) {
  os << "ID: " << v.ID << endl << "Name: " << v.name << endl
  << "Genre: " << v.genre << endl << "Duration: " << v.duration
  << endl << "Score: " << v.score << endl;

}
