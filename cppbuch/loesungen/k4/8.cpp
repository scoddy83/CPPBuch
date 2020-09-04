/* cppbuch/loesungen/k4/8.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstring>
#include <iostream>

void leerzeichenEntfernen(char* s) {
  char* q{s};
  do {
    if (*s != ' ') {
      *q++ = *s;
    }
  } while (*s++);
}

int main() {
  char str[] = "Leerzeichen  aus einer    Zeichenkette"
               " entfernen  ";
  std::cout << str << "\nLänge: " << std::strlen(str) << '\n';
  leerzeichenEntfernen(str);
  std::cout << str << "\nLänge: " << std::strlen(str) << '\n';
}
