/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 08/24/2020
Last modification date: 08/24/2020
File: InvalidOptionException.h
*/

#include <bits/stdc++.h>

class InvalidOptionException : public std::exception {
  //ATTRIBUTS
  std::string message;

public://METHODS
    //CONSTRUCTOR
    InvalidOptionException(std::string message):message(message){}
    //METHOD THAT RETURNS THE MESSAGE IF THERE IS A PROBLEM
    char const* what() const noexcept override {
      return message.c_str();
    }
};
