/* cppbuch/k23/strings/string2zahl/sstream.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  cout << "Bitte Zeichenkette eingeben (z.B. 3.14 12345) : ";
  string zeile;
  getline(cin, zeile);
  stringstream wandler;
  wandler << zeile;  // String schreiben
  double d;
  wandler >> d;  // als double-Zahl lesen
  cout << "Zahl =" << d << '\n';
}
