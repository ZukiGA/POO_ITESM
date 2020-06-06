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
			//LOAD FUNCTION;
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

}

void StreamingMedia::search(){

}
