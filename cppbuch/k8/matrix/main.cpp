/* cppbuch/k8/matrix/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiele für Multiplikation zweier 2-dimensionalen Matrizen und mehr.
// Beispiele für dreidimensionale Matrix.
#define PRINT(X) cout << (#X) << " = " << (X) << '\n'
#include "matrix3d.t"
using namespace std;

int main() {
  Matrix<float> a(3, 4);
  Matrix<float> b(4, 5);
  Matrix<float> c;
  MathVektor<float> mV(5);
  Matrix3D<float> matrix3D(2, 4, 5);
  matrix3D.I();
  mV.init(99.0);

  a.init(1.0);
  for (size_t i = 0; i < b.zeilen(); ++i) {
    for (size_t j = 0; j < b.spalten(); ++j) {
      b[i][j] = i + j;
    }
  }

  c = a * b;

  PRINT(a);
  PRINT(b);
  PRINT(c);

  cout << "a.I(); :\n";
  a.I();
  PRINT(a);
  PRINT(b);
  PRINT(a * b);

  a *= b;
  cout << "a *= b;\n";
  PRINT(a);
  PRINT(b);

  cout << "Zuweisung eines Vektors:\n";
  PRINT(mV);
  b[1] = mV;
  cout << "b[1] = mV:\n";
  PRINT(b);

  cout << "Zuweisung einer Submatrix:\n";
  for (size_t i = 0; i < matrix3D.dim1(); ++i) {
    PRINT(i);
    PRINT(matrix3D[i]);
  }

  cout << "matrix3D[1] = b;:\n";
  matrix3D[1] = b;
  for (size_t i = 0; i < matrix3D.dim1(); ++i) {
    PRINT(i);
    PRINT(matrix3D[i]);
  }
  mV.init(33.0);
  cout << "matrix3D[0][1] = mV; (init(33)):\n";
  matrix3D[0][1] = mV;
  for (size_t i = 0; i < matrix3D.dim1(); ++i) {
    PRINT(i);
    PRINT(matrix3D[i]);
  }
  matrix3D.init(100);
  cout << "matrix3D.init(100)):\n";
  for (size_t i = 0; i < matrix3D.dim1(); ++i) {
    PRINT(i);
    PRINT(matrix3D[i]);
  }
  matrix3D.I();
  cout << "matrix3D.I()):\n";
  for (size_t i = 0; i < matrix3D.dim1(); ++i) {
    PRINT(i);
    PRINT(matrix3D[i]);
  }
}
