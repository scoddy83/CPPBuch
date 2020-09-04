/* cppbuch/k4/wmatrix.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Schreiben einer Matrix als ASCII- und als binäre Datei
// (siehe auch Übungsaufgabe)
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  constexpr int ZEILEN{10};
  constexpr int SPALTEN{8};

  double matrix[ZEILEN][SPALTEN];

  // Matrix mit Werten füllen
  for (int i = 0; i < ZEILEN; ++i)
    for (int j = 0; j < SPALTEN; ++j)
      matrix[i][j] = i + 1 + (j + 1) / 1000.0;

  // Schreiben als ASCII-Datei (lesbar mit Editor)
  ofstream ziel("matrix.asc");
  if (!ziel) {
    cerr << "Datei kann nicht geöffnet werden!\n";
    exit(-1);
  }

  // formatiertes Schreiben
  for (int i = 0; i < ZEILEN; ++i) {
    for (int j = 0; j < SPALTEN; ++j) {
      ziel.width(8);
      ziel << matrix[i][j];
    }
    ziel << '\n';
  }

  // Datei schließen, damit \tt{ziel} wiederverwendet werden kann:
  ziel.close();

  // Schreiben als binäre Datei
  ziel.open("matrix.bin", ios::binary);
  if (!ziel) {
    cerr << "Datei kann nicht geöffnet werden!\n";
    exit(-1);
  }
  ziel.write(reinterpret_cast<const char*>(matrix), sizeof(matrix));
}  // automatisches \tt{close()}
