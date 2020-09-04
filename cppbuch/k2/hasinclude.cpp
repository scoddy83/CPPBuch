/* cppbuch/k2/hasinclude.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>

#if __has_include(<filesystem>)
  #include <filesystem>
  std::string meldung = "<filesystem> inkludiert.";
#elif __has_include(<experimental/filesystem>)
  #include <experimental/filesystem>
  std::string meldung = "<experimental/filesystem> inkludiert.";
#else
  std::string meldung = "filesystem-Header nicht gefunden";
#endif

int main() {
  std::cout << meldung << '\n';
}
