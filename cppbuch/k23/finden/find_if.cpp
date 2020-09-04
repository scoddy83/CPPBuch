/* cppbuch/k23/finden/find_if.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v{2, 4, 6, 8, 99, 12, 14};  // enthält ungerade Zahl
  showContainer(v);

  // nach ungerader Zahl suchen
  auto iter = find_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; });
  if (iter != v.end()) {
    cout << "Die erste ungerade Zahl (" << *iter << ") wurde an Position "
         << (iter - v.begin()) << " gefunden.\n";
  } else {
    cout << "Keine ungerade Zahl gefunden.\n";
  }
}
