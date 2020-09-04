/* cppbuch/k23/finden/search_Searcher.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <experimental/algorithm>
#include <experimental/functional>
#include <iostream>
#include <string_view>

int main() {
  std::string_view zudurchsuchen = "Ist dies schon Tollheit, hat es doch Methode.";
  std::string_view gesucht = "Tollheit";
  auto iter = std::experimental::search(
      zudurchsuchen.begin(), zudurchsuchen.end(),
      std::experimental::make_default_searcher(gesucht.begin(), gesucht.end()));
  if (iter != zudurchsuchen.end()) {
    std::cout << "'" << gesucht << "' beginnt an Position "
              << iter - zudurchsuchen.begin() << '\n';
  } else {
    std::cout << "'" << gesucht << "' nicht gefunden\n";
  }
}
