/* cppbuch/k26/funktionsobjekt/addierer.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <functional>
#include <iostream>

int main() {
  std::plus<double> addierer1;
  std::plus<void> addierer2;
  std::plus<> addierer3;
  int    i = 1;
  double d = 0.987654321;
  std::cout << i << " + " << d << " = \n"
            << addierer1(i, d) << '\n'
            << addierer2(i, d) << '\n'
            << addierer3(i, d) << '\n';
}
