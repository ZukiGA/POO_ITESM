/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: StreamingMedia.hpp
*/

#include <bits/stdc++.h>
#include "Multimedia.hpp"
#include "SearchEngine.hpp"

using namespace std;

class StreamingMedia {
 	unordered_map <int, Multimedia> listOfContent;
public:
	StreamingMedia();
  ~StreamingMedia();
	void on();
	void off();
	int mainMenu();
	void loadInfo();
	void showSeries(int);
	void showMovies();
	void showEverything();
	void search();
  void scoring();

};

StreamingMedia::StreamingMedia(){

}

StreamingMedia::~StreamingMedia(){

}


void StreamingMedia::on(){
	int userChoose = 0;

	cout << "-------------WELCOME TO GeekXGeek-------------" << endl;

	userChoose = mainMenu();

	while (userChoose>0&&userChoose<7) {
		if (userChoose == 1) {
			//LOAD FUNCTION
			loadInfo();
		} else {
			if (userChoose == 2) {
				showEverything();
			} else {
				if (userChoose == 3) {
					showSeries(1);
				} else {
					if (userChoose == 4) {
						showMovies();
					} else {
						if (userChoose == 5) {
							search();
						} else {
							if (userChoose == 6) {
								scoring();
							}
						}
					}
				}
			}
		}
		userChoose = mainMenu();
	}

}

void StreamingMedia::off(){
	cout << endl << "---------------------------" << endl;
	cout << "We hope you have enjoyed GeekXGeek." << endl;
	cout << "Shutting down..." << endl;
}

int StreamingMedia::mainMenu(){
	string choose = "0";

	cout << endl << "-----MENU-----" << endl << "Choose one of the next options:" << endl << "1. Load file"
	<< endl << "2. Show all the content" << endl << "3. Show only series" << endl << "4. Show only movies"
	<< endl << "5. Filter a search (Score, Genre)" << endl << "6. Rate a video" << endl << "0. Exit" << endl;
  cin >> choose;
	unordered_set <string> options={"0","1","2","3","4","5","6"};
  SearchEngine Se;
  choose=Se.validateEntrys(options,choose);
  Se.~SearchEngine();
	return stoi(choose);
}

void StreamingMedia::loadInfo(){
	string fileName = "", line = "-1", numberID="";
	vector <string> compiled, f1, f2, f3, f4, f5, f6;
	int pastmp=0, numberOfMultimediaInFile = 0, g=0;


	cout << "What is the name of the file?" << endl;
	cin >> fileName;

	//If the user don"t add the .txt, this line appends it.
	size_t sIterador = fileName.find(".txt");

	if (sIterador == string::npos)
		fileName += ".txt";

	ifstream multimediaFile(fileName);

	if (multimediaFile.fail()) {

		cout << "Sorry, it appears the file doesn't exist." << endl;

	} else {

			while (getline(multimediaFile, line)) {

				//All the lines are saved, except the one which doesn"t have anything
				if (line.size()!=0)
						compiled.push_back(line);
				}

			//La primera línea indica el número de Multimedia que es utilizado para saber el número de veces que se va a repetir el
			//ordenamiento

			numberOfMultimediaInFile = stoi(compiled[0]);
		    f1.reserve(numberOfMultimediaInFile);
		    f2.reserve(numberOfMultimediaInFile);
		    f3.reserve(numberOfMultimediaInFile);
		    f4.reserve(numberOfMultimediaInFile);
		    f5.reserve(numberOfMultimediaInFile);

			for (int h=1; h<=numberOfMultimediaInFile; h++) {

        		f1.push_back(compiled[h]);
				f2.push_back(compiled[h+numberOfMultimediaInFile]);
				f3.push_back(compiled[h+numberOfMultimediaInFile*2]);
				f4.push_back(compiled[h+numberOfMultimediaInFile*3]);
				f5.push_back(compiled[h+numberOfMultimediaInFile*4]);
        		//cout << tmp << " "<< tmp2 <<" "<< tmp3 <<" "<< tmp4 <<" "<< tmp5 << endl;

        		if (f3[h-1]=="na"){

          			Serie *S = new Serie(stoi(f1[h-1]), f2[h-1], f4[h-1], stof(f5[h-1]));
          			Multimedia M(S);
          			pastmp = stoi(f1[h-1]);
          			listOfContent[pastmp] = M;
                delete S;
          			//cout << listOfContent[stoi(f1[h-1])].getSerie() << endl;;

        		} else if (f1.size()>2&&f1[h-2]==f1[h-1]){

					      g = g+1;
        		  	Episode *E = new Episode(f2[h-1], f3[h-1], f4[h-1], stof(f5[h-1]), stoi(compiled[g+numberOfMultimediaInFile*5]));
        		  	listOfContent[pastmp].saveEpisode(E);
                delete E;
        		  	//cout << listOfContent[stoi(f1[h-1])].getSerie().getEpisode();

        		} else {

		        	Movie *P = new Movie(stoi(f1[h-1]), f2[h-1], f3[h-1], f4[h-1], stof(f5[h-1]));
		        	Multimedia M(P);
		        	listOfContent[stoi(f1[h-1])] = M;
              delete P;
		        	//cout << listOfContent[stoi(f1[h-1])].getMovie() << endl;;

        		}

			}
        	//cout << f1.size() << f2.size() << f3.size() << f5.size();
			cout << "--- DATA LOADED ---" << endl;
	}

	multimediaFile.close();
}

void StreamingMedia::showSeries(int d){
	int b = 0;
	for (auto k : listOfContent){
		if (k.second.getMovie().getID()==0){
			b=b+1;
     	cout << "----------Serie " << b << "----------" << endl;
      cout << k.second.getSerie() << endl;
      if (d==1){
	      cout << "----------Episodes----------" << endl;
			  for (int r=0; r<k.second.getSerie().getEpisode().size(); r++)
				  cout << k.second.getSerie().getEpisode()[r] << endl;
        cout << "--------------------------" << endl << endl;
		  }
    }
	}
}

void StreamingMedia::showMovies(){
	int b = 0;
	for (auto k : listOfContent){
		if (k.second.getSerie().getID()==0){
			b = b+1;
      cout << "----------Movie " << b << "----------" << endl;
			cout << k.second.getMovie() << endl;
      cout << "--------------------------" << endl << endl;
		}

	}
}

void StreamingMedia::showEverything(){
	showMovies();
	showSeries(1);
}

void StreamingMedia::search(){
  if (listOfContent.size()>0){
    string filter = "", content = "", serieChosen = "", minimumScore = "";
  	SearchEngine filters(listOfContent);
    filters.searchBy();
    //filters.~SearchEngine();
  }else{
    cout << endl<<"Please, load a file" << endl;
  }

};

void StreamingMedia::scoring(){
  string option, n, rate;
  int val;
  if (listOfContent.size()>0){
    cout << "Choose one option: " << endl << "1. Rate a movie"
    << endl << "2. Rate an episode" << endl;
    cin >> option;
    unordered_set <string> op2={"1","2"};
    SearchEngine Se;
    option = Se.validateEntrys(op2,option);
    Se.~SearchEngine();
  } else{
    cout << endl<<"Please, load a file" << endl;
  }

  if (option =="1"){
    showMovies();
    cout << "Enter the ID of a movie: " << endl;
    cin >> n;
    unordered_set <string> op3;
    for (auto k : listOfContent){
      op3.insert(to_string(k.first));
    }
    SearchEngine Se;
    n = Se.validateEntrys(op3,n);
    Se.~SearchEngine();
    for (auto k : listOfContent){
      if (k.first==stoi(n))
        val = k.first;
    }

    if (listOfContent[val].getMovie().getID()==val){
      string test = "";
      cout << "Enter your rating (0-5): ";
      cin >> rate;
      SearchEngine Se;
      unordered_set <string> rates = {"0","1","2","3","4","5"};
      rate = Se.validateEntrys(rates,rate);
      Se.~SearchEngine();
      listOfContent[val].rateContent(rate);
      cout << "-------------DONE--------------" << endl;
      cout << listOfContent[val].getMovie() << endl;
      cout << "-------------------------------" << endl;
    } else{
      cout << "ID not found" << endl;
    }

  } else if (option == "2") {
    showSeries(0);
    cout << "Enter the ID of the serie: " << endl;
    cin >> n;
    unordered_set <string> op4;
    for (auto k : listOfContent){
      op4.insert(to_string(k.first));
    }
    SearchEngine Se;
    n = Se.validateEntrys(op4,n);
    Se.~SearchEngine();
    for (auto k : listOfContent){
      if (k.first==stoi(n))
        val = k.first;
    }
    if (listOfContent[val].getSerie().getID()==val){
        unordered_set <string> op5;
        for (int q=0; q<listOfContent[val].getSerie().getEpisode().size(); q++){
          op5.insert(listOfContent[val].getSerie().getEpisode()[q].getID());
          cout << listOfContent[val].getSerie().getEpisode()[q] << endl;
        }
        cout << "Enter the ID of the episode: " << endl;
        cin >> n;
        SearchEngine Se;
        n = Se.validateEntrys(op5,n);
        Se.~SearchEngine();
        int w=0;
        while (listOfContent[val].getSerie().getEpisode()[w].getID()!=n){
          w = w+1;
        }
        if (listOfContent[val].getSerie().getEpisode()[w].getID()==n){
          cout << "Enter your rating (0-5): ";
          cin >> rate;
          SearchEngine Se;
          unordered_set <string> rates = {"0","1","2","3","4","5"};
          rate = Se.validateEntrys(rates,rate);
          Se.~SearchEngine();
          listOfContent[val].rateContent(rate,w);
          cout << listOfContent[val].getSerie().getEpisode()[w].getScore();
          cout << "-------------DONE--------------" << endl;
          cout << listOfContent[val].getSerie().getEpisode()[w] << endl;
          cout << "-------------------------------" << endl;
        } else {
          cout << "ID not found" << endl;
        }
      }  else{
       cout << "ID not found" << endl;
      }
    }
}
