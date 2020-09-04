/* cppbuch/k2/makros2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

int main() {
  std::cout << "__FILE__  (Datei)    : " << __FILE__
            << "\n__LINE__  (Zeile)    : " << __LINE__
            << "\n__func__  (Funktion) : " << __func__
            << "\n__DATE__  (Datum der Compilation)   : " << __DATE__
            << "\n__TIME__  (Uhrzeit der Compilation) : " << __TIME__ << '\n';
}
