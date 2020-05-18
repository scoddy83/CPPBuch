/* cppbuch/loesungen/k1/3.cpp
   Übung zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
*/
#include <iostream>
using namespace std;

int main() {
  int kleineZahl {0};
  int grosseZahl {0};
  int zahl {0};

  cout << "Bitte gebe die kleinste Zahl an: ";
  cin >> kleineZahl;

  while (kleineZahl > grosseZahl) {
    cout << "Bitte gebe die groesste Zahl an: ";
    cin >> grosseZahl;
    if(kleineZahl > grosseZahl) {
      cout << "FEHLER: Die zweite Zahl muss groesser wie die erste Zahl sein!" << '\n';
    }
  }

  cout << "Bitte gebe die Vergleichszahl an: ";
  cin >> zahl;

  if(kleineZahl < zahl && grosseZahl > zahl) {
    cout << "Perfekt! Die Zahl " << zahl << " befindet sich innerhalb des Bereichs zwischen " << kleineZahl << " und " << grosseZahl << '\n';
  } else {
    cout << "Schade! Die Zahl " << zahl << " befindet sich ausserhalb des Bereichs zwischen " << kleineZahl << " und " << grosseZahl << '\n';
  }

}
