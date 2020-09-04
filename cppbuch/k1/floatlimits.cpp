/* cppbuch/k1/floatlimits.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <limits>  // hier sind die Bereichsinformationen

using namespace std;

int main() {
  cout << "Grenzwerte für Float-Zahl-Typen:" << '\n';
  cout << "Float-Min: " << numeric_limits<float>::min() << '\n';
  cout << "Float-Max: " << numeric_limits<float>::max() << '\n';
  cout << "Double-Min: " << numeric_limits<double>::min() << '\n';
  cout << "Double-Max: " << numeric_limits<double>::max() << '\n';
  cout << "Long-Double-Min: " << numeric_limits<long double>::min() << '\n';
  cout << "Long-Double-Max: " << numeric_limits<long double>::max() << '\n';
  cout << "Anzahl der Bytes für:" << '\n';
  cout << "float         " << sizeof(float) << '\n';
  cout << "double        " << sizeof(double) << '\n';
  cout << "long double   " << sizeof(long double) << '\n';
  cout << "float- und double-Zahlen entsprechen";
  if (!numeric_limits<float>::is_iec559) {
    cout << " nicht";
  }
  cout << " dem IEC 559 (=IEEE 754)-Standard.\n";
  cout << "Bits für die Mantisse inkl. Vorzeichen-Bit:\n";
  cout << numeric_limits<float>::digits << '\n';
  cout << numeric_limits<double>::digits << '\n';
  cout << numeric_limits<long double>::digits << '\n';
  cout << "Genauigkeit in Dezimalstellen:" << '\n';
  cout << numeric_limits<float>::digits10 << '\n';
  cout << numeric_limits<double>::digits10 << '\n';
  cout << numeric_limits<long double>::digits10 << '\n';
  cout << "max.Exponent binär und dezimal:" << '\n';
  cout << numeric_limits<float>::max_exponent << '\t';
  cout << numeric_limits<float>::max_exponent10 << '\n';
  cout << numeric_limits<double>::max_exponent << '\t';
  cout << numeric_limits<double>::max_exponent10 << '\n';
  cout << numeric_limits<long double>::max_exponent << '\t';
  cout << numeric_limits<long double>::max_exponent10 << '\n';
}
