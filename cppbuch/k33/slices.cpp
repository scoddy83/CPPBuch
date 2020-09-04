/* cppbuch/k33/slices.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <valarray>
using namespace std;

template <class T> void print(const valarray<T>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}

void printIndizes(slice s) {
  for (size_t i = 0; i < s.size(); ++i) {
    cout << s.start() + i * s.stride() << ' ';
  }
  cout << '\n';
}

int main() {
  constexpr size_t ZEILEN = 3;
  constexpr size_t SPALTEN = 4;
  cout << "\nZeige Indizes von Zeilen und Spalten:\n";
  for (size_t zeile = 0; zeile < ZEILEN; ++zeile) {
    cout << "Zeile  " << zeile << ": ";
    size_t start_index = zeile * SPALTEN;
    printIndizes(slice(start_index, SPALTEN, 1));
  }
  cout << '\n';
  for (size_t spalte = 0; spalte < SPALTEN; ++spalte) {
    cout << "Spalte " << spalte << ": ";
    printIndizes(slice(spalte, ZEILEN, SPALTEN));
  }

  valarray<double> v(ZEILEN * SPALTEN);  // Platz für 3x4-Matrix
  for (size_t i = 0; i < v.size(); ++i) {
    v[i] = i;
  }
  cout << " 3x4 Matrix (Index == Wert):\n";
  size_t index = 0;
  for (size_t i = 0; i < ZEILEN; ++i) {
    for (size_t j = 0; j < SPALTEN; ++j) {
      cout << '\t' << v[index++];
    }
    cout << '\n';
  }

  cout << "Zeile 1 extrahieren:       ";
  valarray<double> zeile1(v[slice(1 * SPALTEN, SPALTEN, 1)]);
  print(zeile1);

  cout << " weitere Slice-Operationen -- valarr erzeugen:\n";
  valarray<double> valarr(14);
  for (size_t i = 0; i < valarr.size(); ++i) {
    valarr[i] = i;
  }
  print(valarr);
  cout << "Slice (1,5,3) konstruieren:\n";
  valarray<double> B(valarr[slice(1, 5, 3)]);
  print(B);
  valarray<double> C(2.0, 5);
  cout << "C = ";
  print(C);
  cout << "Slice (1,5,3) mit C multiplizieren:\n";
  valarr[slice(1, 5, 3)] *= C;
  print(valarr);
  cout << "Slice (1,5,3) zuweisen:\n";
  C = valarr[slice(1, 5, 3)];
  print(C);
  cout << "Slice (1,5,3) =  99 setzen:\n";
  valarr[slice(1, 5, 3)] = 99;
  print(valarr);
}
