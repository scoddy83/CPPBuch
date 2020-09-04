/* cppbuch/k23/array2dmath/performancetest/boost/addboost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <iostream>
#define NDEBUG
#define BOOST_UBLAS_NDEBUG
// boost 1.64: array_wrapper-include fehlt in matrix.hpp, siehe 
// https://svn.boost.org/trac/boost/ticket/12982 und
// https://svn.boost.org/trac/boost/ticket/12516
#include <boost/serialization/array_wrapper.hpp>
#include <boost/numeric/ublas/matrix.hpp>

int main() {
  constexpr unsigned int SIZE = 1000;
  constexpr unsigned int LOOPS = 1000;
  boost::numeric::ublas::matrix<double> a1(SIZE, SIZE);
  boost::numeric::ublas::matrix<double> a2(SIZE, SIZE);
  boost::numeric::ublas::matrix<double> a3(SIZE, SIZE);
  boost::numeric::ublas::matrix<double> aerg(SIZE, SIZE);
  for (unsigned i = 0; i < a1.size1(); ++i) {
    for (unsigned j = 0; j < a1.size2(); ++j) {
      a1(i, j) = 3.14159;
      a2(i, j) = 2.7182;
      a3(i, j) = 1.1111;
    }
  }
  std::cout << "Boost-Matrix " << SIZE << "x" << SIZE << '\n';
  auto anfang = std::chrono::system_clock::now();
  double temp = 0.0;
  for (unsigned int i = 0; i < LOOPS; ++i) {
    aerg = -a1 + 2.0 * a2 + a3;
    aerg(0, 0) = aerg(1, 1);  // Änderung von aerg und Benutzung von
    temp += aerg(1, 1);       // temp verhindert Weg-Optimierung der Schleife
  }
  auto ende = std::chrono::system_clock::now();
  std::cout << temp << " dummy-Ausgabe\n";  // nur um temp zu benutzen
  auto dauer = std::chrono::duration_cast<std::chrono::milliseconds>(ende - anfang);
  std::cout << " Boost-Matrix Dauer pro Addition aerg = -a1 + 2.0*a2 "
               "+ a3 : "
            << dauer.count() / static_cast<double>(LOOPS) << " Millisekunden\n\n";
}
