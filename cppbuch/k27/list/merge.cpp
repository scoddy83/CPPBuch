/* cppbuch/k27/list/merge.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <list>
#include <showContainer.h>
using namespace std;

int main() {
  list<int> L1;
  list<int> L2;

  // Listen mit sortierten Zahlen füllen:
  for (int i = 0; i < 5; ++i) {
    L1.push_back(2 * i);      // gerade Zahlen
    L2.push_back(2 * i + 1);  // ungerade Zahlen
  }

  showContainer(L1);  // 0 2 4 6 8
  showContainer(L2);  // 1 3 5 7 9

  L1.merge(L2);       // merge
  showContainer(L1);  // 0 1 2 3 4 5 6 7 8 9
  showContainer(L2);  //  (leere Liste)
}
