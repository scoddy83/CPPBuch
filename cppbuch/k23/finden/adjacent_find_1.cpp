/* cppbuch/k23/finden/adjacent_find_1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v{0, 2, 3, 4, 8, 8, 5, 1};  // doppelt so großer Nachfolger (4 8)
  showContainer(v);
  auto iter =
      adjacent_find(v.begin(), v.end(), [](int a, int b) { return (b == 2 * a); });

  if (iter != v.end()) {
    cout << "Die erste Zahl (" << *iter
         << ") mit einem doppelt so großen Nachfolger"
            " wurde an Position "
         << (iter - v.begin()) << " gefunden.\n";
  } else {
    cout << "Keine Zahl mit einem doppelt so großen Nachfolger "
            "gefunden.\n";
  }
}
