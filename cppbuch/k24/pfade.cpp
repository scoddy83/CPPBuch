/* cppbuch/k24/pfade.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  std::cout << "Arbeitsverzeichnis (absolut): " << fs::current_path() << '\n';
  fs::path derPfad(".");    // aktuelles Verzeichnis
  derPfad.append(argv[0]);  // argv[0] = aufgerufenes Programm
  // derPfad /= argv[0];    // dito
  std::cout << "diese Datei: " << derPfad.filename() << '\n';
  std::cout << "Stamm      : " << derPfad.stem() << '\n';
  std::cout << "Extension  : " << derPfad.extension() << '\n';
  std::cout << "diese Datei (kanonisch): " << fs::canonical(derPfad) << '\n';
}
