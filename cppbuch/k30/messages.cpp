/* cppbuch/k30/messages.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
#include <string_view>

int main() {
  // Funktioniert nicht unter Windows.
  // MinGW für Windows hat keine locale außer C und "" implementiert.
  std::locale loc("de_DE.UTF-8");
  std::cout.imbue(loc);
  auto& facet = std::use_facet<std::messages<char>>(loc);
  std::string_view software {"grep"}; 
  auto cat = facet.open(software.data(), loc);
  if (cat < 0) {
    std::cout << "Deutscher " << software 
              << "-Message-Katalog kann nicht geöffnet werden\n";
  }
  else {
    std::cout << "invalid character class -> "
              << facet.get(cat, 0, 0, "invalid character class") << '\n'
              << "no syntax specified     -> "
              << facet.get(cat, 0, 0, "no syntax specified") << '\n'
              << "unbalanced (            -> "
              << facet.get(cat, 0, 0, "unbalanced (") << '\n'
              << "write error             -> "
              << facet.get(cat, 0, 0, "write error") << '\n';
  }
  facet.close(cat);
}
