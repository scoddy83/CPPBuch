/* cppbuch/k31/stringview.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
#include <string_view>

int main() {
  std::string_view sv1 = "abcd12345";
  std::string_view sv2 = "6789";
  sv2 = sv1;  
  // Zuweisung:
  std::cout << sv2 << '\n';

  // Anfang und Ende verkürzen:
  sv2.remove_prefix(2);
  std::cout << sv2 << '\n';
  sv2.remove_suffix(1);
  std::cout << sv2 << '\n';

  // Teilstring extrahieren:
  std::string_view sv3 = sv2.substr(0, 3);
  // \tt{<\relax<} nimmt Rücksicht auf die Länge:
  std::cout << "sv3    = " << sv3 << '\n';
  // \tt{data()} nicht:
  std::cout << "data() = " << sv3.data() << '\n';

  // \tt{string\_view} aus \tt{string} erzeugen:
  std::string str {"stringview\n"};
  std::cout << str;
  std::string_view strv = str;
  str[0] = 'S';
  std::cout << strv;          // \tt{strv} erscheint geändert
}
