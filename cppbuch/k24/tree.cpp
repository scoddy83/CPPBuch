/* cppbuch/k24/tree.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
#if __has_include(<filesystem>)
   #include <filesystem>
   namespace fs = std::filesystem;  // zur Abkürzung
#else
  #include <experimental/filesystem>
  namespace fs = std::experimental::filesystem;  // zur Abkürzung
#endif

int main(int argc, char* argv[]) {
  if (argc > 2) {
    std::cout << "Gebrauch: tree.exe [name]\n";
  } else {
    std::string verz(".");  // aktuelles Verzeichnis
    if (argc > 1) {
      verz = argv[1];
    }
    std::cout << verz << '\n';
    fs::path start(verz);
    fs::recursive_directory_iterator di(start), ende;
    while (di != ende) {
      for (int i = 0; i < di.depth(); ++i) {
        std::cout << " |  ";
      }
      std::cout << " |-- " << di->path().filename().string() << '\n';
      ++di;
    }
  }
}
