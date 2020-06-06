/*
Author: Bryan González Arellano
ID : A01734198
Creation date: 06/04/20
Modification date: 07/04/20
File: Time.hpp
*/
#include <bits/stdc++.h>
using namespace std;

class Time{
private:
  int hours;
  int minutes;
public:
  Time(int, int);
  //ostream operator <<()
};

Time::Time(int h, int m){
  hours = h;
  minutes = m;
}
