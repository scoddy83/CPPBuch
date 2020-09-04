/* cppbuch/k23/vermischtes/copy/copy_if.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> container1(20);
  iota(container1.begin(), container1.end(), 1);  // 1, 2, ... 20
  showContainer(container1);

  vector<int> container2(5, 0);  // Container mit 5 Nullen anlegen
  // alle Elemente > 10 am Ende einfügen:
  copy_if(container1.begin(), container1.end(), back_inserter(container2),
          [](int x) { return x > 10; });
  showContainer(container2);
}
