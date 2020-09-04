/* cppbuch/k10/liste/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "liste.t"
#include <algorithm>
#include <iostream>

int main() {
  Liste<int> einContainer;  // Container definieren

  // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
  for (int i = 0; i < 100; ++i) {
    einContainer.push_front(2 * i);
  }
  int zahl{0};
  while (zahl != -1) {
    std::cout << " gesuchte Zahl eingeben (-1 = Ende):";
    std::cin >> zahl;
    if (zahl != -1) {  // weitermachen?
      // std::find() benutzen
      auto position = std::find(einContainer.begin(),  // Container-Methoden
                                einContainer.end(), zahl);
      if (position == einContainer.end()) {
        std::cout << " nicht gefunden!\n";
      } else {
        std::cout << *position  // Dereferenzierung des Iterators
                  << " gefunden!\n";
      }
    }
  }
  std::cout << "Liste ausgeben:\n";
  for (auto iter = einContainer.begin(); iter != einContainer.end(); ++iter) {
    std::cout << *iter << '\n';
  }
}
