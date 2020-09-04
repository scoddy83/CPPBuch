/* cppbuch/k6/privateVererbung/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel zur Warteschlange mit string_view-Objekten
#include <iostream>
#include <string_view>
//#include"warteschlange.t"  // eins auswählen
#include "warteschlangeD.t"

int main() {
  Warteschlange<std::string_view> fifo;
  fifo.push("eins");
  fifo.push("zwei");
  fifo.push("drei");

  while (!fifo.empty()) {
    std::cout << fifo.size() << " Element(e) vorhanden!\n";
    auto buf = fifo.front();  // lesen
    std::cout << "Element " << buf << " entnommen\n";
    fifo.pop();  // löschen
  }
  std::cout << "Liste ist leer!\n";
}
