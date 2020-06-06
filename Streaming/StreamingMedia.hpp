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
	string fileName = "", line = "-1", numberID="";
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

			for (int h=0; h<numberOfMultimediaInFile; h++) {

				size_t pos = compiled[h].find("	");
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
