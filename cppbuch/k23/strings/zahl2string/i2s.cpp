/* cppbuch/k23/strings/zahl2string/i2s.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <limits>
#include <iostream>
#include <string>
#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n';

namespace {
std::string i2string(int i) {
  std::string ergebnis;
  if (i == 0) {
    ergebnis = "0";
  } else {
    bool negativ = (i < 0);
    while (i != 0) {
      ergebnis.insert(ergebnis.begin(), abs(i % 10) + '0');
      i /= 10;
    }
    if (negativ) {
      ergebnis.insert(ergebnis.begin(), '-');
    }
  }
  return ergebnis;
}
}

int main() {
  PRINT(i2string(1 << 31));
  PRINT(i2string(std::numeric_limits<int>::min()));
  PRINT(i2string(-33));
  PRINT(i2string(-1));
  PRINT(i2string(-0));
  PRINT(i2string(0));
  PRINT(i2string(1));
  PRINT(i2string(33));
  PRINT(i2string(unsigned(-1) >> 1));
  PRINT(i2string(std::numeric_limits<int>::max()));
}
