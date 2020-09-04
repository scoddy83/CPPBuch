/* cppbuch/k23/folgen/rotate.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <numeric>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> v(10);
  iota(v.begin(), v.end(), 0);

  for (size_t shift = 1; shift < 3; shift++) {
    cout << "Rotation um " << shift << '\n';
    for (size_t i = 0; i < v.size() / shift; ++i) {
      showContainer(v);
      rotate(v.begin(), v.begin() + shift, v.end());
    }
  }
  cout << "Rotation mit Kopie:\n";
  vector<int> erg(10);
  rotate_copy(v.begin(), v.begin() + 3, v.end(), erg.begin());
  showContainer(erg);
}
