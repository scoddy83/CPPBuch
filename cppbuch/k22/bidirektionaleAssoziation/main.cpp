/* cppbuch/k22/bidirektionaleAssoziation/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"

int main() {
  Person mabuse("Dr. Mabuse");
  Person klicko("Witwe Klicko");
  Person holle1("Frau Holle");
  Person holle2("Frau Holle");              // eine Namensvetterin
  mabuse.lerntkennen(klicko);
  holle1.lerntkennen(klicko);
  holle1.lerntkennen(holle2);
  mabuse.bekannteZeigen();
  klicko.bekannteZeigen();
  holle1.bekannteZeigen();

}
