/* cppbuch/k26/bind/bind2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using std::bind;
using namespace std::placeholders;

int main() {
  std::vector<int> v{111, 107, 101, 90, 106};

  const int wert = 103;
  std::cout << "Das erste Element < " << wert << " ist: "
            << *find_if(v.begin(), v.end(), bind(std::less<int>(), _1, wert))
            << '\n';
}
