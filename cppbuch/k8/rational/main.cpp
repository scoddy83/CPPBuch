/* cppbuch/k8/rational/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Testprogramm für Klasse Rational mit Operatoren
// nur Additions und Ausgabeoperator
#include "ratioop.h"
#include <iostream>
using namespace std;

// nur Addition a und b, Rest fehlt
void druckeTestfall(Rational a, Rational b) {
  cout << "a = ";
  cout << a << '\n';
  cout << "b = ";
  cout << b << '\n';
  cout << "+  : ";
  cout << (a + b) << '\n';
  if (a == b)  // boolscher Operator
    cout << a << " == " << b << '\n';
  else
    cout << a << " != " << b << '\n';
  cout << "a += b = ";
  a += b;
  cout << a << '\n';
}

int main() {
  cout << "Test des Eingabeoperators\n"
          "Bitte Zähler und Nenner der 1. Zahl durch Leerzeichen "
          "getrennt eingeben:";
  Rational a;
  cin >> a;
  cout << "Bitte Zähler und Nenner der 2. Zahl durch Leerzeichen "
          "getrennt eingeben:";
  Rational b;
  cin >> b;
  druckeTestfall(a, b);

  cout << "\n Test mit verschiedenen Vorzeichen\n";
  a.set(3, 7);
  b.set(6, 13);
  druckeTestfall(a, b);
  a.set(3, -7);
  druckeTestfall(a, b);
  a.set(-3, -7);
  druckeTestfall(a, b);
  a.set(-3, -17);
  b.set(-6, -13);
  druckeTestfall(a, b);

  cout << "\n Test mit Nullwerten\n";
  // Nenner = 0 nach Test auskommentieren
  a.set(0, 7);
  b.set(6, 13);
  druckeTestfall(a, b);
  a.set(3, 7);
  b.set(0, 3);
  druckeTestfall(a, b);

  cout << "\n Test mit gemischten Datentypen\n";
  a.set(2301, 77777);
  druckeTestfall(a, 17);
  druckeTestfall(17, a);

  cout << "\n Test mit gemischten Datentypen, Zahlen < 0\n";
  druckeTestfall(a, -17);
  druckeTestfall(-17, a);
  cin.get();
}
