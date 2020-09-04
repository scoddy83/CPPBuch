/* cppbuch/k23/array2dmath/arraytest.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
//#define TESTARRAY2D
#include "array2d.h"
#include <cassert>
#include <numeric>
using namespace std;

int main() {
  Array2d<int> a1(2, 3, 1);
  Array2d<int> a2(2, 3, 2);
  Array2d<int> a3(2, 3, 3);
  Array2d<int> a4(3, 3, 4);
  Array2d<int> ergAdd(2, 3);
  // 2 Op
  cout << "2 Op: a1+a2:\n";
  a1.print();
  cout << "+\n";
  a2.print();
  cout << "=\n";
  ergAdd = a1 + a2;
  ergAdd.print();
  assert(ergAdd == a3);

  // 3 op
  cout << "3 Op: -a1 + 2*a2*3 + a3:\n-\n";
  a1.print();
  cout << "+ 2*\n";
  a2.print();
  cout << "+\n";
  a3.print();
  cout << "=\n";
  ergAdd = -a1 + 2 * a2 * 3  + a3;
  ergAdd.print();
  assert(ergAdd == Array2d<int>(2, 3, 14));

  // 4 op
  cout << "4 Op: a1 + a2 - a3 + a1:\n";
  a1.print();
  cout << "+\n";
  a2.print();
  cout << "-\n";
  a3.print();
  cout << "+\n";
  a1.print();
  cout << "=\n";
  ergAdd = a1 + a2 - a3 + a1;
  ergAdd.print();
  assert(ergAdd == Array2d<int>(2, 3, 1));

  // mult
  cout << "\nb1*b2:\n";
  Array2d<int> b1(2, 3);
  iota(b1.begin(), b1.end(), 1);
  b1.print();
  cout << "*\n";
  Array2d<int> b2(3, 4);
  iota(b2.begin(), b2.end(), -4);
  b2.print();
  cout << "=\n";
  Array2d<int> ergMult(2, 4);
  ergMult = b1 * b2;
  ergMult.print();
  assert(ergMult == Array2d<int>({{8, 14, 20, 26}, {8, 23, 38, 53}}));

  Array2d<int> c0(3, 3);
  iota(c0.begin(), c0.end(), 1);
  Array2d<int> c1(3, 3, 1);
  Array2d<int> ergc(3, 3, 1);
  Array2d<int> e(3, 3, 0);
  for (size_t i = 0; i < e.getZeilen(); ++i) {
    e[i][i] = 1;  // Einheitsmatrix
  }
  cout << "\nEinheitsmatrix:\n";
  e.print();

  cout << "\nc0 *= c1:\n";
  c0.print();
  cout << " *= \n";
  c1.print();
  cout << " = \n";
  c0 *= c1;
  c0.print();
  assert(c0 == Array2d<int>({{6, 6, 6}, {15, 15, 15}, {24, 24, 24}}));

  cout << "\nergc = c0 * e:\n";
  ergc = c0 * e;
  ergc.print();
  assert(c0 == Array2d<int>({{6, 6, 6}, {15, 15, 15}, {24, 24, 24}}));

  cout << "\nc0 = 2*c0:\n";
  c0 = 2 * c0;
  c0.print();
  assert(c0 == Array2d<int>({{12, 12, 12}, {30, 30, 30}, {48, 48, 48}}));

  cout << "\nergc = c0 * e + e*2:\n";
  ergc = c0 * e + e * 2;
  ergc.print();
  assert(ergc == Array2d<int>({{14, 12, 12}, {30, 32, 30}, {48, 48, 50}}));

  Array2d<int> ax{{1, 2, 3}, {4, 5, 6}};
  Array2d<int> bx{{1, 2, 3, 0}, {4, 1, 1, 5}, {1, 7, 1, 4}};
  Array2d<int> cx = 2 * (ax + ax) * (bx + bx + bx);
  cout << "\nax:\n";
  ax.print();
  cout << "\nbx:\n";
  bx.print();
  cout << "\n2*(ax+ax)*(bx+bx+bx):\n";
  cx.print();
  assert(cx == Array2d<int>({{144, 300, 96, 264}, {360, 660, 276, 588}}));

  cout << "\ntransponiert:\n";
  Array2d<int> cxt(cx.transpose());
  cxt.print();
  for(auto i = 0u; i < cx.getZeilen(); ++i) {
    for(auto j = 0u; j < cx.getSpalten(); ++j) {
      assert(cx[i][j] == cxt[j][i]);
    }
  }
}
