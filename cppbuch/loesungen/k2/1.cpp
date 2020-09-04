/* cppbuch/loesungen/k2/1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int dauerInSekunden(int stunden, int minuten, int sekunden);

int main() {
  int std = 3;
  int m = 37;
  int sec = 40;
  cout << std << " Stunden und " << m << " Minuten und " << sec
       << " Sekunden sind insgesamt " << dauerInSekunden(std, m, sec)
       << " Sekunden.\n";
}

int dauerInSekunden(int stunden, int minuten, int sekunden) {
  return 3600 * stunden + 60 * minuten + sekunden;
}
