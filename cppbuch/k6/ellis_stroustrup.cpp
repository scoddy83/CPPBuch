/* cppbuch/k6/ellis_stroustrup.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
/*
Das folgende Programm ist ein erweitertes und erläutertes Beispiel
aus
\cite{Ell90}. Es zeigt in konzentrierter Form die Eigenschaften
virtueller Funktionen.
*/
#include <iostream>
using std::cout;

class Basisklasse {
public:
  virtual ~Basisklasse() = default;
  virtual void vf1() { cout << "Basisklasse::vf1()" << '\n'; }
  virtual void vf2() { cout << "Basisklasse::vf2()" << '\n'; }
  virtual void vf3() { cout << "Basisklasse::vf3()" << '\n'; }
  virtual Basisklasse* vf4() {
    cout << "Basisklasse::vf4()\n";
    return this;
  }
  virtual Basisklasse& vf5() {
    cout << "Basisklasse::vf5()\n";
    return *this;
  }
  void f() { cout << "Basisklasse::f()\n"; }
};

class AbgeleiteteKlasse : public Basisklasse {
public:
  virtual void vf1() { cout << "AbgeleiteteKlasse::vf1()\n"; }
  virtual void vf2(int) { cout << "AbgeleiteteKlasse::vf2(int)\n"; }
  // virtual char vf3();            // Fehler! falscher Rückgabetyp
  virtual AbgeleiteteKlasse* vf4() {  // geänderter Rückgabetyp
    cout << "AbgeleiteteKlasse::vf4()\n";
    return this;
  }
  virtual AbgeleiteteKlasse& vf5() {  // geänderter Rückgabetyp
    cout << "AbgeleiteteKlasse::vf5()\n";
    return *this;
  }
  void f() { cout << "AbgeleiteteKlasse::f()\n"; }
};

int main() {
  AbgeleiteteKlasse d;
  Basisklasse* bp = &d;
  // In der folgenden Anweisung wird richtig
  // \tt{AbgeleiteteKlasse::vf1()}
  // aufgerufen, weil \tt{vf1()} virtuell ist.
  bp->vf1();  // \tt{AbgeleiteteKlasse::vf1()}
  // Eine Funktion  \tt{AbgeleiteteKlasse::vf2()}, das heißt ohne
  // Parameter, gibt  es nicht. Deshalb wird durch \tt{bp->vf2();}
  // die
  // Funktion
  // \tt{Basisklasse::vf2()}  aufgerufen.
  bp->vf2();  // \tt{Basisklasse::vf2()}

  // Die Funktion \tt{Basisklasse::vf2()} ist von \tt{d} aus nicht
  // mehr
  // zugreifbar. Mit  dem \tt{int}-Parameter gibt es kein Problem,
  // weil \tt{vf2(int)} in
  // der abgeleiteten  Klasse deklariert ist.
  // d.vf2();               // Fehler!
  d.vf2(7);  // ok: \tt{AbgeleiteteKlasse::vf2(int)}

  //  Obwohl \tt{bp} auf ein Objekt der abgeleiteten Klasse zeigt,
  //  ist
  //  \tt{bp->vf2(7)} nicht möglich, weil eine Funktion  mit
  //  \tt{int}-Parameter in der
  // Basisklasse nicht existiert.
  // bp->vf2(7);            // Fehler!

  // \tt{bp->f()} ruft  \tt{Basisklasse::f()} für das in \tt{d}
  // enthaltene Subobjekt auf, weil \tt{f()} nicht virtuell ist.
  bp->f();  //  \tt{Basisklasse::f()}

  AbgeleiteteKlasse* dp;
  dp = d.vf4();  // \tt{AbgeleiteteKlasse::vf4()}
  d.vf5();       // \tt{AbgeleiteteKlasse::vf5()}
  d.vf5().vf1();
  // Eine Referenz kann als Alias-Name für ein Objekt aufgefasst
  // werden.
  // Weil \tt{d.vf5()} eine Referenz auf \tt{AbgeleiteteKlasse}
  // zurückgibt, wird der Aufruf der Funktion \tt{d.vf5().vf1()}
  // interpretiert als \tt{(d.vf5()).vf1()}. Typischerweise  wird
  // das
  // (möglicherweise veränderte) Objekt selbst als Referenz
  // zurückgegeben.  // Die Zeile kann dann in zwei Teile zerlegt
  // werden:
  // \tt{d.vf5();}
  // \tt{d.vf1();}
}  // Ende von main
