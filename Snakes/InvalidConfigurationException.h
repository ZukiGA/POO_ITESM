/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 08/24/2020
Last modification date: 08/24/2020
File: InvalidConfigurationException.h
*/

#include <bits/stdc++.h>

class InvalidConfigurationException : public std::exception {
  //ATTRIBUTS
  std::string param_name;
  int param_value;
  std::string str;

public://METHODS
    //CONSTRUCTOR
    InvalidConfigurationException(std::string param_name, int param_value):param_name(param_name), param_value(param_value),
    str("Invalid "+param_name+" value "+std::to_string(param_value)){}
    //METHOD THAT RETURNS THE MESSAGE IF THERE IS A PROBLEM
    char const* what() const noexcept override {
      return str.c_str();
    }
};
