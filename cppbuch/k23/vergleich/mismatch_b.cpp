/* cppbuch/k23/vergleich/mismatch_b.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <algorithm>
#include <cmath>  // \tt{fabs()}
#include <cstddef>
#include <showContainer.h>
#include <vector>
using namespace std;

class VergleichMitToleranz {
public:
  VergleichMitToleranz(double e) : eps(e) {}
  bool operator()(double x, double y) { return fabs(x - y) < eps; }

private:
  double eps;
};

int main() {
  vector<double> v1(8);
  vector<double> v2(8);
  Random zufall(100);
  for (size_t i = 0; i < v1.size(); ++i) {
    v1[i] = i + zufall() / 10000.0;
    v2[i] = i + zufall() / 10000.0;
  }
  showContainer(v1);  // Anzeige
  showContainer(v2);

  // Prüfung mit Iterator Paar \tt{wo}
  auto wo =
      mismatch(v1.begin(), v1.end(), v2.begin(), VergleichMitToleranz(0.01));
  if (wo.first == v1.end()) {
    cout << "Inhalt der Container stimmt innerhalb der Toleranz "
            "überein.\n";
  } else {
    cout << "Der erste Unterschied (" << *wo.first << " != " << *wo.second
         << ") wurde an Position " << (wo.first - v1.begin())
         << " gefunden.\n";
  }
}
