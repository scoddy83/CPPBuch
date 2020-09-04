/* cppbuch/loesungen/k4/10.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Aufgabe   Ausgabe von Namen in einer Datei
#include <fstream>
#include <iostream>

bool istBuchstabe(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

bool istAlphanumerisch(char c) {
  return (c >= '0' && c <= '9') || istBuchstabe(c);
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Kein Dateiname in der Kommandozeile gefunden.\n"
                 "Gebrauch: "
              << argv[0]  // Programmname
              << " dateiname\n";
    return 0;
  }

  std::ifstream quelle(argv[1]);
  if (!quelle) {  // Fehlerabfrage
    std::cout << "Datei " << argv[1] << " nicht gefunden.\n";
    return 0;
  }

  char ch;
  bool namengefunden{false};
  while (quelle.get(ch)) {
    if (istBuchstabe(ch)) {
      std::cout << ch;
      namengefunden = true;
    } else if (namengefunden && istAlphanumerisch(ch)) {
      std::cout << ch;
    } else if (namengefunden) {
      namengefunden = false;
      std::cout << '\n';
    }
  }
  // quelle.close();  // macht der Destruktor
}
