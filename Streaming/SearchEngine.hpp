/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: SearchEngine.hpp
*/
#include <bits/stdc++.h>
using namespace std;

class SearchEngine {

public:
  SearchEngine();
  void searchBy(string, unordered_map <int, Multimedia>, string);
  void searchBy(string, string, unordered_map <int,Multimedia> );
  void searchMovie(unordered_map <int, Multimedia>);
  void searchSerie();
  void searchEpisode();
  void searchByGenre();
  void searchByScore();
};


SearchEngine::SearchEngine(){
}

void SearchEngine::searchBy(string filter, unordered_map <int, Multimedia> catalogue, string serieChosen){

  if (filter=="1"){
    searchByScore();
  } else {
    searchByGenre();
  }

  searchEpisode();
}

void SearchEngine::searchBy(string filter, string content, unordered_map <int,Multimedia> catalogue ){
  vector <Movie> v;
  vector <Serie> m;
  if (content=="3"){
    m=searchSerie(catalogue);
    v=searchMovie(catalogue);
  } else {

    v=searchMovie(catalogue);
  }

  if (filter=="1"){
    searchByScore();
  } else {
    searchByGenre();
  }
}

vector <Movie> SearchEngine::searchMovie(unordered_map <int, Multimedia> catalogue){
  vector<Movie> newList;
  for (auto k : catalogue){
    if (k.second.getSerie().getID()==0){
      newlist.push_back(k.second.getMovie());
    }
  }
  return newList;
}

vector <Serie> SearchEngine::searchSerie(unordered_map <int, Multimedia> catalogue){
  vector <Serie> newList;
  for (auto k : catalogue){
    if (k.second.getMovie().getID()==0){
      newlist.push_back(k.second.getSerie());
    }
  }
  return newList;
}

void  SearchEngine::searchEpisode(){
  //int j=0;
  //vector <Episode> newList = searchSerie();
  //for (auto & k : newList){
  //  j=j+1;
  //  if (j==stoi(episodeID)){
  //    ;
  //  }
  //}
}

void SearchEngine::searchByGenre(){

}

void SearchEngine::searchByScore(){

}
