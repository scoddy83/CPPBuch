/* cppbuch/k24/verzeichnisloeschen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>
#include <string>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Verzeichnis loeschen\n"
                 "Gebrauch: verzeichnisloeschen.exe verzeichnisname\n";
  } else if (argv[1][0] == '.') {
    std::cout << ". nicht erlaubt. Nur für Unterverzeichnis aufrufen!\n";
  } else {
    fs::path pfad(argv[1]);
    if (fs::exists(pfad) && fs::is_directory(pfad)) {
      fs::remove_all(pfad);  // Rückgabewert ignoriert
    } else {
      std::cout << "Verzeichnis " << argv[1] << " existiert nicht!\n";
    }
  }
}
