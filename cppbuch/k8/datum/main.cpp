/* cppbuch/k8/datum/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "datum.h"
#include <iostream>
using namespace std;

int main() {
  cout << "NOCH NICHT VOLLSTÄNDIG (s. Übungsaufgaben)\n";
  Datum d1;
  ++d1;
  // string datumString = d1;  // implizite Typumwandlung wegen
  // explicit nicht erlaubt
  cout << "explizite Typumwandlung: ";
  string datumString = static_cast<string>(d1);
  cout << datumString << '\n';

  constexpr Datum d2(1, 1, 2017);
  cout << d2.tag() << '.' << d2.monat() << '.' << d2.jahr() << '\n';
  Datum d3 = d2;
  ++d3;
  cout << d3.tag() << '.' << d3.monat() << '.' << d3.jahr() << '\n';
}
