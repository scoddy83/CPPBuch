/* cppbuch/k6/usingdeklaration.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
class Basis {
protected:
  void f(int) {}
};

class Abgeleitet : public Basis {
public:
  using Basis::f;
  // ...
};

int main() {
  Basis einBasisObjekt;
  //einBasisObjekt.f(0);                     // Fehler! \tt{f()} ist nicht \tt{public}.
  Abgeleitet einAbgeleitetObjekt;
  einAbgeleitetObjekt.f(0);                 // ok
}
