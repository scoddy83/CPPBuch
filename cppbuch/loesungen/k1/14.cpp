/* cppbuch/loesungen/k1/14.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  cout << "Bitte eine Startzahl > 0 eingeben: ";
  long long zahl;
  cin >> zahl;
  cin.ignore(1000, '\n');  // Tastaturpuffer löschen
  int iterationen = 0;
  long long maxzahl = 0LL;
  while (zahl > 1) {
    ++iterationen;
    if (zahl % 2 == 0) {  // Zahl ist gerade
      zahl /= 2;
    } else {
      zahl = 3 * zahl + 1;
    }
    cout << zahl << '\n';
    if (maxzahl < zahl) {
      maxzahl = zahl;
      cout << " neues Maximum. Weiter mit ENTER\n";
      string dummy;
      getline(cin, dummy);  // weiter mit Tastendruck
    }
  }
  cout << iterationen << " Iterationen. Maximale Zahl = " << maxzahl << '\n';
}
