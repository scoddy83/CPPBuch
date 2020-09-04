/* cppbuch/k1/climits.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Grenzwerte für ganze Zahlen basierend auf der
// C-Programmiersprache:
#include <climits>  // hier sind die Bereichsinformationen
#include <iostream>
using namespace std;

int main() {
  cout << "Grenzwerte für Ganzzahl-Typen:\n";

  cout << "INT_MIN =       " << INT_MIN << '\n';
  cout << "INT_MAX =       " << INT_MAX << '\n';
  cout << "LONG_MIN =      " << LONG_MIN << '\n';
  cout << "LONG_MAX =      " << LONG_MAX << '\n';
  cout << "LLONG_MIN =     " << LLONG_MIN << '\n';
  cout << "LLONG_MAX =     " << LLONG_MAX << '\n';
  cout << "unsigned-Grenzwerte:\n";
  cout << "UINT_MAX =      " << UINT_MAX << '\n';
  cout << "ULONG_MAX =     " << ULONG_MAX << '\n';
  cout << "ULLONG_MAX =    " << ULLONG_MAX << '\n';
}
