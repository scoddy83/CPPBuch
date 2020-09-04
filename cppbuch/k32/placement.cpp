/* cppbuch/k32/placement.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <new>

class Irgendwas {
public:
  Irgendwas() : id(++maxid) {}
  void machwas() const { std::cout << "Id  = " << id << '\n'; }

private:
  int id;
  static int maxid;
};

int Irgendwas::maxid = 0;

int main() {
  char vielPlatz[1000 * sizeof(Irgendwas)] = {0};  // mit 0 initialisieren

  // Ein Objekt in \tt{vielPlatz} anlegen:
  Irgendwas* p = new (vielPlatz) Irgendwas;  // Objekt 1
  p->machwas();

  // Weitere 10 Objekte mit Array-Operator anlegen:
  char* naechsteAdresse = reinterpret_cast<char*>(p) + sizeof(Irgendwas);
  new (naechsteAdresse) Irgendwas[10];  // Objekte 2 bis 11

  // Alle 11 Objekte abfragen (1-11)
  for (int i = 0; i < 11; ++i) {
    std::cout << i << ": ";
    p++->machwas();
  }
  // Die nächste Position ist nicht belegt, d.h. der
  // Aufruf muss 0 ergeben, weil das Feld mit 0 initialisiert wurde.
  // p zeigt auf einen Bereich, in dem gar kein Objekt des Typs
  // Irgendwas angelegt wurde. Nichtsdestoweniger wird der Zeiger p
  // interpretiert, als zeige er auf ein Objekt. Die Daten sind aber
  // alle 0.
  p->machwas();
}
