/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 08/04/20
File: StreamingMedia.hpp
*/

#include <bits/stdc++.h>
//COMPOSE
#include "Multimedia.hpp"
#include "SearchEngine.hpp"

using namespace std;

//CLASS
class StreamingMedia {
  //PUBLIC ATTRIBUT
 	unordered_map <int, Multimedia> listOfContent;
public:
  //CONSTRUCTOR
	StreamingMedia();
  //DESTRUCTOR
  ~StreamingMedia();
  //METHODS
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

//CONSTRUCTOR
StreamingMedia::StreamingMedia(){
}

//DESTRUCTOR
StreamingMedia::~StreamingMedia(){
}

//VOID FUNCTION, NO PARAMETERS. STARTS THE STREAMING SERVICE
void StreamingMedia::on(){
  //VARIABLES
	int userChoose = 0;
  //WELCOME
	cout << "-------------WELCOME TO GeekXGeek-------------" << endl;
  //CALLING TO THE MENU METHOD
	userChoose = mainMenu();
  //MAIN MENU STORED IN A LOOP
	while (userChoose>0&&userChoose<7) {
		if (userChoose == 1) {
			//LOAD FILE
			loadInfo();
		} else {
			if (userChoose == 2) {
        //SHOW ALL CONTENT
				showEverything();
			} else {
				if (userChoose == 3) {
          //SHOW ONLY SERIES
					showSeries(1);
				} else {
					if (userChoose == 4) {
            //SHOW ONLY MOVIES
						showMovies();
					} else {
						if (userChoose == 5) {
              //SEARCH USING FILTERS
							search();
						} else {
							if (userChoose == 6) {
                //RATE VIDEOS
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

//VOID METHOD, NO PARAMETERS. FINISH THE STREAMING SERVICE
void StreamingMedia::off(){
  //FINAL MESSAGES
	cout << endl << "---------------------------" << endl;
	cout << "We hope you have enjoyed GeekXGeek." << endl;
	cout << "Shutting down..." << endl;
}

//INT METHOD, NO PARAMETERS. RETURNS THE CHOISE OF THE USER AND PRINTS THE POSSIBLE OPTIONS.
int StreamingMedia::mainMenu(){
  //VARIABLE
	string choose = "0";
  //MENU
	cout << endl << "-----MENU-----" << endl << "Choose one of the next options:" << endl << "1. Load file"
	<< endl << "2. Show all the content" << endl << "3. Show only series" << endl << "4. Show only movies"
	<< endl << "5. Filter a search (Score, Genre)" << endl << "6. Rate a video" << endl << "0. Exit" << endl;
  //INPUT
  cin >> choose;
  //SET WITH THE POSSIBLE OPTIONS, IT HELPS TO VALIDATE ALL THE ENTRYS
	unordered_set <string> options={"0","1","2","3","4","5","6"};
  //OBJECT WHICH HAS THE VALIDATE METHOD.
  SearchEngine Se;
  //RETURNS A VALIDATED INPUT
  choose=Se.validateEntrys(options,choose);
  //CALLING DESTRUCTOR
  Se.~SearchEngine();
  //RETURNS THE CHOICE
	return stoi(choose);
}

//VOID METHOD. NO PARAMETERS. IT HELPS TO LOAD THE INFO OF A FILE.
void StreamingMedia::loadInfo(){
  //VARIABLES
	string fileName = "", line = "-1", numberID="";
	vector <string> compiled, f1, f2, f3, f4, f5, f6;
	int pastmp=0, numberOfMultimediaInFile = 0, g=0;

  //MESSAGE
	cout << "What is the name of the file?" << endl;
  //INPUT
	cin >> fileName;

	//If the user don"t add the .txt, these lines append it.
	size_t sIterador = fileName.find(".txt");

	if (sIterador == string::npos)
		fileName += ".txt";

  //FILE STREAM
	ifstream multimediaFile(fileName);

  //CHECK IF THE FILE EXISTS
	if (multimediaFile.fail()) {

		cout << "Sorry, it appears the file doesn't exist." << endl;

	} else {
      //COLLECT THE INFO
			while (getline(multimediaFile, line)) {

				//All the lines are saved, except the one which doesn"t have anything
				if (line.size()!=0)
						compiled.push_back(line);
				}

      //SIZE OF DATA
			numberOfMultimediaInFile = stoi(compiled[0]);
      //RESERVING MEMORIE FOR THE VECTORS
		  f1.reserve(numberOfMultimediaInFile);
		  f2.reserve(numberOfMultimediaInFile);
		  f3.reserve(numberOfMultimediaInFile);
		  f4.reserve(numberOfMultimediaInFile);
		  f5.reserve(numberOfMultimediaInFile);

      //IT CYCLE FOR SAVES THE INFO IN THE MAP
			for (int h=1; h<=numberOfMultimediaInFile; h++) {

        //SEPARATING THE INFO
        f1.push_back(compiled[h]);
				f2.push_back(compiled[h+numberOfMultimediaInFile]);
				f3.push_back(compiled[h+numberOfMultimediaInFile*2]);
				f4.push_back(compiled[h+numberOfMultimediaInFile*3]);
				f5.push_back(compiled[h+numberOfMultimediaInFile*4]);

            //CONDITIONAL FOR SERIES, BECAUSE THEY DON'T HAVE DURATION SPECIFIED
        		if (f3[h-1]=="na"){
                //POINTER DECLARATION
          			Serie *S = new Serie(stoi(f1[h-1]), f2[h-1], f4[h-1], stof(f5[h-1]));
                //MULTIMEDIA OBJECT
          			Multimedia M(S);
                //ID OF SERIE
          			pastmp = stoi(f1[h-1]);
                //STORING OBJECT WITH ID AS KEY
          			listOfContent[pastmp] = M;
                //DELETE TEMPORAL OBJECT
                delete S;

        		} else if (f1.size()>2&&f1[h-2]==f1[h-1]){
                //VARIABLE USED FOR SET SEASON (EXCLUSIVE FROM EPISODES)
					      g = g+1;
                //POINTER DECLARATION
        		  	Episode *E = new Episode(f2[h-1], f3[h-1], f4[h-1], stof(f5[h-1]), stoi(compiled[g+numberOfMultimediaInFile*5]));
                //STORING OBJECT IN THE SERIE'S ATTRIBUTS
                listOfContent[pastmp].saveEpisode(E);
                //DELETE TEMPORAL
                delete E;

        		} else {

              //POINTER
		        	Movie *P = new Movie(stoi(f1[h-1]), f2[h-1], f3[h-1], f4[h-1], stof(f5[h-1]));
              //MULTIMEDIA
		        	Multimedia M(P);
              //STORING OBJECT
		        	listOfContent[stoi(f1[h-1])] = M;
              //DELETE TEMPORAL
              delete P;

        		}
			}
			cout << "-------- DATA LOADED -------" << endl;
	}
  //CLOSING FILE
	multimediaFile.close();
}

//VOID FUNCTION, INT PARAMETER THAT IS USED TO PRINT THE WHOLE INFO OR JUST THE SERIES // 0 = SERIES //1 = S & EPISODES
void StreamingMedia::showSeries(int d){
  //VARIABLE
	int b = 0;

	for (auto k : listOfContent){
    //IF AN ID IS 0, THAT MEANS THERE IS NO THAT KIND OF OBJECT
		if (k.second.getMovie().getID()==0){
      //ORDER THE SERIES BY NUMBER
			b=b+1;
      //SERIE + NUMBER
     	cout << "----------Serie " << b << "----------" << endl;
      //SERIE IS PRINTED BY OPERATOR OVERLOADING
      cout << k.second.getSerie() << endl;
      //WHEN D=1, THE EPISODES ARE PRINTED TOO
      if (d==1){

	      cout << "----------Episodes----------" << endl;
        //EVERY EPISODE OF EVERY SERIE IS PRINTED BY OPERATOR OVERLOADING
			  for (int r=0; r<k.second.getSerie().getEpisode().size(); r++)
				  cout << k.second.getSerie().getEpisode()[r] << endl;
        //END
        cout << "--------------------------" << endl << endl;
		  }
    }
	}
}

//VOID FUNTION. NO PARAMETERS. ONLY SHOWS THE MOVIES AVAILABLE
void StreamingMedia::showMovies(){
  //VARIABLES
	int b = 0;
  //IT PRINTS INFO
	for (auto k : listOfContent){
    //CHECK WHAT KIND OF OBJECT IS STORED
		if (k.second.getSerie().getID()==0){

			b = b+1;

      cout << "----------Movie " << b << "----------" << endl;
      //PRINTING MOVIE BY OPERATOR OVERLOADING
			cout << k.second.getMovie() << endl;

      cout << "--------------------------" << endl << endl;
		}

	}
}

//VOID FUNCTION. NO PARAMETERS. IT PRINTS ALL THE CONTENT.
void StreamingMedia::showEverything(){
  //CALLING SHOW MOVIES
	showMovies();
  //CALLING SHOW SERIES USING INDEX 1
	showSeries(1);
}

//VOID FUNCTION. NO PARAMETERS. SEARCH BY USING FILTERS WITH A SEARCH ENGINE
void StreamingMedia::search(){
  //CHECKS IF THERE IS NO CONTENT
  if (listOfContent.size()>0){
    //VARIABLES
    string filter = "", content = "", serieChosen = "", minimumScore = "";
    //OBJECT USING THE INFO
  	SearchEngine filters(listOfContent);
    //METHOD FOR SEARCH WITH FILTERS
    filters.searchBy();

  } else {
    //MESSAGE PRINTED IF THE MAP IS VOID
    cout << endl<<"Please, load a file" << endl;
  }
}

//VOID FUNCTION. NO PARAMETERS. RATES THE VIDEO THAT THE USER CHOOSE.
void StreamingMedia::scoring(){
  //VARIABLES
  string option, n, rate;
  int val;
  //CHECK THE SIZE OF THE MAP
  if (listOfContent.size()>0){
    //INITIAL MESSAGE
    cout << "Choose one option: " << endl << "1. Rate a movie"
    << endl << "2. Rate an episode" << endl;
    //INPUT
    cin >> option;
    //OPTIONS FOR INPUT
    unordered_set <string> op2={"1","2"};
    //OBJECT
    SearchEngine Se;
    //VALIDATE ENTRYS
    option = Se.validateEntrys(op2,option);
    //DESTRUCTOR
    Se.~SearchEngine();

  } else{
    //WHEN THE MAP IS VOID
    cout << endl<<"Please, load a file" << endl;

  }
  //USER CHOSE TO RATE A MOVIE
  if (option =="1"){
    //SHOW MOVIES AVAILABLE
    showMovies();
    //BY NAME
    cout << "Enter the name of a movie: " << endl;
    //input
    cin.ignore();
    getline(cin,n);
    //OPTIONS
    unordered_set <string> op3;
    //SAVES THE NAMES INTO THE SET
    for (auto k : listOfContent){

      op3.insert(k.second.getMovie().getName());

    }
    //OBJECT
    SearchEngine Se;
    //VALIDATE ENTRYS
    n = Se.validateEntrys(op3,n);
    //DESTRUCTOR
    Se.~SearchEngine();

    //CHECKS THE EXISTENCE OF THE NAME AND SAVES THE ID
    for (auto k : listOfContent){

      if (k.second.getMovie().getName()==n)
        val = k.first;

    }
    //SEARCHS FOR THE ID GIVEN
    if (listOfContent[val].getMovie().getID()==val){
      //VARIABLE
      string test = "";
      //MESSAGE
      cout << "Enter your rating (0-5): ";
      //INPUT
      rate = "";
      cin >> rate;
      //OBJECT
      SearchEngine Se;
      //OPTIONS
      unordered_set <string> rates = {"0","1","2","3","4","5"};
      //VALIDATE
      rate = Se.validateEntrys(rates,rate);
      //DESTRUCTOR
      Se.~SearchEngine();
      //RATE THE MOVIE BY CALLINF A METHOD IN MULTIMEDIA
      listOfContent[val].rateContent(rate);
      //FINAL MESSAGES
      cout << "-------------DONE--------------" << endl;
      //PRINTS THE INFO UPDATED
      cout << listOfContent[val].getMovie() << endl;
      cout << "-------------------------------" << endl;

    } else{
      //WHEN FAILING
      cout << "ID not found" << endl;

    }

    //IF THE USER CHOSE TO RATE AN EPISODE
  } else if (option == "2") {
    //SHOW ONLY SERIES AVAILABLE BECAUSE OF THE INDEX 0
    showSeries(0);
    //MESSAGE
    cout << "Enter the name of the serie: " << endl;
    //INPUT
    cin.ignore();
    getline(cin,n);
    //OPTIONS
    unordered_set <string> op4;
    //SAVES THE NAMES INTO THE SET
    for (auto k : listOfContent){
      op4.insert(k.second.getSerie().getName());

    }
    //OBJECT
    SearchEngine Se;
    //VALIDATE
    n = Se.validateEntrys(op4,n);
    //DESTRUCTOR
    Se.~SearchEngine();
    //SEARCHS THE ID
    for (auto k : listOfContent){
      //SAVES THE ID;
      if (k.second.getSerie().getName()==n)
        val = k.first;

    }
    //CHECKS IF THE ID EXISTS
    if (listOfContent[val].getSerie().getID()==val){
        //OPTIONS
        unordered_set <string> op5;
        //PRINTS THE EPISODES OF THE SERIE AND SAVES THE NAMES IN THE SET
        for (int q=0; q<listOfContent[val].getSerie().getEpisode().size(); q++){

          op5.insert(listOfContent[val].getSerie().getEpisode()[q].getName());
          cout << listOfContent[val].getSerie().getEpisode()[q] << endl;

        }
        //MESSAGE
        cout << "Enter the name of the episode: " << endl;
        //INPUT
        n = "";

        getline(cin,n);
        //OBJECT
        SearchEngine Se;
        //VALIDATE
        n = Se.validateEntrys(op5,n);
        //DESTRUCTOR
        Se.~SearchEngine();
        //INDEX
        int w=0;
        //STORES THE EPISODE NUMBER BY COMPARING WITH THE NAME
        while (listOfContent[val].getSerie().getEpisode()[w].getName()!=n){

          w = w+1;

        }

        //CHECKS IF THE INDEX EXISTS
        if (listOfContent[val].getSerie().getEpisode()[w].getName()==n){
          //MESSAGE
          cout << "Enter your rating (0-5): ";
          //INPUT
          rate = "";
          cin >> rate;
          //OBJECT
          SearchEngine Se;
          //OPTIONS
          unordered_set <string> rates = {"0","1","2","3","4","5"};
          //VALIDATE SCORE GIVEN
          rate = Se.validateEntrys(rates,rate);
          //DESTRUCTOR
          Se.~SearchEngine();
          //RATE BY CALLING A FUNCTION FROM MULTIMEDIA
          listOfContent[val].rateContent(rate,w);
          //FINAL MESSAGE
          cout << "-------------DONE--------------" << endl;
          //PRINTS THE UPTADED INFO
          cout << listOfContent[val].getSerie().getEpisode()[w] << endl;
          cout << "-------------------------------" << endl;

        } else {
          //IF FAILS
          cout << "ID not found" << endl;
        }
      }  else{
        //IF FAILS
       cout << "ID not found" << endl;
      }
    }
}
