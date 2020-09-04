/* cppbuch/k24/verzeichnisanzeigen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <ctime>
#include <experimental/filesystem>
#include <iostream>
#include <string>
namespace fs = std::experimental::filesystem;  // zur Abkürzung

int main(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Gebrauch: verzeichnisanzeigen.exe [name]\n";
  } else {
    std::string verz(".");  // aktuelles Verzeichnis
    if (argc > 1) {
      verz = argv[1];
    }
    try {
      fs::path pfad(verz);
      fs::directory_iterator di(pfad), ende;
      while (di != ende) {
        fs::path p = di->path();
        std::cout << p.filename() << '\t';
        if (fs::is_directory(p)) {
          std::cout << " (Verzeichnis)";
        } else {
          std::cout << fs::file_size(p) << " Bytes";
        }
        auto zeitpunkt = fs::last_write_time(p);
        // Umwandlung in String über time_t und ctime()
        std::time_t t = std::chrono::system_clock::to_time_t(zeitpunkt);
        std::cout << '\t' << std::ctime(&t);
        ++di;
      }
    } catch (const std::exception& e) {
      std::cerr << "Anzeige des Verzeichnisses " << argv[1]
                << " fehlgeschlagen: " << e.what() << '\n';
    }
  }
}
