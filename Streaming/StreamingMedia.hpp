/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: StreamingMedia.hpp
*/
#include <bits/stdc++.h>
using namespace std;

class StreamingMedia {
private:
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
	<< endl << "2. Show me all the videos" << endl << "3. Show me series" << endl << "4. Show me movies"
	<< endl << "5. Filter your search (Score, Genre)" << endl << "6. Rate a video" << endl << "0. Exit" << endl;

	cin >> choose;

	return choose;
}

void StreamingMedia::loadInfo(){
	string nombreArchivo = "", linea = "-1";
	vector <string> recopilado;
	Vuelo miVueloCargado, *miVueloCargado2;
	FechaHora fechaHoraLlegadaVueloCargado, fechaHoraSalidaVueloCargado, *fechaHoraLlegadaVueloCargadoPoint, *fechaHoraSalidaVueloCargadoPoint;
	int numeroVuelosArchivo = 0;


	cout << "¿Cuál es el nombre del archivo?" << endl;
	cin >> nombreArchivo;

	//Si el usuario no agrega el .txt se le asigna automáticamente.
	size_t sIterador = nombreArchivo.find(".txt");

	if (sIterador == string::npos)
		nombreArchivo += ".txt";

	ifstream archivoVuelos(nombreArchivo);

	if (archivoVuelos.fail()) {

		cout << "Archivo no encontrado" << endl;

	} else {

			while (getline(archivoVuelos, linea)) {

				//Se gurdan todas las líneas, excepto las que estén en blanco.
				if (linea.size()!=0)
						recopilado.push_back(linea);
				}

				//La primera línea indica el número de vuelos que es utilizado para saber el número de veces que se va a repetir el
				//ordenamiento
				numeroVuelosArchivo = stoi(recopilado[0]);

				for (int h=0; h<numeroVuelosArchivo; h++) {

			//Los datos en determinadas posiciones en el vector se van asignado a un objeto temporal.
					miVueloCargado.setOrigen(recopilado[h*14+1]);
					miVueloCargado.setDestino(recopilado[h*14+2]);

					//Stoi() convierte los datos de tipo string a int.
					fechaHoraSalidaVueloCargado.setFecha(stoi(recopilado[h*14+3]), stoi(recopilado[h*14+4]),
						stoi(recopilado[h*14+5]), stoi(recopilado[h*14+6]), stoi(recopilado[h*14+7]));
					fechaHoraSalidaVueloCargadoPoint = &fechaHoraSalidaVueloCargado;
					miVueloCargado.setFechaHoraSalida(*fechaHoraSalidaVueloCargadoPoint);

					fechaHoraLlegadaVueloCargado.setFecha(stoi(recopilado[(h+1)*14-6]), stoi(recopilado[(h+1)*14-5]),
						stoi(recopilado[(h+1)*14-4]), stoi(recopilado[(h+1)*14-3]), stoi(recopilado[(h+1)*14-2]));
					fechaHoraLlegadaVueloCargadoPoint = &fechaHoraLlegadaVueloCargado;
					miVueloCargado.setFechaHoraLlegada(*fechaHoraLlegadaVueloCargadoPoint);

					miVueloCargado.setAerolinea(recopilado[(h+1)*14-1]);
					miVueloCargado.setNumeroVuelo(stoi(recopilado[(h+1)*14]));

					//La dirección en memoria del objeto se asigna a un apuntador.
					miVueloCargado2 = &miVueloCargado;

					//El número de vuelo se usa como llave para el objeto apuntador.
					datosVuelosCarga[stoi(recopilado[(h+1)*14])] = *miVueloCargado2;
				}

				cout << "--- DATOS CARGADOS ---" << endl;
	}

	archivoVuelos.close();

	return datosVuelosCarga;
}

void StreamingMedia::search(){

}
