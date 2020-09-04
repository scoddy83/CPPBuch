/* cppbuch/loesungen/k4/4.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
/* Da eine echte dreidimensionale Ausgabe in der Ebene nicht möglich
ist,
werden  n  (DIM2 x DIM3)-Matrizen ausgegeben.
*/
#include <iostream>

template <typename Feldtyp>
void Tabellenausgabe3D(Feldtyp T, unsigned int n) {
  const unsigned int DIM2 = sizeof T[0] / sizeof T[0][0];
  const unsigned int DIM3 = sizeof T[0][0] / sizeof T[0][0][0];
  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < DIM2; ++j) {
      for (unsigned int k = 0; k < DIM3; ++k)
        std::cout << T[i][j][k] << ' ';
      std::cout << '\n';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main() {
  const unsigned int N = 2, M = 3, Q = 4;
  int mat3D[N][M][Q];  // 3D-Matrix
  // Mit Werten füllen
  int m = 0;
  for (unsigned int i = 0; i < N; ++i) {
    for (unsigned int j = 0; j < M; ++j) {
      for (unsigned int k = 0; k < Q; ++k)
        mat3D[i][j][k] = ++m;
    }
  }
  Tabellenausgabe3D(mat3D, N);
}
