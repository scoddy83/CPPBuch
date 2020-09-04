/* cppbuch/k24/verzeichnisanlegen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Verzeichnis anlegen\n"
                 "Gebrauch: verzeichnisanlegen.exe name\n";
  } else {
    if (!fs::create_directory(fs::path(argv[1]))) {
      std::cerr << argv[1] << " existiert bereits!\n";
    }
  }
}
