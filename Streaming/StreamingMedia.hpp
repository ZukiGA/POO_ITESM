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
#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#ifndef SERIE_H_INCLUDED
#define SERIE_H_INCLUDED
#ifndef EPISODE_H_INCLUDED
#define EPISODE_H_INCLUDED
#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED




using namespace std;

class StreamingMedia {
 	unordered_map <int, Multimedia*> listOfContent;
public:
	StreamingMedia();
	void on();
	void off();
	int mainMenu();
	void loadInfo();
	void search();
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
				//SHOW CATALOGUE;
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
	string fileName = "", line = "-1", numberID="", pastmp = "";
	vector <string> compiled;
	Multimedia myMultimediaLoaded, *myMultimediaLoaded2;
	int numberOfMultimediaInFile = 0;


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

				////La primera línea indica el número de Multimedia que es utilizado para saber el número de veces que se va a repetir el
				////ordenamiento

				//numberOfMultimediaInFile = stoi(compiled[0]);

			for (int h=0; h<compiled.size(); h++) {
        //cout << "Checkpoint3" << endl;
				size_t pos = compiled[h].find("	");
        string tmp = compiled[h].substr(0,pos);
        string str = compiled[h].substr(pos+1,compiled[h].size());
        tmp.erase(remove_if(tmp.begin(), tmp.end(), ::isspace),tmp.end());

        size_t pos2 = str.find(" ");
        string tmp2 = str.substr(0,pos2);
        string str2 = str.substr(pos2+1,str.size());
        tmp2.erase(remove_if(tmp2.begin(), tmp2.end(), ::isspace),tmp2.end());

        size_t pos3 = str2.find(" ");
        string tmp3 = str2.substr(0,pos3);
        string str3 = str2.substr(pos3+1,str2.size());
        tmp3.erase(remove_if(tmp3.begin(), tmp3.end(), ::isspace),tmp3.end());

        size_t pos4 = str3.find(" ");
        string tmp4 = str3.substr(0,pos4);
        string str4 = str3.substr(pos4+1,str3.size());
        tmp4.erase(remove_if(tmp4.begin(), tmp4.end(), ::isspace),tmp4.end());

        size_t pos5 = str4.find(" ");
        string tmp5 = str4.substr(0,pos5);
        string str5 = str4.substr(pos5+1,str4.size());
        tmp5.erase(remove_if(tmp5.begin(), tmp5.end(), ::isspace),tmp5.end());
        cout << tmp << " "<< tmp2 <<" "<< tmp3 <<" "<< tmp4 <<" "<< tmp5 << endl;
        //if (tmp3=="na"){
        //  Serie *S = new Serie();
        //  listOfContent[stoi(tmp)] = S;
        //} else if (tmp==pastmp){
        //  Episode *E = new Episode();
        //  listOfContent[stoi(tmp)]->setEpisode(S);
        //} else {
        //  Movie *M = new Movie();
        //  listOfContent[stoi(tmp)] = M;
        //}
        pastmp = tmp;

			//////Los datos en determinadas posiciones en el vector se van asignado a un objeto temporal.
			//	//	myMultimediaLoaded.setOrigen(compiled[h*14+1]);
			//	//	myMultimediaLoaded.setDestino(compiled[h*14+2]);

			//	//	//Stoi() convierte los datos de tipo string a int.
			//	//	fechaHoraSalidaMultimediaCargado.setFecha(stoi(compiled[h*14+3]), stoi(compiled[h*14+4]),
			//	//		stoi(compiled[h*14+5]), stoi(compiled[h*14+6]), stoi(compiled[h*14+7]));
			//	//	fechaHoraSalidaMultimediaCargadoPoint = &fechaHoraSalidaMultimediaCargado;
			//	//	myMultimediaLoaded.setFechaHoraSalida(*fechaHoraSalidaMultimediaCargadoPoint);

			//	//	fechaHoraLlegadaMultimediaCargado.setFecha(stoi(compiled[(h+1)*14-6]), stoi(compiled[(h+1)*14-5]),
			//	//		stoi(compiled[(h+1)*14-4]), stoi(compiled[(h+1)*14-3]), stoi(compiled[(h+1)*14-2]));
			//	//	fechaHoraLlegadaMultimediaCargadoPoint = &fechaHoraLlegadaMultimediaCargado;
			//	//	myMultimediaLoaded.setFechaHoraLlegada(*fechaHoraLlegadaMultimediaCargadoPoint);

			//		myMultimediaLoaded.setAeroline(compiled[(h+1)*14-1]);
			//		myMultimediaLoaded.setNumeroMultimedia(stoi(compiled[(h+1)*14]));

			//		//La dirección en memoria del objeto se asigna a un apuntador.
			//		myMultimediaLoaded2 = &myMultimediaLoaded;

			//		//El número de Multimedia se usa como llave para el objeto apuntador.
			//		MultimediaData[stoi(compiled[(h+1)*14])] = *myMultimediaLoaded2;
			}

				cout << "--- DATA LOADED ---" << endl;
	}

	multimediaFile.close();

}

void StreamingMedia::search(){

}
#endif
#endif
#endif
#endif
