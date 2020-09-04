/* cppbuch/k2/kleiner.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

template <typename T> bool kleiner(const T& a, const T& b) {  // Vergleich
  cout << "Template\n";
  return (a < b);
}

template <> bool kleiner(const int& a, const int& b) {  // spezialisiert
  cout << "spezialisiertes Template\n";
  return (a < b);
}

bool kleiner_func(int a, int b) {  // gewöhnliche Funktion
  cout << "gewöhnliche Funktion\n";
  return (a < b);
}

int main() {
  // Template, Ausgabe 1.9:
  cout << (kleiner(1.9, 9.7) ? 1.9 : 9.7) << '\n';

  // spez. Template oder Funktion , Ausgabe 3
  cout << (kleiner(3, 6) ? 3 : 6) << '\n';

  // Die folgende Zeile wird nicht kompiliert. Bei Templates ist die
  // Typprüfung schärfer.
  // cout <<  (kleiner(3.1, 3) ? 3.1 : 3.0) << '\n';

  // wird kompiliert, liefert aber ein falsches Ergebnis wegen des
  // Genauigkeitsverlust bei der Umwandlung!
  cout << (kleiner_func(3.1, 3.3) ? 3.1 : 3.3) << '\n';
}
