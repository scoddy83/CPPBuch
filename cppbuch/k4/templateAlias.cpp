/* cppbuch/k4/templateAlias.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <deque>
#include <iostream>

template <typename T> using Container = std::deque<T>;  // double ended queue

int main() {
  Container<int> cont;
  cont.push_back(1);
  // Container weiterverwenden:
  std::cout << cont.at(0) << '\n';
}
