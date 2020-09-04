/* cppbuch/k2/makros1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
// Zum Testen eins oder beide der folgenden Makros auskommentieren
//#define zweig1
#define konstante 42

int main() {

#ifdef zweig1
  std::cout << "zweig1 ist definiert\n";
#elif konstante == 42
  std::cout << "zweig1 undefiniert, konstante ist 42\n";
#else
  std::cout << "zweig1 undefiniert, konstante undefiniert oder != 42\n";
#endif
}
