/* cppbuch/k27/list/splice.cpp
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
  for (int i = 0; i < 10; ++i) {
    L1.push_back(2 * i);      // gerade Zahlen
    L2.push_back(2 * i + 1);  // ungerade Zahlen
  }

  showContainer(L1);  // 0 2 4 6 8 10 12 14 16 18
  showContainer(L2);  // 1 3 5 7 9 11 13 15 17 19

  auto iter = L2.begin();
  advance(iter, 4);  // 4 Schritte
  L1.splice(L1.begin(), L2, iter, L2.end());
  cout << " nach splice():\n";
  showContainer(L1);  // 9 11 13 15 17 19 0 2 4 6 8 10 12 14 16 18
  showContainer(L2);  // 1 3 5 7
}
