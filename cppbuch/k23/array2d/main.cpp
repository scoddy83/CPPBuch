/* cppbuch/k23/array2d/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "array2d.h"
#include <iostream>
using namespace std;

int main() {
  Array2d<int> arr(5, 7, 0);
  cout << "at():\n";
  for (size_t z = 0; z < arr.getZeilen(); ++z) {
    for (size_t s = 0; s < arr.getSpalten(); ++s) {
      arr.at(z, s) = 10 * z + s;  // at()
      cout << arr.at(z, s) << " ";
    }
    cout << '\n';
  }
  cout << "[]():\n";
  for (size_t z = 0; z < arr.getZeilen(); ++z) {
    for (size_t s = 0; s < arr.getSpalten(); ++s) {
      arr[z][s] = 10 * z + s;  // operator[]
      cout << arr[z][s] << " ";
    }
    cout << '\n';
  }

  cout << "init(3):\n";
  arr.init(3);
  arr.print();

  cout << "Array mit Strings:\n";
  Array2d<string> arrs(2, 5, "hello");
  arrs.print();

  cout << "Vergleiche von double-Arrays:\n";
  Array2d<double> d1(3, 4, 50.0);
  d1.print();
  Array2d<double> d2(3, 4, 100.0);
  d2.print();
  cout.setf(ios_base::boolalpha);
  cout << " d1 < d2 : " << (d1 < d2) << '\n';
  cout << " d1 > d2 : " << (d1 > d2) << '\n';
  cout << " d1 == d2 : " << (d1 == d2) << '\n';
  cout << " d1 != d2 : " << (d1 != d2) << '\n';

  cout << "Sequenzkonstruktor:\n";
  Array2d<double> x{{1.1, 2.2}, {3.3, 4.4}, {5.5, 6.6}};
  x.print();

  double feld[]{0.1, 0.2, 0.3};
  cout << "Init mit C-Array:\n";
  Array2d<double> x1(1, 3, feld);
  x1.print();
}
