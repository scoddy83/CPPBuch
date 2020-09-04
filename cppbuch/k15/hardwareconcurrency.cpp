/* cppbuch/k15/hardwareconcurrency.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <thread>

int main() {
  std::cout << "Dieser Rechner hat " << std::thread::hardware_concurrency()
            << " Prozessorkerne\n";
}
