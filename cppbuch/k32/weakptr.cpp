/* cppbuch/k32/weakptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <memory>
using namespace std;

struct ZyklStruktur {
  ZyklStruktur() = default;
  ~ZyklStruktur() { cout << "Destruktor ~ZyklStruktur() aufgerufen\n"; }
  weak_ptr<ZyklStruktur> nachbar;  // Inititialisierung durch weak_ptr
                                   // Standard-Konstruktor (leeres
                                   // Objekt)
  // shared_ptr<ZyklStruktur> nachbar; // kein Destruktor-Aufruf!
};

void f() {
  shared_ptr<ZyklStruktur> a1(new ZyklStruktur);
  shared_ptr<ZyklStruktur> a2(new ZyklStruktur);
  // Gegenseitige Verweise herstellen:
  a1->nachbar = a2;
  a2->nachbar = a1;
  cout << "Ende von f()\n";
}

int main() { f(); }
