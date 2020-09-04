/* cppbuch/k3/personalverwaltung/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "personalverwaltung.h"
#include <iostream>

using namespace std;

int main() {
  Personalverwaltung personalverwaltung("daten.txt");

  cout << "Gelesene Namen und Personalnummern:\n";
  personalverwaltung.ausgeben();

  personalverwaltung.dialog();
  cout << "Programmende\n";
}
