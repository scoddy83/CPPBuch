/* cppbuch/k28/finsert.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iterator>
#include <list>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  list<int> dieListe{1, 2, 3, 4, 5};
  cout << "dieListe.size() = " << dieListe.size() << '\n';
  showContainer(dieListe);

  front_insert_iterator<list<int>> frontInsertIterator(dieListe);

  // Einfügen mit den Operationen *, ++, =
  int i = 1;
  while (i < 5) {
    *frontInsertIterator++ = i++;  // 4 Zahlen vorne einfügen
  }
  cout << "dieListe.size() = " << dieListe.size() << '\n';
  showContainer(dieListe);
  // Beispiel mit copy:
  vector<int> v{7, 8, 9, 10};
  copy(v.begin(), v.end(), front_inserter(dieListe));
  showContainer(dieListe);
}
