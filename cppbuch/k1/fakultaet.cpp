/* cppbuch/k1/fakultaet.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  cout << "Fakultät berechnen. Zahl >= 0? :";
  unsigned int n;
  cin >> n;

  unsigned long fak{1L};
  for (unsigned int i = 2; i <= n; ++i) {
    fak *= i;
  }
  cout << n << "!   =   " << fak << '\n';
}
