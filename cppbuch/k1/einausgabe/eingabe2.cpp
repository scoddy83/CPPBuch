/* cppbuch/k1/einausgabe/eingabe2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Bitte Vor- und Nachnamen eingeben:";
  string derName;
  getline(cin, derName);
  cout << derName;
}
