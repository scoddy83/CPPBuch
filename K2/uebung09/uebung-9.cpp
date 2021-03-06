//CPPBuch/K2/Übung 2.6
#include <iostream>
#include <cctype>
#include "uebung-9.hpp"

using namespace std;

long ausdruck(char& c) {
  long a;
  if(c == '-') {
    cin.get(c);
    a = -summand(c);
  }
  else {
    if(c == '+')
      cin.get(c);
    a = summand(c);
  }
  while(c == '+' || c == '-') {
    if(c == '+') {
      cin.get(c);
      a += summand(c);
    }
    else {
      cin.get(c);
      a -= summand(c);
    }
  }

  return a;
}

long summand(char& c) {
  long s = faktor(c);
  while(c == '*' || c == '/') {
    if (c == '*') {
      cin.get(c);
      s *= faktor(c);
    }
    else {
      cin.get(c);
      s /= faktor(c);
    }
  }
  return s;
}

long faktor (char& c) {
  long f;
  if(c == '(') {
    cin.get(c);
    f = ausdruck(c);
    if(c != ')')
      cout << "Rechte Klammer fehlt!\n";
    else cin.get(c);
  }
  else
    f = zahl(c);
  return f;
}

long zahl(char& c) {
  long z = 0;
  while(isdigit(c)) {
    z = 10*z + long(c-'0');
    cin.get(c);
  }
  return z;
}
