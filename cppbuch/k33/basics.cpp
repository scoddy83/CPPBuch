/* cppbuch/k33/basics.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <valarray>
using namespace std;

template <class T> void print(const valarray<T>& v) {
  for (size_t i = 0; i < v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';
}

unsigned int doubleIt(unsigned int x) { return 2 * x; }

int main() {
  cout << "Konstruktoren :\n";
  valarray<double> v(12);
  print(v);
  valarray<double> u(4, 12);
  print(u);
  double a[] = {2.2, 3.3, 4.4, 9.9};
  valarray<double> w(a, 4);
  print(w);
  cout << "Kopier-Konstruktor :\n";
  valarray<double> x(w);
  print(x);
  cout << "Zuweisung :\n";
  u = v;
  print(u);
  cout << "Unäre Operatoren :\n";
  u = -17.45;
  print(u);
  v = +u;
  print(v);
  v = -u;
  print(v);
  valarray<unsigned int> i(9);
  print(i);
  i[1] = -1;  // absichtliche Typumwandlung!
  print(i);
  valarray<unsigned int> j = ~i;
  print(j);
  valarray<bool> b = !i;
  print(b);
  cout << "Summe ";
  print(w);
  cout << "=" << w.sum() << '\n';
  cout << "Minimum =" << w.min() << '\n';
  cout << "Maximum =" << w.max() << '\n';
  w.resize(5, 7.0);
  print(w);
  cout << "shift() :\n";
  valarray<double> y = w.shift(2);
  print(y);
  y = w.shift(-2);
  print(y);
  valarray<unsigned int> i1(9);
  for (unsigned int k = 0; k < i.size(); ++k)
    i[k] = k;
  print(i);
  cout << "cshift() :\n";
  i1 = i.cshift(2);
  print(i1);
  i1 = i.cshift(-2);
  print(i1);
  cout << "apply():\n";
  print(i);
  i1 = i.apply(doubleIt);
  print(i1);
  cout << "Kurzform-Operator:\n";
  i1 += 3;
  print(i1);
  print(i);
  i1 += i;
  print(i1);
  cout << "Binäre Operatoren:\n";
  print(i);
  i1 = i * 2U;
  print(i1);
  i1 = 3U * i;
  print(i1);
  i1 = i * i;
  print(i1);
  valarray<bool> b1 = i1 && i;
  b1 = i1 == i;
  print(b1);
  b1 = i1 != i;
  print(b1);
  b1 = i1 < i;
  print(b1);
  b1 = i1 < 6U;
  print(b1);
  cout << "math. Funktionen:\n abs():\n";
  w = -w;
  print(w);
  w = abs(w);
  print(w);
  valarray<double> w1(w);
  cout << "pow():\n";
  w1 = pow(w, 2.0);
  print(w1);
  valarray<double> h(3.0, 5);
  w1 = pow(w, h);
  print(w1);
}
