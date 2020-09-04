/* cppbuch/k24/loeschen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Datei oder leeres Verzeichnis loeschen\n"
                 "Gebrauch: loeschen.exe name\n";
  } else {
    try {
      std::experimental::filesystem::remove(
          std::experimental::filesystem::path(argv[1]));
    } catch (const std::exception& e) {
      std::cerr << e.what() << '\n';
    }
  }
}
