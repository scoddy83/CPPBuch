/* cppbuch/k23/folgen/adjacent_difference.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <numeric>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<long> v(10);
  iota(v.begin(), v.end(), 0);  // 0 1 2 3 4 5 6 7 8 9
  vector<long> adjacDiff(10);
  cout << "Differenzen     = ";
  adjacent_difference(v.begin(), v.end(), adjacDiff.begin());
  showContainer(adjacDiff);  // 0 1 1 1 1 1 1 1 1 1

  vector<int> fib(16);  // für Fibonacci-Zahlen
  fib[0] = 1;           // Anfangswert
  /* {\em Ein} Startwert genügt hier, weil der erste Wert
  an Position 1 eingetragen wird (Formel $e_i = v_i - v_{i-1}$
  oben)
  und damit sich der zweite Wert von selbst ergibt
  (beachte den um 1 verschobenen \tt{result}-Iterator in der
  Parameterliste).*/

  cout << "Fibonacci-Zahlen  = ";
  adjacent_difference(fib.begin(), fib.end() - 1, fib.begin() + 1,
                      plus<int>());
  showContainer(fib);
  // 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987
}
