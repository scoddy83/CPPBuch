/* cppbuch/k24/loeschen_ec.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/filesystem>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Datei oder leeres Verzeichnis loeschen\n"
                 "Gebrauch: loeschen_ec.exe name\n";
  } else {
    std::error_code ec;
    if (std::experimental::filesystem::remove(
            std::experimental::filesystem::path(argv[1]), ec)) {
      std::cout << argv[1] << " wurde gelöscht.\n";
    } else {
      std::cout << argv[1] << " existiert nicht.\n";
    }
    std::cout << "error_code: Wert: " << ec.value()
              << "  Text: " << ec.message() << '\n';
  }
}
