/* cppbuch/k23/folgen/partialsum.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <numeric>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<long> v(10);
  vector<long> partialsummen(10);
  iota(v.begin(), v.end(), 1);  // natürliche Zahlen 1 bis 10
  partial_sum(v.begin(), v.end(), partialsummen.begin());
  cout << "Partialsummen    = ";
  showContainer(partialsummen);  // 1 3 6 10 15 21 28 36 45 55
  cout << "Folge von Fakuläten  = ";
  partial_sum(v.begin(), v.end(), v.begin(), multiplies<long>());
  showContainer(v);  // 1 2 6 24 120 720 5040 40320 362880 3628800
}
