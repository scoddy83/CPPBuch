/* cppbuch/k4/eldatptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

struct Datensatz {                          // öffentliche Klasse
  Datensatz(int x, int y)                   // Konstruktor
      : a{x}, b{y} {}
  int a;
  int b;
};

int main() {
  // Zeiger auf Elementattribute
  Datensatz einDatensatz(1, 2);
  int Datensatz::*dp{&Datensatz::a};
  std::cout << einDatensatz.*dp << '\n';    // 1
  dp = &Datensatz::b;                       // Zeiger umschalten
  std::cout << einDatensatz.*dp << '\n';    // 2
  // neues Objekt erzeugen
  Datensatz* dPtr{new Datensatz(1000, 2000)};
  std::cout << dPtr->*dp << '\n';           // 2000
  delete dPtr;
}
