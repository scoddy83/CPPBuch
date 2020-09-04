/* cppbuch/k23/vermischtes/copy/copy_n.cpp
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
  vector<int> v1(20);
  iota(v1.begin(), v1.end(), 1);
  showContainer(v1);
  vector<int> v2(20, 0);
  // die ersten 10 Elemente kopieren
  copy_n(v1.begin(), 10, v2.begin());
  showContainer(v2);
}
