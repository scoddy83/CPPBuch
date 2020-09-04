/* cppbuch/k26/bind/bind1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <functional>
#include <iostream>
using std::bind;
using namespace std::placeholders;

template <class T>  // T muss ein Typ für Funktionsobjekte sein
void aufrufen(T funcObj) {
  int i1 = 1;
  int i2 = 3;
  int i3 = 5;
  int doppel = funcObj(i1, i2, i3);  // Funktionsaufruf über FuncObj-Objekt
  std::cout << doppel << '\n';
}

int verdoppeln(int i) { return 2 * i; }

int main() {
  aufrufen(bind(verdoppeln, 9));   // Funktion an Wert binden
  aufrufen(bind(verdoppeln, _1));  // Funktion an Parameter 1 binden
  aufrufen(bind(verdoppeln, _2));  // Funktion an Parameter 2 binden
  aufrufen(bind(verdoppeln, _3));  // Funktion an Parameter 3 binden
}
