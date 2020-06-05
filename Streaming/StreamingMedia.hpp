/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 06/04/20
File: StreamingMedia.h
*/
#include <bits/stdc++.h>
using namespace std;

class StreamingMedia {
private:
public:
	StreamingMedia();
	void on();
	void off();
	void loadInfo();
	void search();
};

StreamingMedia::StreamingMedia(){
}

void StreamingMedia::on(){
	cout << "Welcome" << endl;
	cout << "Choose one of the next options:" << endl;

	int eleccion = 0;

	cout << endl << "-----MENÚ-----" << endl << "Escoge una opción." << endl << "1. Ver vuelos" << endl << "2. Agregar vuelo" << endl
	<< "3. Mostrar vuelos de una fecha específica" << endl << "4. Actualizar vuelo retrasado" << endl << "5. Cargar vuelos desde archivo"
	<< endl << "6. Guardar vuelos en archivo" << endl << "0. Salir" << endl;

	cin >> eleccion;

	//return eleccion;

	eleccionUsuario = menuPrincipal();

	while (eleccionUsuario>0&&eleccionUsuario<7) {
		if (eleccionUsuario == 1) {
			verVuelo(datosVuelos);
		} else {
			if (eleccionUsuario == 2) {
				datosVuelos = agregarVuelo(datosVuelos);
			} else {
				if (eleccionUsuario == 3) {
					mostrarVuelo(datosVuelos);
				} else {
					if (eleccionUsuario == 4) {
						datosVuelos = actualizarVuelo(datosVuelos);
					} else {
						if (eleccionUsuario == 5) {
							datosVuelos = cargarVuelo(datosVuelos);
						} else {
							if (eleccionUsuario == 6)
								guardarVuelo(datosVuelos);
						}
					}
				}
			}
		}
		eleccionUsuario = menuPrincipal();
	}
}

void StreamingMedia::off(){

}

void StreamingMedia::loadInfo(){

}

void StreamingMedia::search(){

}
