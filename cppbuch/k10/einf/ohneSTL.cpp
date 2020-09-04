/* cppbuch/k10/einf/ohneSTL.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

// neuer Typname IteratorType für `Zeiger auf const int'
using IteratorType = const int*;

// Prototyp des Algorithmus
IteratorType find(IteratorType begin, IteratorType end, int wert);

int main() {
  constexpr int ANZAHL{100};
  int einContainer[ANZAHL];          // Container definieren
  IteratorType begin{einContainer};  // Zeiger auf den Anfang
  //  Position NACH dem letzten Element
  IteratorType end{einContainer + ANZAHL};

  // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
  for (unsigned int i = 0; i < ANZAHL; ++i) {
    einContainer[i] = 2 * i;
  }

  int zahl{0};
  while (zahl != -1) {
    std::cout << " gesuchte Zahl eingeben (-1 = Ende):";
    std::cin >> zahl;
    if (zahl != -1) {  // weitermachen?
      IteratorType position = find(begin, end, zahl);
      if (position != end) {
        std::cout << "gefunden an Position " << (position - begin) << '\n';
      } else {
        std::cout << zahl << " nicht gefunden!\n";
      }
    }
  }
}

// Implementation
IteratorType find(IteratorType begin, IteratorType end, int wert) {
  while (begin != end          // Zeigervergleich
         && *begin != wert) {  // Dereferenzierung und Objektvergleich
    ++begin;                   // nächste Stelle
  }
  return begin;
}
