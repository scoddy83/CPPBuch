/* cppbuch/k27/reverseiterator.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>


int main() {
  std::vector<int> container {1, 2, 3, 4, 100};
  auto iter = container.rbegin();            // \tt{auto} = \tt{vector<int>::reverse\_iterator}
  while(iter != container.rend()) {
    std::cout << (*iter) << '\n';
    ++iter;
  }
}
