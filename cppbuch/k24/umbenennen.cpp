/* cppbuch/k24/umbenennen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Datei oder Verzeichnis umbenennen\n"
                 "Gebrauch: umbenennen.exe altername neuername\n";
  } else {
    fs::rename(fs::path(argv[1]), fs::path(argv[2]));
  }
}
