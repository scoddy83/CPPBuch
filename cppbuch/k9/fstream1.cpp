/* cppbuch/k9/fstream1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>

using namespace std;

// Benutzen *eines* Datei-Objekts nacheinander zum schreiben und
// lesen
int main() {
  fstream fileStream;

  // schreiben
  fileStream.open("fstream1.dat", ios::out);
  // fileStream << "X" << endl;  // Lesefehler unten provozieren
  for (int i = 0; i < 9; ++i) {
    fileStream << i << '\n';
  }
  fileStream.close();

  // lesen
  fileStream.open("fstream1.dat", ios::in);
  while (fileStream.good()) {
    int i;
    fileStream >> i;
    if (fileStream.good()) {
      cout << i << ' ';
    } else {
      cout << "\nDateiende erreicht oder Lesefehler";
    }
  }
  cout << '\n';
}
