/* cppbuch/loesungen/k5/2/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "format.h"
#include <iostream>
using namespace std;

int main() {

  Format f(12, 3);
  cout << "789.906625        :" << f.toString(789.906625) << '\n';
  cout << "-123456789.906625 :" << f.toString(-123456789.906625) << '\n';
  cout << "-0,00123456789    :" << f.toString(-0.00123456789) << '\n';
  cout << "0,00              :" << f.toString(0.00) << '\n';
  cout << "-12345.6789906625 :" << f.toString(-12345.6789906625) << '\n';
  cout << "1.00000           :" << f.toString(1.0) << '\n';

  Format fi(12, 0);

  cout << "123               :" << fi.toString(123) << '\n';
  cout << "-123456789.906625 :" << fi.toString(-123456789.906625) << '\n';
}
