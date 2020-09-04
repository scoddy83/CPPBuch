/* cppbuch/loesungen/k1/4.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Maximum dreier Zahlen ausgeben
#include <iostream>
using namespace std;

int main() {
  cout << "Maximum dreier Zahlen! Eingabe: ";
  int a, b, c;
  cin >> a >> b >> c;
  cout << " Maximum = ";
  if (a > b) {
    if (a > c) {
      cout << a;
    } else {
      cout << c;
    }
  } else {
    if (b > c) {
      cout << b;
    } else {
      cout << c;
    }
  }
  cout << '\n';
}
