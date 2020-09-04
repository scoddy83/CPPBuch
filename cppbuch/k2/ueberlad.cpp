/* cppbuch/k2/ueberlad.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

double maximum(double x, double y) {
  return x > y ? x : y;  // Bedingungsoperator siehe Seite
                         // \pageref{Bedingungsoperator}
}

// zweite Funktion gleichen Namens, aber unterschiedlicher Signatur
int maximum(int x, int y) { return x > y ? x : y; }

int main() {
  double a = 100.2, b = 333.777;
  int c = 1700, d = 1000;
  cout << maximum(a, b) << '\n';  // Aufruf von maximum(double, double)
  cout << maximum(c, d) << '\n';  // Aufruf von maximum(int, int)

  constexpr float E{2.7182f};
  constexpr float PI{3.14159f};
  cout << maximum(E, PI) << '\n';
  cout << maximum(31, 'A') << '\n';

  cout << maximum(3.1, static_cast<float>(7)) << '\n';
  cout << maximum(3.1, static_cast<double>(7)) << '\n';
  int x = 66;
  char y = static_cast<char>(x);
  cout << maximum(static_cast<int>(0.1), static_cast<int>(y)) << '\n';
  // Voraussetzung: \tt{char} ist \tt{signed char}.
  // Aufgerufen wird \tt{maximum(int, int)}.
  cout << maximum(-1000, static_cast<char>(600)) << '\n';  // ergibt 88
  cout << maximum(-1000, static_cast<char>(128)) << '\n';  // ergibt -128
  cout << maximum(-1000, static_cast<char>(129)) << '\n';  // ergibt -127 usw
}
