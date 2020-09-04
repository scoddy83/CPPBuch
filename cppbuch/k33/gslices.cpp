/* cppbuch/k33/gslices.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <valarray>
using namespace std;

template <class T> void print(const valarray<T>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    cout << '\t' << v[i];
  }
  cout << '\n';
}

void printIndizes(const gslice& gs) {
  for (size_t r = 0; r < gs.size()[0]; ++r) {    // Zeilen
    for (size_t c = 0; c < gs.size()[1]; ++c) {  // Spalten
      cout << '\t' << gs.start() + r * gs.stride()[0] + c * gs.stride()[1];
    }
    cout << '\n';
  }
}

void print3DIndizes(const gslice& gs) {
  for (size_t x = 0; x < gs.size()[0]; ++x) {
    for (size_t y = 0; y < gs.size()[1]; ++y) {
      for (size_t z = 0; z < gs.size()[2]; ++z) {
        cout << " (" << x << ", " << y << ", " << z << ", "
             << gs.start() + x * gs.stride()[0] + y * gs.stride()[1] +
                    z * gs.stride()[2]
             << ")\n";
      }
    }
  }
  cout << '\n';
}

// gslice_index() aus Stroustrup C++PL4 40.5.6
size_t gslice_index(const gslice& gs, size_t i, size_t j) {
  return gs.start() + i * gs.stride()[0] + j * gs.stride()[1];
}

//  2D-Submatrix aus einer durch gs definierten 2D-Matrix erzeugen
gslice submatrix_gslice(const gslice& gs,  // 2-D Matrix
                        size_t position,   // Startposition
                        size_t rows,
                        size_t cols) {  // Zeilen, Spalten
  size_t sz[] = {rows, cols};
  size_t str[] = {gs.size()[1], 1};
  valarray<size_t> sizes(sz, 2);
  valarray<size_t> strides(str, 2);
  return gslice(position, sizes, strides);
}

int main() {
  cout << "\n\nBeispiel aus Stroustrup C++PL4 40.5.6:\nMapping:\n";
  valarray<size_t> lengths{2, 3};
  valarray<size_t> strides{3, 1};
  gslice gs(0, lengths, strides);
  for (size_t i = 0; i < 3; ++i) {    // für jede Zeile
    for (size_t j = 0; j < 2; ++j) {  // für jedes Element der Zeile
      cout << '(' << i << ", " << j << ")-> " << gslice_index(gs, i, j)
           << ';';
    }
  }

  cout << "\n\nBeispiel aus C++ Standard 26.6.6.1:\n";
  valarray<size_t> lengths3{2, 4, 3};
  valarray<size_t> strides3{19, 4, 1};
  gslice G3(3, lengths3, strides3);
  print3DIndizes(G3);

  cout << " valarray als 4x5 Matrix (Index == Wert):\n";
  constexpr size_t ZEILEN = 4;
  constexpr size_t SPALTEN = 5;
  valarray<size_t> lengths4{ZEILEN, SPALTEN};  // 2 Dimensionen
  valarray<size_t> strides4{SPALTEN, 1};
  // \tt{gslice} in der Ecke oben links konstruieren
  gslice g(0, lengths4, strides4);
  cout << "\nIndizes der 4x5 Matrix:\n";
  printIndizes(g);

  cout << "\nZeige Indizes der 3x4 Submatrix in Position 0:\n";
  printIndizes(submatrix_gslice(g, 0, 3, 4));

  cout << "\nZeige Indizes der 3x4 Submatrix in Position 1:\n";
  printIndizes(submatrix_gslice(g, 1, 3, 4));

  cout << "\nZeige Indizes der 3x4 Submatrix in Position 6:\n";
  printIndizes(submatrix_gslice(g, 6, 3, 4));

  // 4x5 Matrix erzeugen und initialisieren
  valarray<double> v(ZEILEN * SPALTEN);
  for (size_t i = 0; i < v.size(); ++i) {
    v[i] = i;  // Index == Wert
  }

  cout << "\nZeige Indizes der 2x3 Submatrix in Position 6:\n";
  gslice gs4(submatrix_gslice(g, 6, 2, 3));
  printIndizes(gs4);

  cout << "\nZeige 2x3 Submatrix in Position 6:\n";
  valarray<double> sub1(v[gs4]);
  cout << "sub1.size()= " << sub1.size() << '\n';
  print(sub1);
  cout << "\nSetze Submatrix zu 0:\nMatrix vorher:\n";
  for (size_t i = 0; i < ZEILEN; ++i) {
    print(valarray<double>(v[slice(i * SPALTEN, SPALTEN, 1)]));
  }
  cout << "\n und danach:\n";
  v[gs4] = 0;  // Setze 2x3 Submatrix zu 0
  for (size_t i = 0; i < ZEILEN; ++i) {
    print(valarray<double>(v[slice(i * SPALTEN, SPALTEN, 1)]));
  }
  cout << '\n';
}
