/* cppbuch/k9/sstream/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "zahlToString.h"
#include <iostream>

using namespace std;

int main() {
  double xd = 73.1635435363;                   // Ausgabe:
  cout << zahlToString(xd) << '\n';            // 73.1635
  cout << zahlToString(xd, 12) << '\n';        //     73.1635
  cout << zahlToString(xd, 12, 1) << '\n';     //  7.3164e+01
  cout << zahlToString(xd, 12, 1, 3) << '\n';  //   7.316e+01
  cout << zahlToString(xd, 12, 0, 3) << '\n';  //      73.164

  int xi = 1234567;
  cout << zahlToString(xi) << '\n';      // 1234567
  cout << zahlToString(xi, 14) << '\n';  //       1234567

  float xf = 1234.567f;
  cout << zahlToString(xf) << '\n';  // 1234.57
  unsigned long xl = 123456789L;
  cout << zahlToString(xl) << '\n';  // 123456789
}
