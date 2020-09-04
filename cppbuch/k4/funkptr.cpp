/* cppbuch/k4/funkptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
using namespace std;

int max(int x, int y) { return x > y ? x : y; }

int min(int x, int y) { return x < y ? x : y; }

int main() {
  int a{1700};
  int b{1000};

  // \tt{fp} ist Zeiger auf eine Funktion
  int (*fp)(int, int);

  do {
    char c;
    cout << "max (1) oder min (0) ausgeben (sonst = Ende) ?";
    cin >> c;

    // Zuweisung von \tt{max()} oder \tt{min()}
    // (ohne Angabe von Klammern nach dem Funktionsnamen)
    switch (c) {
    case '0':
      fp = &min;
      break;
    case '1':
      fp = max;
      break;
    default:
      fp = NULL;
    }
    if (fp) {
      // Dereferenzierung des Funktionszeigers und Aufruf
      cout << (*fp)(a, b) << '\n';
      // oder auch direkte Verwendung des Namens (implizite
      // Typumwandlung)
      cout << fp(a, b) << '\n';
    }
  } while (fp);
}
