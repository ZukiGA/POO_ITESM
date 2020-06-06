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
  int hours;
  int minutes;
public:
  Time(int, int);
  friend ostream& operator <<(ostream& os, const Time& tm);
};

Time::Time(int h, int m){
  hours = h;
  minutes = m;
}


//OPERATOR <<
ostream& operator<<(ostream& os, const Time& tm) {
  if (tm.hours<10&&tm.minutes<10)
    os << '0' << tm.hours << ':' << '0' << tm.minutes;
  else if (tm.hours<10&&tm.minutes>9)
    os << '0' << tm.hours << ':' << tm.minutes;
  else if (tm.hours>9&&tm.minutes<10)
    os << tm.hours << ':' << '0' << tm.minutes;
  else
    os << tm.hours << ':' << tm.minutes;
}
