/*
Author: Bryan Gonzalez Arellano
ID: A01734198
Creation date: 08/24/2020
Last modification date: 08/24/2020
File: Exception.h
*/

#include <bits/stdc++.h>
class Exception : public std::exception
{
  std::string msg;

public:
    Exception(std::string msg):msg(msg){}

    char const* what() const noexcept override {
      return msg.c_str();
    }
};
