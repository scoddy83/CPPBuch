/* cppbuch/k23/strings/zahl2string/to_string.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <limits>
#include <iostream>
#include <string>
#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n';

int main() {
  PRINT(std::to_string(std::numeric_limits<int>::min()));
  PRINT(std::to_string(std::numeric_limits<long>::max()));
  PRINT(std::to_string(-1.23456));
}
