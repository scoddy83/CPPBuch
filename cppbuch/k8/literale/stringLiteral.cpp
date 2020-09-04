/* cppbuch/k8/literale/stringLiteral.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>

std::string operator"" _str(const char* s, std::size_t sz) { // sz wird nicht gebraucht
  return std::string(s);
}

int main() {
  // Anwendung des obigen Operators
  std::string s0 = "123"_str + "abc"_str;   // Verkettung
  std::cout << s0 << '\n';                  // 123abc

  // Anwendung des C++-Standard-Operators
  using namespace std::literals::string_literals;
  std::string s1 = "123"s + "abc"s;
  std::cout << s1 << '\n';
}
