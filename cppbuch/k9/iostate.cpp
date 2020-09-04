/* cppbuch/k9/iostate.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

using namespace std;

int main() {
  ios::iostate status;
  while (true) {  // Schleifenabbruch mit break
    int i;
    cout << "Zahl (Ctrl+D oder Ctrl+Z = Ende):";
    cin >> i;
    status = cin.rdstate();
    // Ausgabe der Statusbits
    cout << "status = " << status << '\n';
    cout << "good() = " << cin.good() << '\n';
    cout << "eof()  = " << cin.eof() << '\n';
    cout << "fail() = " << cin.fail() << '\n';
    cout << "bad()  = " << cin.bad() << '\n';
    if (cin.eof()) {
      break;  // Abbruch
    }
    // Fehlerbehandlung bzw. Ausgabe
    if (status) {
      cin.clear();  // Fehlerbits zurücksetzen
      cin.get();    // ggf. fehlerhaftes Zeichen entfernen
    } else
      cout << "*** " << i << '\n';
  }
}
