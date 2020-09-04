/* cppbuch/loesungen/k2/3.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

long fakultaet(int n);

int main() {
  cout << "Ganze Zahl >= 0 eingeben: ";
  int n;
  cin >> n;
  cout << n << "! = " << fakultaet(n) << '\n';
}

long fakultaet(int n) {
  if (n < 2) {
    return 1;  // Rekursionsabbruch
  }
  return n * fakultaet(n - 1);
}
