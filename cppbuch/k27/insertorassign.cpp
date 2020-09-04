/* cppbuch/k27/insertorassign.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, std::string> woerterbuch1;
  woerterbuch1.insert({"Buch", "book"});
  woerterbuch1.insert({"Gesellschaft", "society"});
  // Die folgende Anweisung ist ohne Wirkung, weil der Schlüssel schon existiert:
  woerterbuch1.insert({"Gesellschaft", "company"});
  // insert_or_assign() bewirkt dennoch eine Änderung:
  woerterbuch1.insert_or_assign("Gesellschaft", "company");
  // Falls der Schlüssel nicht existiert, wird der Eintrag neu angelegt:
  woerterbuch1.insert_or_assign("Lehrer", "teacher");  // neu 
  std::cout << "Wörterbuch 1:\n";
  for (const auto& eintrag : woerterbuch1) {
    std::cout << eintrag.first << " : " << eintrag.second << '\n';   // Schlüssel, Daten
  }
}
