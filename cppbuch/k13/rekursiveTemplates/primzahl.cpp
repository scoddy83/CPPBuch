/* cppbuch/k13/rekursiveTemplates/primzahl.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

template <int p, int i> struct istPrimzahl {
  // \tt{p} ist nur dann prim, wenn \tt{p} nicht durch \tt{i}
  // teilbar
  // ist und auch
  // nicht durch alle anderen Teiler zwischen 2 und \tt{i}. Wenn
  // \tt{i==2} ist,
  // wird \tt{istPrimzahl<0, 1>::prim} gefragt, d.h. Abruch der
  // Rekursion (s.u.).
  static const int prim{(p % i) && istPrimzahl<(i > 2 ? p : 0), i - 1>::prim};
};

template <int i> struct druckePrimzahlenBis {
  // Der folgende Konstruktoraufruf sorgt dafür, dass auch die
  // kleineren Primzahlen rekursiv ausgegeben werden.
  druckePrimzahlenBis<i - 1> a;
  static const int primzahl{istPrimzahl<i, i - 1>::prim};
  druckePrimzahlenBis() {
    if (primzahl) {
      std::cout << i << '\n';
    }
  }
};

// Rekursionsabbruch durch Spezialisierungen
template <> struct istPrimzahl<0, 1> { static const int prim = 1; };

template <> struct druckePrimzahlenBis<2> {  //
  druckePrimzahlenBis() { std::cout << 2 << '\n'; }
};

int main() { druckePrimzahlenBis<17> a; }
