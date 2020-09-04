/* cppbuch/k23/strings/zahl2string/sstream.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  cout << "Bitte double-Zahl eingeben : ";
  double d;
  cin >> d;
  stringstream wandler;
  wandler << d;  // Zahl schreiben
  string zahlAlsString;
  wandler >> zahlAlsString;  // als String lesen
  cout << "String =" << d << '\n';
}
