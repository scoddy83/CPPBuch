/* cppbuch/loesungen/k3/6.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

class MeineKlasse {
public:
  MeineKlasse()
      : readonlyZahl{privateZahl},  // Initialisierung der Referenz
        privateZahl{0} {}

  void aendern(int wert) { privateZahl = wert; }

  // public-Referenz auf Konstante, Initialisierung im Konstruktor
  const int& readonlyZahl;

private:
  int privateZahl;
};

using namespace std;

int main() {
  MeineKlasse objekt;
  // objekt.privateZahl = 999;  // Fehler! Zugriff nicht möglich!
  // objekt.readonlyZahl = 999;  // Fehler! Änderung nicht möglich!
  // erlaubte Änderung
  objekt.aendern(999);
  // erlaubter direkter lesender Zugriff:
  cout << "objekt.readonlyZahl=" << objekt.readonlyZahl << '\n';  // 999
}
