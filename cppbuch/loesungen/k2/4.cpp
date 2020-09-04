/* cppbuch/loesungen/k2/4.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

void bewegen(int n, int a, int b, int c) {
  while (n > 0) {
    bewegen(n - 1, a, c, b);
    cout << "Bringe eine Scheibe von " << a << " nach " << b << '\n';
    --n;
    int t = a;
    a = c;
    c = t;
  }
}

int main() {
  cout << "Türme von Hanoi! Anzahl der Scheiben: ";
  int scheiben;
  cin >> scheiben;
  bewegen(scheiben, 1, 2, 3);
}
