/* cppbuch/k8/smartptr/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "smartptr.t"
#include <iostream>

using namespace std;

class A {
public:
  virtual void hi() { cout << "hier ist A::hi()\n"; }

  virtual ~A() { cout << "A::Destruktor\n"; }
  A() = default;
  A(const A&) = default;
  A& operator=(const A&) = default;
};

class B : public A {
public:
  virtual void hi() { cout << "hier ist B::hi()\n"; }
  virtual ~B() { cout << "B::Destruktor\n"; }
  B() = default;
  B(const B&) = default;
  B& operator=(const B&) = default;
};

// Übergabe per Wert ist hier nicht möglich, wohl aber per Referenz:
template <class T> void perReferenz(const SmartPointer<T>& p) {
  cout << "Aufruf: perReferenz(const SmartPointer<T>&):";
  p->hi();  // (p.operator->())->hi();
}

int main() {
  cout << "Zeiger auf dynamische Objekte:\n";
  cout << "Konstruktoraufruf\n";
  SmartPointer<A> spA(new A);

  cout << "Operator ->\n";
  spA->hi();

  cout << "Operator *\n";
  (*spA).hi();

  cout << "Polymorphismus:\n";
  SmartPointer<A> spAB(new B);  // zeigt auf \tt{B}-Objekt
  spAB->hi();                   // \tt{B::hi()}

  // Parameterübergabe eines \tt{SmartPointer}
  perReferenz(spAB);

  // Die  Wirkung der Sicherungsmaßnahmen im Vergleich zu einfachen
  // C-Zeigern zeigen die folgenden Zeilen:

  SmartPointer<B> spUndef;
  try {
    if (!spUndef)  // = \tt{if(!(spUndef.operator bool()))}
      cout << "undefinierter Zeiger:\n";
    // Zugriff auf nicht-initialisierten Zeiger bewirkt Laufzeitfehler:
    spUndef->hi();    // Laufzeitfehler!
    (*spUndef).hi();  // Laufzeitfehler!
  } catch (const NullPointerException& ex) {
    cerr << "Laufzeitfehler: " << ex.what() << '\n';
  }

  //  alle folgenden Anweisungen bewirken Fehlermeldungen des Compilers

  //  Typkontrolle: ein \tt{B} ist kein \tt{A}!
  // SmartPointer<B> spTyp(new A);         //  Fehler!

  //  Initialisierung mit Kopierkonstruktor ist nicht möglich:
  // SmartPointer<A> spY = spA;   // Fehler!

  //  Zuweisung ist nicht möglich:
  //SmartPointer<A> spA1;
  //spA1 = spA;                                // Fehler!
}
