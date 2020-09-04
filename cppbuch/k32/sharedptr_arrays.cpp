/* cppbuch/k32/sharedptr_arrays.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <memory>

struct X {
  X(int i = 0)
    : wert(i) {
  }
  ~X() {
    std::cout << "X(" << wert << ") gelöscht\n";;
  }
  int wert;
};

int main() {
  std::shared_ptr<X> p1(new X[5], std::default_delete<X[]>());
  std::shared_ptr<X[]> p2(new X[5]);        // 
  for(int i=0; i < 5; ++i) {
    p1.get()[i].wert = i + 1;               // Zuweisen eines Werts
    p2[i].wert = 10*i + 11;                 // Kurzform geht nur bei shared_ptr<X[]>
  }
}
