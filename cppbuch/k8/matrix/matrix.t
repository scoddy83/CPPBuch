/* cppbuch/k8/matrix/matrix.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MATRIX_T
#define MATRIX_T
#include "../mathvek/mvektor.t"
#include <iostream>

// Matrix als Vektor von MathVektoren 
template <typename T> class Matrix 
: public Vektor<MathVektor<T>> {
public:
  using super = Vektor<MathVektor<T>>;  // Abkürzung für Oberklassentyp

  Matrix(std::size_t z = 1, std::size_t s = 1)  // Zeilen, Spalten
      // Initialisierung mit z MathVektoren der Länge s:
      : Vektor<MathVektor<T>>(z, MathVektor<T>(s)) {}

  auto zeilen() const { return super::size(); }

  // Die Spaltenanzahl ist die Länge eines der MathVektoren (hier  der 0.)
  auto spalten() const { return super::operator[](0).size(); }

  void init(T);

  // mathematische Operatoren und Funktionen
  Matrix<T>& I();  // Einheitsmatrix erzeugen
  Matrix<T>& operator*=(T);
  Matrix<T>& operator*=(const Matrix<T>&);

  // ... weitere  Operatoren und Funktionen
};

/* ===== noch fehlende Implementierungen   =================*/

template <typename T> void Matrix<T>::init(T wert) {
  for (std::size_t i = 0; i < zeilen(); ++i) {
    super::operator[](i).init(wert);
    // \tt{operator[](i)} ist vom Typ \tt{<MathVektor<T>}
  }
}

template <typename T> Matrix<T>& Matrix<T>::I() {  // Einheitsmatrix
  for (std::size_t i = 0; i < zeilen(); ++i) {
    for (std::size_t j = 0; j < spalten(); ++j) {
      super::operator[](i)[j] = (i == j) ? T(1) : T(0);
    }
  }
  return *this;
}

// Multiplikation mit einer Zahl
template <typename T> Matrix<T>& Matrix<T>::operator*=(T faktor) {
  for (std::size_t i = 0; i < zeilen(); ++i) {
    super::operator[](i) *= faktor;  // \tt{MathVektor::operator*=()}
  }
  return *this;
}

// Multiplikation mit einer Matrix
template <typename T> Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& b) {
  if (spalten() != b.zeilen()) {
    throw "Falsche Dimension in Matrix*= !";
  }
  Matrix<T> erg(zeilen(), b.spalten());
  for (std::size_t i = 0; i < zeilen(); ++i) {
    for (std::size_t j = 0; j < b.spalten(); ++j) {
      erg[i][j] = T(0);
      for (std::size_t k = 0; k < spalten(); ++k)
        erg[i][j] += super::operator[](i)[k] * b[k][j];
    }
  }
  super::swap(erg);  // \tt{*this} mit \tt{erg} vertauschen
  return *this;
}

template <typename T> Matrix<T> operator*(Matrix<T> a, const Matrix<T>& b) {
  return a *= b;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Matrix<T>& m) {
  for (std::size_t i = 0; i < m.zeilen(); ++i) {
    s << '\n' << i << " :  ";
    for (std::size_t j = 0; j < m.spalten(); ++j) {
      s << m[i][j] << " ";
    }
  }
  s << '\n';
  return s;
}

#endif
