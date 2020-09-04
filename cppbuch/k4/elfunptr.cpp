/* cppbuch/k4/elfunptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <ort.h>                            // in \tt{../include}

int main() {
  Ort einOrt(100, 200);
  int (Ort::*fp)() const {&Ort::getX};      // Zeiger auf \tt{Ort::getX()} richten
  std::cout << (einOrt.*fp)() << '\n';      // dasselbe wie \tt{einOrt.getX()}
  fp = &Ort::getY;                          // Funktionszeiger umschalten
  std::cout << (einOrt.*fp)() << '\n';      // jetzt dasselbe wie \tt{einOrt.getY()}
  Ort* derZeiger = new Ort(300, 400);
  std::cout << (derZeiger->*fp)() << '\n';  // dasselbe wie \tt{derZeiger->getY()}
  void (Ort::*fpAendern)(int, int){&Ort::aendern};
  (derZeiger->*fpAendern)(500, 600);        // d.h. \tt{derZeiger->aendern(500, 600)}
  anzeigen(*derZeiger);                     // geänderter Ort
  delete derZeiger;
}
