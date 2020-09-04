/* cppbuch/k23/folgen/minmaxElement.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <numeric>
#include <showContainer.h>
#include <utility>                          // \tt{pair}
#include <vector>
using namespace std;

struct Absolutbetrag {              // Funktor, gekennzeichnet durch \tt{operator()()}
  bool operator()(int x, int y) { return abs(x) < abs(y); }
};

bool abskleiner(int x, int y) { return abs(x) < abs(y); }

int main() {
  vector<long> v(10);
  iota(v.begin(), v.end(), -5);                                      // -5 ... +4
  showContainer(v);
  cout << "Minimum: " << *min_element(v.begin(), v.end()) << '\n';   // -5
  cout << "Maximum: " << *max_element(v.begin(), v.end()) << '\n';   // 4

  cout << "Minimum des Absolutbetrags mit Funktor: "
       << *min_element(v.begin(), v.end(), Absolutbetrag()) << '\n';  // 0
  cout << "Minimum des Absolutbetrags mit Funktion: "
       << *min_element(v.begin(), v.end(), abskleiner) << '\n';      // 0
  cout << "Minimum des Absolutbetrags mit Lambda-Funktion: "
       << *min_element(v.begin(), v.end(),
                       [](auto a, auto b) { return abs(a) < abs(b);} ) << '\n'; // 0
  cout << "Minimum und Maximum mit nur einem Funktionsaufruf: ";
  auto iteratorPair = minmax_element(v.begin(), v.end());
  cout << *iteratorPair.first << "  " << *iteratorPair.second << '\n';
}
