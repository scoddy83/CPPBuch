/* cppbuch/k6/cast.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
class Basis {
public:
  virtual void f() {}
  virtual ~Basis() = default;
  Basis() = default;
  Basis(const Basis&) = default;
  Basis& operator=(const Basis&) = default;
};

class Abgeleitet : public Basis {
public:
  virtual void f() {}
};

Abgeleitet* g(Basis *pB) {                  // \tt{g()} benutzt \tt{f()}
  Abgeleitet *pA = dynamic_cast<Abgeleitet*>(pB);
  if(pA) {                              // Null-Zeiger bei Scheitern des \tt{dynamic\_cast}
      pA->f();                              // \tt{Abgeleitet::f()}
  }
  return static_cast<Abgeleitet*>(pB);
}

int main() {
  Basis einB;
  Abgeleitet einA;
  Basis *pBB = & einB;
  Basis *pBA = & einA;
  Abgeleitet *pErgebnis;
  // Durch den folgenden Aufruf von \tt{g()} wird in  \tt{g()} \tt{Abgeleitet::f()} ausgeführt,
  // weil \tt{pBA} auf ein \tt{Abgeleitet}-Objekt zeigt. \tt{pErgebnis} zeigt auf \tt{einA}:
  pErgebnis = g(pBA);
  // \tt{Abgeleitet::f()} wird unten  \emph{nicht} ausgeführt, weil \tt{pB} in \tt{g()} auf ein \tt{Basis}-Objekt
  //  zeigt. \tt{pErgebnis} ist undefiniert(!), weil der \tt{static\_cast} ungeeignet ist:
  // Der dynamische Typ des per Zeiger übergebenen Objekts ist nicht vom Typ \tt{Abgeleitet}.
  pErgebnis = g(pBB);
} // Ende von \tt{main()}
