/* cppbuch/k1/menu.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  while (true) {  // unendliche Schleife
    char c;
    cout << "Wählen Sie: a, b, x = Ende : ";
    cin >> c;

    if (c == 'a') {
      cout << "Programm a\n";
      continue;  // zurück zur Auswahl
    }

    if (c == 'b') {
      cout << "Programm b\n";
      continue;  // zurück zur Auswahl
    }

    if (c == 'x') {
      break;  //  Schleife verlassen
    }
    cout << "Falsche Eingabe! Bitte wiederholen!\n";
  }
  cout << "\n Programmende mit break\n";
}
