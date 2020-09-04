/* cppbuch/k1/einausgabe/boolalpha.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  bool istGrossBuchstabe;
  char c;
  cin >> c;
  istGrossBuchstabe = (c >= 'A') && (c <= 'Z');
  cout.setf(ios_base::boolalpha);     // Textformat einschalten
  cout << istGrossBuchstabe << '\n';  // Wandlung in Text
  cout.unsetf(ios_base::boolalpha);   // Textformat ausschalten
  cout << istGrossBuchstabe << '\n';  // 1 oder 0
}
