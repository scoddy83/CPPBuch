/* cppbuch/k9/time.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

int main() {
  auto jetzt = std::chrono::system_clock::now();  // siehe dazu Abschnitt
                                                  // \ref{chrono}
  std::time_t jetztAlsTime_t = std::chrono::system_clock::to_time_t(jetzt);
  std::tm* tmPtr =
      std::localtime(&jetztAlsTime_t);  // siehe dazu Abschnitt \ref{strftime}
  std::cout << std::put_time(tmPtr, "%c") << '\n';
}
