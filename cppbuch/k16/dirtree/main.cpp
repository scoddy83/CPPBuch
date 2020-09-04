/* cppbuch/k16/dirtree/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc > 2) {
    cout << "Verzeichnisbaum anzeigen\n"
            "Gebrauch: tree.exe [name]\n";
  } else {
    string verz(".");  // aktuelles Verzeichnis
    if (argc > 1) {
      verz = argv[1];
    }
    try {
      baumAnzeigen(verz);
    } catch (const exception& e) {
      cerr << argv[1] << ": Fehler: " << e.what() << '\n';
    }
  }
}
