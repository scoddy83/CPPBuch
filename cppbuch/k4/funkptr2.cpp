/* cppbuch/k4/funkptr2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

void drucke(int x) { std::cout << x << '\n'; }  // Funktion

int main() {
  void (*f1)(int) = &drucke;  // keine Umwandlung
  void (*f2)(int) = drucke;   // Funktion $\rightarrow$ Zeiger
  f1(3);                      // Zeiger $\rightarrow$ Funktion
  (*f1)(3);                   // explizit: Zeiger$\rightarrow$ Funktion
}
