/* cppbuch/loesungen/k2/5.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>

void str_umkehr(std::string& s);

int main() {
  std::cout << "Reihenfolge der Zeichen umdrehen. Eingabe einer "
               "Zeichenkette:";
  std::string str;
  std::cin >> str;
  str_umkehr(str);
  std::cout << str << '\n';
}

void str_umkehr(std::string& s) {  // dreht die Reihenfolge der Zeichen um
  size_t links{0};
  size_t rechts{s.length() - 1};
  while (links < rechts) {
    char temp{s[links]};
    s[links++] = s[rechts];
    s[rechts--] = temp;
  }
}
