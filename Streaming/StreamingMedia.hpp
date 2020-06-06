/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: StreamingMedia.hpp
*/

#include <bits/stdc++.h>
#include "SearchEngine.hpp"
#include "Multimedia.hpp"





using namespace std;

class StreamingMedia {
 	unordered_map <int, Multimedia> listOfContent;
public:
	StreamingMedia();
	void on();
	void off();
	int mainMenu();
	void loadInfo();
	void showEverything();
};

StreamingMedia::StreamingMedia(){
}

void StreamingMedia::on(){
	int userChoose = 0;

	cout << "WELCOME" << endl;

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
					//SHOW SERIES;
				} else {
					if (userChoose == 4) {
						//SHOW MOVIES;
					} else {
						if (userChoose == 5) {
							//FILTERS;
						} else {
							if (userChoose == 6) {
								//RATE;
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
	cout << "Turning off..." << endl;
}

int StreamingMedia::mainMenu(){
	int choose = 0;

	cout << endl << "-----MENU-----" << endl << "Choose one of the next options:" << endl << "1. Load file"
	<< endl << "2. Show me all the Multimedia" << endl << "3. Show me series" << endl << "4. Show me movies"
	<< endl << "5. Filter your search (Score, Genre)" << endl << "6. Rate a video" << endl << "0. Exit" << endl;

	cin >> choose;

	return choose;
}

void StreamingMedia::loadInfo(){
	string fileName = "", line = "-1", numberID="";
	vector <string> compiled, f1, f2, f3, f4, f5, f6;
	int pastmp=0, numberOfMultimediaInFile = 0, g=0;


	cout << "What is the name of the file?" << endl;
	cin >> fileName;

	//If the user don't add the .txt, this line appends it.
	size_t sIterador = fileName.find(".txt");

	if (sIterador == string::npos)
		fileName += ".txt";

	ifstream multimediaFile(fileName);

	if (multimediaFile.fail()) {

		cout << "Sorry, it appears the file doesn't exist." << endl;

	} else {

			while (getline(multimediaFile, line)) {

				//All the lines are saved, except the one which doesn't have anything
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

          			Serie *S = new Serie(stoi(f1[h-1]), f2[h-1], f4[h-1], stoi(f5[h-1]));
          			Multimedia M(S);
          			pastmp = stoi(f1[h-1]);
          			listOfContent[pastmp] = M;

          			//cout << listOfContent[stoi(f1[h-1])].getSerie() << endl;;

        		} else if (f1.size()>2&&f1[h-2]==f1[h-1]){

					      g = g+1;
        		  	Episode *E = new Episode(f2[h-1], f3[h-1], f4[h-1], stoi(f5[h-1]), stoi(compiled[g+numberOfMultimediaInFile*5]));
        		  	listOfContent[pastmp].saveEpisode(E);
        		  	//cout << listOfContent[stoi(f1[h-1])].getSerie().getEpisode();

        		} else {

		        	Movie *P = new Movie(stoi(f1[h-1]), f2[h-1], f3[h-1], f4[h-1], stoi(f5[h-1]));
		        	Multimedia M(P);
		        	listOfContent[stoi(f1[h-1])] = M;
		        	//cout << listOfContent[stoi(f1[h-1])].getMovie() << endl;;

        		}

			}

        	//cout << f1.size() << f2.size() << f3.size() << f5.size();
			cout << "--- DATA LOADED ---" << endl;
	}

	multimediaFile.close();
}

void StreamingMedia::showEverything(){
	for (auto k : listOfContent){
		if (k.second.getSerie().getID()==0){
      cout << "----------Movie----------" << endl;
			cout << k.second.getMovie() << endl;
		} else {
      cout << "----------Serie----------" << endl;
			cout << k.second.getSerie() << endl;
      cout << "----------Episodes----------" << endl;
			for (int r=0; r<k.second.getSerie().getEpisode().size(); r++)
				cout << k.second.getSerie().getEpisode()[r] << endl;
		}
    cout << "--------------------------" << endl << endl;
	}
}
