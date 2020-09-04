/* cppbuch/k23/array2dmath/testvergleichmitboost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "array2d.h"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
// boost 1.64: array_wrapper-include fehlt in matrix.cpp, siehe 
// https://svn.boost.org/trac/boost/ticket/12982 und
// https://svn.boost.org/trac/boost/ticket/12516
#include <boost/serialization/array_wrapper.hpp>
#include <boost/numeric/ublas/matrix.hpp>

template <typename T> void zufallswerte(boost::numeric::ublas::matrix<T>& array) {
  std::uniform_real_distribution<T> verteilung(T(-100), T(100));
  std::mt19937 generator;
  for (unsigned int i = 0; i < array.size1(); ++i) {
    for (unsigned int j = 0; j < array.size2(); ++j) {
      array(i, j) = static_cast<T>(verteilung(generator));
    }
  }
}

int main() {
  constexpr unsigned int N = 100;
  constexpr unsigned int M = 10;
  constexpr unsigned int Q = 77;
  // Boost
  boost::numeric::ublas::matrix<double> b1(N, M);
  boost::numeric::ublas::matrix<double> b2(M, Q);
  zufallswerte(b1);
  zufallswerte(b2);
  // Produktbildung: b_result = b1*b2;  // geht leider nicht mit boost-matrix
  boost::numeric::ublas::matrix<double> b_result = boost::numeric::ublas::prod(b1, b2);
  assert(b_result.size1() == N);
  assert(b_result.size2() == Q);

  // Array2d
  Array2d<double> a1(b1.size1(), b1.size2());
  for(auto i = 0u; i < a1.getZeilen(); ++i) {
    for(auto j = 0u; j < a1.getSpalten(); ++j) {
      a1[i][j] = b1(i, j);  // kein []-Operator bei Boost matrix
    }
  }
  Array2d<double> a2(b2.size1(), b2.size2());
  for(auto i = 0u; i < a2.getZeilen(); ++i) {
    for(auto j = 0u; j < a2.getSpalten(); ++j) {
      a2[i][j] = b2(i, j);
    }
  }
  Array2d<double> a_result = a1 * a2;   // Produkt

  // Ergebnisse müssen gleich sein, abgesehen von Rundungsfehlern
  // bei nicht exakt gleicher Abfolge der Rechnungen
#ifdef NDEBUG
  std::cerr << "NDEBUG darf wg. assert() nicht gesetzt sein!\n";
  std::exit(1);
#endif
  double epsilon = 1.0e-12;
  for(auto i = 0u; i < a_result.getZeilen(); ++i) {
    for(auto j = 0u; j < a_result.getSpalten(); ++j) {
      assert(fabs(a_result[i][j] - b_result(i, j)) < epsilon);
    }
  }
  std::cout << "Die Ergebnisse sind gleich.\n";
}
