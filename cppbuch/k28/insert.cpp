/* cppbuch/k28/insert.cpp
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

  cout << "einVektor.size() = " << einVektor.size() << '\n';  //  5
  showContainer(einVektor);                                   //  0 0 0 0 0

  // Einfügen mit den Operationen *, ++, =
  insert_iterator<vector<int>> insertIterator(einVektor, einVektor.begin());

  int i = 1;
  while (i < 3) {
    *insertIterator++ = i++;
  }
  // vector:  1 2 0 0 0 0 0,  size() = 7

  insert_iterator<vector<int>> middleInsertIterator(
      einVektor, einVektor.begin() + einVektor.size() / 2);

  while (i < 6) {
    *middleInsertIterator++ = i++;
  }
  // vector:  1 2 0 3 4 5 0 0 0 0,  size() =  10

  insert_iterator<vector<int>> endInsertIterator(einVektor, einVektor.end());
  while (i < 9) {
    *endInsertIterator++ = i++;
  }

  cout << "einVektor.size() = " << einVektor.size() << '\n';  //  13
  showContainer(einVektor);  //  1 2 0 3 4 5 0 0 0 0 6 7 8
  // Beispiel mit copy:
  vector<int> v{7, 8, 9, 10};
  copy(v.begin(), v.end(), inserter(einVektor, einVektor.begin() + 2));
  showContainer(einVektor);
}
