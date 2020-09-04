/* cppbuch/k8/matrix/matrix3d.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MATRIX3D_T
#define MATRIX3D_T
#include "matrix.t"

template <typename T>
class Matrix3D : public Vektor<Matrix<T>> {  // 3D-Matrix als Vektor
                                             // von 2D-Matrizen
public:
  using super = Vektor<Matrix<T>>;  // Oberklassentyp

  Matrix3D(std::size_t d1 = 1, std::size_t d2 = 1, std::size_t d3 = 1)
      : Vektor<Matrix<T>>(d1, Matrix<T>(d2, d3)) {}

  auto dim1() const { return super::size(); }
  auto dim2() const { return super::operator[](0).size(); }
  auto dim3() const {
    return super::operator[](0).operator[](0).size();
  }

  void init(T);      // Initialisierung
  Matrix3D<T>& I();  // Einheitsmatrix

  // mathematische Operatoren
  Matrix3D<T>& operator*=(T);  // Multiplikation
  // weitere Operatoren und Funktionen ...
};

/* =======  noch fehlende Implementierungen =====================*/

template <typename T> void Matrix3D<T>::init(T wert) {  // Initialisierung
  for (std::size_t i = 0; i < dim1(); ++i) {
    super::operator[](i).init(wert);  // = \tt{Matrix<T>::operator[](i)}
  }
}

template <typename T> Matrix3D<T>& Matrix3D<T>::I() {  // Einheitsmatrix
  for (std::size_t i = 0; i < dim1(); ++i) {
    super::operator[](i).I();
  }
  return *this;
}

template <typename T> Matrix3D<T>& Matrix3D<T>::operator*=(T faktor) {
  for (std::size_t i = 0; i < dim1(); ++i) {
    super::operator[](i) *= faktor;  // \tt{Matrix::operator*=()}
  }
  return *this;
}

#endif
