/* cppbuch/k3/delegierenderKonstruktor/klasse2.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef KLASSE2_H
#define KLASSE2_H

class Klasse {
public:
  Klasse(int a, int b)  // Konstruktor 1
      : attr1{a}, attr2{b} {
    // Code für weitere Initialisierungen
  }
  Klasse()               // Konstruktor 2
      : Klasse(1, 42) {  // Delegation an Konstruktor 1
  }

private:
  int attr1;
  int attr2;
};
#endif
