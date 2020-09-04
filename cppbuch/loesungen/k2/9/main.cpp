/* cppbuch/loesungen/k2/9/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "taschenrechner.h"
#include <iostream>
using namespace std;

int main() {
  char ch;
  while (true) {  // Abbruch mit break
    cout << "\nBitte einen mathematischen Ausdruck OHNE LEERZEICHEN "
            "eingeben, "
            "z.B. 4*(12+3)\n(Abbruch durch Eingabe von 'e')>>";
    cin.get(ch);
    if (ch != 'e')
      cout << ausdruck(ch);
    else
      break;
  }
}
