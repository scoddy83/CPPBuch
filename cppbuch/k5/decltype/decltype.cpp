/* cppbuch/k5/decltype/decltype.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ort.h"
#include <utility>  //             \tt{declval}

auto func(const Ort& ort) -> decltype(ort.getX()) {  // C++11
  auto x = ort.getX();
  // Berechnungen mit x weggelassen ..
  return x;
}

auto func1(const Ort& ort) {  // C++14
  auto x = ort.getX();
  // Berechnungen mit x weggelassen ..
  return x;
}

auto func2(const Ort& ort) -> decltype(std::declval<Ort>().getX()) {  // C++11
  auto x = ort.getX();
  // Berechnungen mit x weggelassen ..
  return x;
}

int main() {
  Ort ort1(20, 100);
  auto a = ort1.getX();                 // 20 (\tt{int})
  decltype(ort1.getX()) b;              // nicht initialisiert
  decltype((Ort()).getX()) c;           // nicht initialisiert
  decltype(func(ort1)) d;               // nicht initialisiert
  auto e = func(ort1);                  // initialisiert
  decltype(func(ort1)) f = func(ort1);  // initialisiert
  auto g = func1(ort1);

  // decltype hat oben einen Ausdruck als Argument.
  // Der Typ kann aber auch aus der Initialisierung ermittelt werden
  Ort ort2(1, 99);
  std::cout << ort2 << '\n';
  // decltype(auto) o2 = ort2;          // der Typ ist Ort
  // decltype(auto) o2r = (ort2);       // der Typ ist Ort&
  auto o2 = ort2;    // der Typ ist Ort
  auto& o2r = ort2;  // der Typ ist Ort&
  o2r.aendern(100, 200);
  std::cout << ort2 << '\n';  // (100, 200)

  // FALLS kein Standard-Konstruktor existiert oder ein anderer
  // Konstruktor nicht bekannt ist oder ein Objekt nicht existiert
  // (hier nicht der Fall), wird declval eingesetzt:
  decltype(std::declval<Ort>().getX()) c1;
}
