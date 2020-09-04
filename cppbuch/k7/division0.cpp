/* cppbuch/k7/division0.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cfenv>
#include <iostream>
using namespace std;

float f(float a, float b) {
  float c = a / b;
  if (fetestexcept(FE_DIVBYZERO)) {         // abfragen
    feclearexcept(FE_DIVBYZERO);            // zurücksetzen
    throw("Fehler: Division durch 0!");
  }
  return c;
}

int main() {
  float z;
  float n;
  cout << "Zähler :";
  cin >> z;
  cout << "Nenner :";
  cin >> n;
  try {
    cout << "Ergebnis = " << f(z, n) << '\n';
  } catch (const char* ex) {
    cerr << ex << '\n';
  }
}
