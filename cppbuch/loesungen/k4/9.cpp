/* cppbuch/loesungen/k4/9.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Aufgabe:  Ausgabe von Dateien
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  std::cout << "Dateien ausgeben\n";
  if (argc == 1) {
    std::cout << "Keine Dateinamen in der Kommandozeile gefunden.\n"
                 "Gebrauch: "
              << argv[0]  // Programmname
              << " datei1 datei2 usw.\n";
    return 0;
  }
  int nr{0};
  while (argv[++nr] != 0) {
    std::ifstream quelle(argv[nr], std::ios::binary);
    std::cout << "Datei " << argv[nr];
    if (!quelle) {  // Fehlerabfrage
      std::cout << " nicht gefunden.\n";
      continue;  // weiter bei while
    }
    std::cout << ":\n";
    char ch;
    while (quelle.get(ch)) {
      std::cout << ch;  // zeichenweise ausgeben
    }
    quelle.close();
  }
}
