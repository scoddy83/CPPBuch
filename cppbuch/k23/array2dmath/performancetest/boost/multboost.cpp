/* cppbuch/k23/array2dmath/performancetest/boost/multboost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <iostream>
#include <random>
#define NDEBUG
#define BOOST_UBLAS_NDEBUG
// boost 1.64: array_wrapper-include fehlt in matrix.hpp, siehe 
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
  constexpr unsigned int SIZE = 500;
  constexpr unsigned int LOOPS = 20;

  boost::numeric::ublas::matrix<double> a1(SIZE, SIZE);
  boost::numeric::ublas::matrix<double> a2(SIZE, SIZE);
  zufallswerte(a1);
  zufallswerte(a2);
  boost::numeric::ublas::matrix<double> aerg(SIZE, SIZE);
  std::cout << "Boost-Matrix " << SIZE << "x" << SIZE << '\n';
  auto anfang = std::chrono::system_clock::now();
  double temp = 0.0;
  for (unsigned int i = 0; i < LOOPS; ++i) {
    // aerg = a1*a2;  // geht nicht mit boost-matrix
    aerg = boost::numeric::ublas::prod(a1, a2);
    aerg(0, 0) = aerg(1, 1);  // Änderung von aerg und Benutzung von
    temp += aerg(1, 1);       // temp verhindert Weg-Optimierung der Schleife
  }
  auto ende = std::chrono::system_clock::now();
  std::cout << temp << " dummy-Ausgabe\n";  // nur um temp zu benutzen
  auto dauer = std::chrono::duration_cast<std::chrono::milliseconds>(ende - anfang);
  std::cout << "Dauer pro Multiplikation und Zweisung  aerg = "
    "prod(a2, a1)\n(aerg = a1*a2; geht nicht "
    "wegen fehlender *-Operatorüberladung):\n"
            << 0.001 * dauer.count() / LOOPS << " Sekunden\n\n";
}
