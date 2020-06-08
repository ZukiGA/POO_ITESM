/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 08/04/20
File: SearchEngine.hpp
*/
#include <bits/stdc++.h>

using namespace std;
//CLASS
class SearchEngine {
private:
  unordered_map <int, Multimedia> catalogue;
public:
  SearchEngine();
  SearchEngine(unordered_map <int, Multimedia>);
  ~SearchEngine();
  void searchBy();
  void sort(string, string);
  void call(float, string);
  void call(string, string);
  string validateEntrys(unordered_set <string>, string);
  bool isFloat(string);
};

SearchEngine::SearchEngine(){
}
SearchEngine::SearchEngine(unordered_map <int, Multimedia> lis){
  catalogue = lis;
}
SearchEngine::~SearchEngine(){

}

string SearchEngine::validateEntrys(unordered_set <string>options, string str){
  //SEARCH FOR THE ACTION INTO THE ARRAY WITH THE OPTIONS
  unordered_set <string>::iterator check = options.find(str);
  //UNTIL THE USER INTRODUCES A VALID OPTION, THE LOOP WILL STOP
  while (check == options.end()) {
    cout << "Invalid option. Choose one valid option." << endl;
    getline(cin,str);
    check = find(begin(options),end(options),str);
  }
  return str;
}



void SearchEngine::searchBy(){
  string filter = "", genre = "", minimumScore = "";
  cout << "Choose a filter:" << endl << "1. Minimum score"
  << endl << "2. Genre" << endl;
  cin >> filter;
  unordered_set <string> op6={"1","2"};
  filter = validateEntrys(op6,filter);
  if (filter=="1"){
    cout << "Enter the minimum score(0-5): ";
    cin >>  minimumScore;
    unordered_set <string> op9={"0","1","2","3","4","5"};
    minimumScore = validateEntrys(op9,minimumScore);
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
  unordered_set <string> op7={"1","2", "3"};
  content = validateEntrys(op7,content);
  if (filter=="1"){
    call(stof(value),content);
  } else {
    call(value,content);
  }
}

void SearchEngine::call(float v, string c){

  string number = "";
  if (c=="1"){
    for (auto k : catalogue) {
      if (k.second.getMovie().getScore()>=v)
        cout << k.second.getMovie() << endl;
    }
  } else if (c=="2"){
    int b = 0;
    for (auto k : catalogue){
  		if (k.second.getMovie().getID()==0){
        b = b+1;
       	cout << "----------Serie " << b << "----------" << endl;
  			cout << k.second.getSerie() << endl;
      }
    }
    cout << "Enter the ID of the serie: ";
    cin >> number;
    int val =0;
    unordered_set <string> op8;
    for (auto k : catalogue){
      op8.insert(to_string(k.first));
    }
    number = validateEntrys(op8,number);
    for (auto k : catalogue){
      if (k.first==stoi(number))
        val = k.first;
    }
    if (catalogue[val].getSerie().getID()==val){
        for (int q=0; q<catalogue[val].getSerie().getEpisode().size(); q++){
          if (catalogue[val].getSerie().getEpisode()[q].getScore()>=v)
            cout << catalogue[val].getSerie().getEpisode()[q] << endl;
        }
      }  else{
       cout << "ID not found" << endl;
      }
  } else {
    for (auto k : catalogue) {
      if (k.second.getSerie().getID()==0&&k.second.getMovie().getScore()>=v){
        cout << k.second.getMovie() << endl;
      } else if (k.second.getMovie().getID()==0){
        for (int f=0; f<k.second.getSerie().getEpisode().size(); f++){
          if (k.second.getSerie().getEpisode()[f].getScore()>=v)
            cout << k.second.getSerie().getEpisode()[f];
        }
      }
    }
  }
}

void SearchEngine::call(string v, string c){
  string number = "";
  if (c=="1"){
    for (auto k : catalogue) {
      if (k.second.getMovie().getGenre()==v)
        cout << endl << k.second.getMovie() << endl;
    }
  } else if (c=="2"){
    int b = 0;
    for (auto k : catalogue){
  		if (k.second.getMovie().getID()==0){
        b = b+1;
       	cout << "----------Serie " << b << "----------" << endl;
  			cout <<endl<< k.second.getSerie() << endl;
      }
    }
    cout << "Enter the ID of the serie: ";
    cin >> number;
    unordered_set <string> op9;
    for (auto k : catalogue){
      op9.insert(to_string(k.first));
    }
    number = validateEntrys(op9,number);
    int val =0;
    for (auto k : catalogue){
      if (k.first==stoi(number))
        val = k.first;
    }
    if (catalogue[val].getSerie().getID()==stoi(number)){
        for (int q=0; q<catalogue[val].getSerie().getEpisode().size(); q++){
          if (catalogue[val].getSerie().getEpisode()[q].getGenre()==v)
            cout << catalogue[val].getSerie().getEpisode()[q] << endl;
        }
      }  else{
       cout << "ID not found" << endl;
      }
  } else {
    for (auto k : catalogue) {
      if (k.second.getSerie().getID()==0&&k.second.getMovie().getGenre()==v){
        cout << "----------Movie ----------" << endl;
        cout << endl << k.second.getMovie() << endl;
      } else if (k.second.getMovie().getID()==0){
        for (int f=0; f<k.second.getSerie().getEpisode().size(); f++){
          if (k.second.getSerie().getEpisode()[f].getGenre()==v){
            cout << "----------Episode----------" << endl;
            cout << endl << k.second.getSerie().getEpisode()[f] << endl;
          }

        }
      }
    }
  }
}
