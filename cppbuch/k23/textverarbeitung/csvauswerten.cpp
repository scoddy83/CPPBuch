/* cppbuch/k23/textverarbeitung/csvauswerten.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>                          // für \tt{exit( )}
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "../strings/split.h"               // siehe Seite \pageref{splith}
using namespace std;

int main() {
  string csvDateiname;
  cout << "CsvDatei? ";
  cin >> csvDateiname;
  ifstream quelle(csvDateiname);            // Dateiobjekt anlegen
  if (!quelle) {                            // Fehlerabfrage
    cerr << csvDateiname << " kann nicht geöffnet werden!\n";
    exit(-1);
  }
  vector<vector<int>> tabelle;
  string zeile;
  while (quelle.good()) {
    getline(quelle, zeile);
    if (!quelle.fail()) {
      auto stringvektor = split(zeile, ","); 
      vector<int> intvektor;
      for(const auto& str : stringvektor) {  // String $\rightarrow$ \tt{int}
        intvektor.push_back(stoi(str));
      }
      tabelle.push_back(intvektor);
    }
  }
  quelle.close();
  // Tabelle ausgeben
  for (const auto& zeile : tabelle) {
    for (auto zahl : zeile) {
      cout << zahl << "  ";
    }
    cout << '\n';
  }
}
