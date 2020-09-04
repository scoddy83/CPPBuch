/* cppbuch/k4/wdouble.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>  // für exit( )
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream ziel("double.dat", ios::binary);
  if (!ziel) {
    cerr << "Datei kann nicht geöffnet werden!\n";
    exit(-1);
  }

  // Schreiben von 20 double-Zahlen
  double d = 1.0;
  for (int i = 0; i < 20; ++i, d *= 1.1)  // Kommaoperator (s.Text)
    ziel.write(reinterpret_cast<const char*>(&d), sizeof(d));
}  // \tt{ziel.close()} wird vom Destruktor durchgeführt
