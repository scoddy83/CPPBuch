/* cppbuch/k2/namespaces.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

namespace A { 
  void print() {std::cout << "A::print()\n";} 
  namespace B { 
    void print() {std::cout << "A::B::print()\n";} 
  } 
}

int main() {
  A::print();
  A::B::print();
}
