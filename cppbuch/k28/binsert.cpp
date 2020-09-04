/* cppbuch/k28/binsert.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iterator>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> einVektor(5, 0);  // 5 Nullen
  cout << "einVektor.size() = " << einVektor.size() << '\n';
  showContainer(einVektor);  // 0 0 0 0 0

  back_insert_iterator<vector<int>> backInsertIterator(einVektor);

  // Einfügen mit den Operationen *, ++, =
  int i = 1;
  while (i < 4) {
    *backInsertIterator++ = i++;
  }
  cout << "einVektor.size() = " << einVektor.size() << '\n';

  showContainer(einVektor);  // 0 0 0 0 0 1 2 3
  // Beispiel mit copy:
  vector<int> v{7, 8, 9, 10};
  copy(v.begin(), v.end(), back_inserter(einVektor));
  showContainer(einVektor);
}
