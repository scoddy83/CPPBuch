/* cppbuch/k26/string2int.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cctype>
#include <iostream>
#include <optional>
#include <string>
 
// optional kann als Rückgabetyp verwendet werden, wenn die Funktion evtl. kein Ergebnis liefert.
std::optional<int> string2int(const std::string& str) {
  // eigener Algo, weil std::stoi() ggf. Exception wirft
  bool istNegativ = false;
  unsigned int start = 0;
  if(str[start] == '-') {
    istNegativ = true;
    ++start;
  }
  int ergebnis = 0;
  bool gefunden = false;
  while(start < str.size() && isdigit(str[start])) {
    ergebnis = 10*ergebnis + (str[start] - '0');
    gefunden = true;
    ++start;
  }
  if(gefunden) {
    if(istNegativ) {
      ergebnis = -ergebnis;
    }
    return ergebnis;
  }
  return std::nullopt;
}
 
int main() {
  for(int i = 0; i < 3; ++i) {
    std::string str;
    switch (i) {
       case 0  : str = "42 oder ... "; break;
       case 1  : str = "-1 ist legal"; break;
       default : str = " keine Zahl ";
    }
    auto result = string2int(str);
    std::cout << "string2int(" << str << ") : ";
    if(result) {                            // entspricht \tt{if(result.has\_value())} 
      std::cout << result.value();
    }
    else {
      std::cout << "keine Zahl gefunden";
    }
    // oder:
    std::cout << ". value_or() ergibt " << result.value_or(9999) << '\n';
  }
}
