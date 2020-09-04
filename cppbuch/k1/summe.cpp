/* cppbuch/k1/summe.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  int summe;
  int summand1;
  int summand2;

  // Lies zwei Zahlen ein
  cout << " Zwei ganze Zahlen eingeben:";
  cin >> summand1 >> summand2;
  /* Berechne die Summe beider Zahlen
   */
  summe = summand1 + summand2;

  // Zeige das Ergebnis auf dem Bildschirm an
  cout << "Summe=" << summe << '\n';

  // Falls die Entwicklungsumgebung dafür sorgt, dass das Fenster
  // lange genug offen bleibt, können die folgenden Zeilen entfernt
  // werden.
  cout << "Bitte drücken Sie Enter zum Beenden des Programms\n";
  cin.ignore(1000, '\n');
  cin.get();
  return 0;
}
