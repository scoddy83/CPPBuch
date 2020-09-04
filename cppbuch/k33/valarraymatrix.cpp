/* cppbuch/k33/valarraymatrix.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <valarray>
#include <vector>

/* Simulation von
1 2 3                  P x Q
4 5 6
*
-4 -3 -2 -1            R x S   (R muss == Q sein)
0 1 2 3
4 5 6 7
=
8 14 20 26             P x S
8 23 38 53
indem ein valarray als Matrix interpretiert wird
*/

template <class T>
void printMatrix(const std::valarray<T>& v, const std::gslice& gs) {
  for (std::size_t r = 0; r < gs.size()[0]; ++r) {    // Zeilen
    for (std::size_t c = 0; c < gs.size()[1]; ++c) {  // Spalten
      std::cout << '\t'
                << v[gs.start() + r * gs.stride()[0] + c * gs.stride()[1]];
    }
    std::cout << '\n';
  }
}
using namespace std;

int main() {
  valarray<int> va{1, 2, 3, 4, 5, 6};
  constexpr size_t P = 2;
  constexpr size_t Q = 3;
  // Beschreibung als Matrix: sizes: Zeilen, Spalten -- strides:
  // Spalten, 1
  gslice ga(0, valarray<size_t>{P, Q}, valarray<size_t>{Q, 1});
  printMatrix(va, ga);
  cout << "*\n";
  constexpr size_t R =
      Q;  // Multiplikation erfordert Zeilenzahl vb = Spaltenzahl va
  constexpr size_t S = 4;
  valarray<int> vb{-4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7};
  // Beschreibung als Matrix (s.o.)
  gslice gb(0, valarray<size_t>{R, S}, valarray<size_t>{S, 1});
  printMatrix(vb, gb);
  cout << "=\n";

  // Ergebnismatrix
  valarray<int> vc(P * S);
  // Beschreibung als Matrix (s.o.)
  gslice gc(0, valarray<size_t>{P, S}, valarray<size_t>{S, 1});

  // Matrix-Multiplikation
  // das Element [i, j] ist das Skalarprodukt der i-Zeile von va mit
  // der j-ten Spalte von
  // vb. Um die jeweiligen Zeilen und Spalten nicht in der Schleife
  // mehrfach
  // zu berechnen, wird die Berechnung herausgezogen. Das ist bei
  // kleinen Matrizen nicht
  // notwendig, spart aber Laufzeit bei großen Matrizen.
  vector<valarray<int>> zeilen(P,
                               valarray<int>(Q));  // P valarrays der Größe Q
  for (size_t i = 0; i < P; ++i) {
    // ACHTUNG: Die folgende Zuweisung ist nur dann definiert, wenn
    // size()
    // auf der linken Seite des =-Operators mit der Größe des vom
    // slice_array
    // (=Rückgabetyp von operator[]() referenzierten Valarrays
    // übereinstimmt.
    // Das ist hier der Fall, wie an der Definition des vectors
    // 'zeilen' zu sehen.
    zeilen[i] = va[slice(i * Q, Q, 1)];
  }
  vector<valarray<int>> spalten(S);  // S valarrays der Größe Null!
  for (size_t j = 0; j < S; ++j) {
    // ACHTUNG: Die folgende Zuweisung ist nur dann definiert, wenn
    // size()
    // auf der linken Seite des =-Operators mit der Größe des vom
    // slice_array
    // (=Rückgabetyp von operator[]() referenzierten Valarrays
    // übereinstimmt.
    // Das ist hier NICHT der Fall, wie an der Definition des
    // vectors
    // 'spalten' zu sehen. Deshalb ist der static_cast notwendig,
    // sodass
    // operator=(valarray) aufgerufen wird.
    spalten[j] = static_cast<valarray<int>>(vb[slice(j, R, S)]);
  }
  for (size_t i = 0; i < P; ++i) {    // Zeile
    for (size_t j = 0; j < S; ++j) {  // Spalte
      vc[i * S + j] = (zeilen[i] * spalten[j]).sum();
    }
  }
  printMatrix(vc, gc);
}
