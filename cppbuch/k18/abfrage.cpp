/* cppbuch/k18/abfrage.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Datenbank.h"
#include <iostream>

int main() {
  std::string zeile;
  std::cout << "Datenbankname: ";
  std::getline(std::cin, zeile);
  try {
    Datenbank db(zeile.c_str());
    do {
      std::cout << "SQL-Anweisung: ";
      std::getline(std::cin, zeile);
      if (zeile.length() > 0) {
        db.execute(zeile.c_str()).print();
      }
    } while (zeile.length() > 0);
  } catch (const SQLError& e) {
    std::cerr << e.what() << '\n';
  }
}
