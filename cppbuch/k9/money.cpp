/* cppbuch/k9/money.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  try {
    std::cout << std::showbase;   // Währungsymbol anzeigen
    long double money_d = 12345;  // Betrag in Cent
    std::cout.imbue(std::locale("de_DE.utf8"));
    std::cout << std::put_money(money_d) << '\n';
    std::cout << std::put_money(money_d, true) << '\n';
    std::string money_str = "12345";  // Betrag in Cent
    std::cout.imbue(std::locale("en_US.utf8"));
    std::cout << std::put_money(money_str) << '\n';
    std::cout << std::put_money(money_str, true) << '\n';
  } catch (std::exception& ex) {
    std::cerr << ex.what()
              << "\nlocale wird von diesem System nicht unterstützt\n";
  }
}
