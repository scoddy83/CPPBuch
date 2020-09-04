/* cppbuch/k23/mengen/set_algorithmen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <set>
#include <showContainer.h>
using namespace std;

int main() {
  //  Sets initialisieren.  Vergleichsobjekt: \tt{less<int>()}
  // (implizite automatische Sortierung).
  set<int> s1{1, 2, 3, 4};
  set<int> s2{0, 1, 2, 3, 4, 5, 7, 99, 13};
  set<int> s3{-2, 5, 12, 7, 33};

  if (includes(s2.begin(), s2.end(), s1.begin(), s1.end())) {
    showContainer(s1);  // 1 2 3 4
    cout << " ist eine Teilmenge von ";
    showContainer(s2);  // 0 1 2 3 4 5 7 99
  }

  set<int> result;  // leere Menge (s1, s2, s3 wie oben)
  set_union(s1.begin(), s1.end(), s3.begin(), s3.end(),
            inserter(result, result.begin()));

  showContainer(s1);  // 1 2 3 4
  cout << " vereinigt mit ";
  showContainer(s3);  // -2 5 7 12 33
  cout << " ergibt ";
  showContainer(result);  // -2 1 2 3 4 5 7 12 33

  result.clear();  // Set leeren
  set_intersection(s2.begin(), s2.end(), s3.begin(), s3.end(),
                   inserter(result, result.begin()));

  showContainer(s2);  // 0 1 2 3 4 5 7 99
  cout << " geschnitten mit ";
  showContainer(s3);  // -2 5 7 12 33
  cout << " ergibt ";
  showContainer(result);  // 5 7

  result.clear();
  set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(),
                 inserter(result, result.begin()));
  showContainer(s2);  // 0 1 2 3 4 5 7 99
  cout << " minus ";
  showContainer(s1);  // 1 2 3 4
  cout << " ergibt ";
  showContainer(result);  // 0 5 7 99

  result.clear();
  set_symmetric_difference(s2.begin(), s2.end(), s3.begin(), s3.end(),
                           inserter(result, result.begin()));

  showContainer(s2);  // 0 1 2 3 4 5 7 99
  cout << "  exklusiv oder ";
  showContainer(s3);  // -2 5 7 12 33
  cout << " ergibt ";
  showContainer(result);  // -2 0 1 2 3 4 12 33 99
}
