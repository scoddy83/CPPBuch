/* cppbuch/k1/dynvekt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>  // size_t
#include <iostream>
#include <vector>  // Standard-Vektor einschließen
using namespace std;

int main() {
  vector<int> meineDaten;  // anfängliche Größe ist 0
  cout << "Bitte Werte eingeben\n";

  int wert;
  do {
    cout << "Wert (0 = Ende der Eingabe):";
    cin >> wert;
    if (wert != 0) {
      meineDaten.push_back(wert);
    }
  } while (wert != 0);

  cout << "Es wurden die folgenden Werte eingegeben:\n";
  for (size_t i = 0; i < meineDaten.size(); ++i) {
    cout << i << ". Wert : " << meineDaten[i] << '\n';
  }
}
