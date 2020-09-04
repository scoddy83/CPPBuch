/* cppbuch/k3/delegierenderKonstruktor/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Falls der Compiler delegierende Konstruktoren NICHT unterstützt,
// die nächste Zeile entfernen oder auskommentieren
//#define DELEGIERENDERKONSTRUKTOR

#ifndef DELEGIERENDERKONSTRUKTOR
#include "klasse1.h"
#else
#include "klasse2.h"
#endif

int main() {         // Attributwerte
  Klasse k1(5, 20);  //     5     20
  Klasse k2;         //     1     42
}
