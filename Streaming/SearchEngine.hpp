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
private:
  unordered_map <int, Multimedia> catalogue;
public:
  SearchEngine(unordered_map <int, Multimedia>);
  ~SearchEngine();
  void searchBy();
  void sort(string, string);
  void call(float, string);
  void call(string, string);
  vector <Video*> searchMovie();
  vector <Video*> searchEpisode();
  vector <Video*> searchEpisode(string);
  vector <Video*>  searchVideo();
  void searchByGenre(vector <Video*>, string);
  void searchByScore(vector <Video*>, float);
};


SearchEngine::SearchEngine(unordered_map <int, Multimedia> lis){
  catalogue = lis;
}
SearchEngine::~SearchEngine(){

}

void SearchEngine::searchBy(){
  string filter = "", genre = "", minimumScore = "";
  cout << "Choose a filter:" << endl << "1. Minimum score"
  << endl << "2. Genre" << endl;
  cin >> filter;
  if (filter=="1"){
    cout << "Enter the minimum score: ";
    cin >>  minimumScore;
    sort(filter, minimumScore);
  } else {
    cout << "Enter the genre: ";
    cin >> genre;
    sort(filter, genre);
  }
}

void SearchEngine::sort(string filter,string value){
  string content = "";
  cout << "Kind of content:" << endl << "1. Movies"
  << endl << "2. Episodes of a serie" << endl << "3. All" << endl;
  cin >> content;
  if (filter=="1"){
    call(stof(value),content);
  } else {
    call(value,content);
  }
}

void SearchEngine::call(float v, string c){
  vector <Video*> vec;
  string number = "";
  if (c=="1"){
    vec=searchMovie();
  } else if (c=="2"){
    int b = 0;
    for (auto k : catalogue){
  		if (k.second.getMovie().getID()==0){
        b = b+1;
       	cout << "----------Serie " << b << "----------" << endl;
  			cout << k.second.getSerie() << endl;
      }
    }
    cout << "Enter the number of the serie: ";
    cin >> number;
    vec=searchEpisode(number);
  } else {
    vec=searchVideo();
  }
  searchByScore(vec,v);
}

void SearchEngine::call(string v, string c){
  vector <Video*> vec;
  if (c=="1"){
    vec=searchMovie();
  } else if (c=="2"){
    vec=searchEpisode();
  } else {
    vec=searchVideo();
  }
  searchByGenre(vec,v);
}

vector <Video*> SearchEngine::searchMovie(){
  vector<Video*> newList;
  for (auto k : catalogue){
    if (k.second.getSerie().getID()==0){
      newList.push_back(k.second.getMovie().getThis());
    }
  }
  return newList;
}

vector <Video*> SearchEngine::searchEpisode(){
  vector <Video*> newList;
  for (auto k : catalogue){
    if (k.second.getMovie().getID()==0){
      for (int r=0; r<k.second.getSerie().getEpisode().size(); r++)
        newList.push_back(&k.second.getSerie().getEpisode()[r]);
    }
  }
  return newList;
}

vector <Video*> SearchEngine::searchEpisode(string n){
  vector <Video*> newList;
  int b = 0;
  for (auto k : catalogue){
    if (k.second.getMovie().getID()==0){
      b = b+1;
      if (b==stoi(n)){
        for (int r=0; r<k.second.getSerie().getEpisode().size(); r++)
          newList.push_back(&k.second.getSerie().getEpisode()[r]);
      }
    }
  }
  return newList;
}

vector <Video*> SearchEngine::searchVideo(){
  vector <Video*> newList = searchMovie();
  vector <Video*> tmp = searchEpisode();
  newList.insert(newList.end(), begin(tmp), end(tmp));
  return newList;
}


void SearchEngine::searchByGenre(vector <Video*> vec, string s){
  cout << "--------RESULTS----------" << endl;
  for (int u=0; u<vec.size(); u++) {
    if (vec[u]->getGenre()==s)
      cout << *vec[u] << endl;
  }
  cout << "--------------------------" << endl << endl;
}

void SearchEngine::searchByScore(vector <Video*> vec, float s){
  cout << "--------RESULTS----------" << endl;
  for (int u=0; u<vec.size(); u++) {
    if (vec[u]->getScore()>=s)
      cout << *vec[u] << endl;
  }
  cout << "--------------------------" << endl << endl;
}
