/* cppbuch/k4/rdouble.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Lesen einer Datei double.dat mit \tt{double}-Zahlen
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream quelle("double.dat", ios::binary);
  if (!quelle) {  // muss existieren
    cerr << "Datei kann nicht geöffnet werden!\n";
    exit(-1);
  }

  double d;
  while (quelle.read(reinterpret_cast<char*>(&d), sizeof(d)))  // lesen
    cout << "  " << d << '\n';
}  // \tt{quelle.close()} wird vom Destruktor durchgeführt
