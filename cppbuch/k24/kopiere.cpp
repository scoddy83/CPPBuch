/* cppbuch/k24/kopiere.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Datei oder Verzeichnis kopieren\n"
                 "Gebrauch: kopiere.exe Quelle Ziel\n";
  } else {
    std::error_code ec;
    fs::copy(fs::path(argv[1]), fs::path(argv[2]), ec);
    if (ec.value() != 0) {
      std::cerr << "Nichts kopiert: " << ec.message() << '\n';
    }
  }
}
