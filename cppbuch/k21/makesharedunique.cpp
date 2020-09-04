/* cppbuch/k21/makesharedunique.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <memory>
#include <vector>

int main() {
  auto ptr = std::make_shared<std::vector<int>>();

  for (auto i = 0; i < 10; ++i) {  // vector mit Werten versehen
    ptr->push_back(i);
  }
  for (auto element : *ptr) {
    std::cout << element << '\n';
  }
  auto ptr1 = std::make_unique<std::vector<int>>();

  for (auto i = 0; i < 10; ++i) {  // vector mit Werten versehen
    ptr1->push_back(i + 10);
  }
  for (auto element : *ptr1) {
    std::cout << element << '\n';
  }
}
