/* cppbuch/k10/einf/mitVector.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>

// Prototyp des Algorithmus ersetzt durch Template
template <class Iterator, typename T>
Iterator find(Iterator begin, Iterator end, const T& wert) {
  while (begin != end          // Zeigervergleich
         && *begin != wert) {  // Dereferenzierung und Objektvergleich
    ++begin;                   // nächste Stelle
  }
  return begin;
}

int main() {
  std::vector<int> einContainer(100);  // Container definieren

  // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
  for (unsigned int i = 0; i < einContainer.size(); ++i) {
    einContainer[i] = 2 * i;
  }

  int zahl{0};
  while (zahl != -1) {
    std::cout << " gesuchte Zahl eingeben (-1 = Ende):";
    std::cin >> zahl;
    if (zahl != -1) {  // weitermachen?
      // globales find() von oben benutzen

      auto position =                   // \tt{auto} =
                                        // \tt{vector<int>::const\_iterator}
          ::find(einContainer.begin(),  // Container-Methoden
                 einContainer.end(), zahl);
      if (position != einContainer.end()) {
        std::cout << "gefunden an Position " << (position - einContainer.begin())
             << '\n';
      } else {
        std::cout << zahl << " nicht gefunden!\n";
      }
    }
  }
}
