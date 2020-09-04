/* cppbuch/k9/quoted.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  std::string text = "abc \"def\" ijk";
  std::cout << text << '\n';               //  abc "def" ijk
  std::cout << std::quoted(text) << '\n';  //  "abc \"def\" ijk"

  std::cout << "Text eingeben:\n";
  std::cin >> std::quoted(text);           //  "abc \"def\" ijk"
  std::cout << text << '\n';               //  abc "def" ijk
  std::cout << std::quoted(text) << '\n';  //  "abc \"def\" ijk"

  std::cout << "Text eingeben:\n";
  std::cin >> text;           //  "abc \"def\" ijk"
  std::cout << text << '\n';  //  "abc
}
