/* cppbuch/loesungen/k1/5.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Zahl binär ausgeben
#include <iostream>
using namespace std;

int main() {
  cout << "Eingabe einer Zahl: ";
  int zahl = 0;
  cin >> zahl;
  int anzahlDerBytes = sizeof zahl;
  int anzahlDerBits = 8 * anzahlDerBytes;
  cout << " binär :  ";
  for (int k = anzahlDerBits - 1; k >= 0; --k) {
    if (zahl & (1 << k)) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '\n';
}
/*
Bemerkung: Die 1 in der if(...)-Bedingung ist vom Typ
int. Sie muss durch mindestens so viele Bits wie zahl
repräsentiert werden. Wenn zahl als long deklariert werden
soll, ist daher 1L zu schreiben.
*/
