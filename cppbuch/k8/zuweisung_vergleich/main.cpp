/* cppbuch/k8/zuweisung_vergleich/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Zuweisung in einer Klassenhierarchie mit 3 Klassen.
// Jede Klasse hat einen  Zuweisungsoperator, damit kein
// Zuweisungsoperator implizit erzeugt wird, sowie eine Methode
// assign, die die eigentliche Arbeit erledigt.

#include "C.h"                              // schließt A.h, B.h ein
#include <cassert>
#include <iostream>
using namespace std;

int main() {
  // Klasse A
  cout << "\nTest 1\n";
  A a1(1);
  A a2(2);
  a1.ausgabe();
  cout << '\n';
  a1 = a2;
  cout << "a1 nach Zuweisung a1=a2:\n";
  a1.ausgabe();
  cout << '\n';
  assert(a1 == a2);

  // Klasse B
  cout << "\nTest 2\n";
  B b1(1, 2);
  B b2(3, 4);
  b1.ausgabe();
  cout << '\n';
  b1 = b2;
  cout << "b1 nach Zuweisung b1=b2:\n";
  b1.ausgabe();
  cout << '\n';
  assert(b1 == b2);

  cout << "\nTest 3  polymorphe Zuweisung\n";
  B b3(5, 6);
  A& ar = b1;                               // Oberklassenreferenz
  ar = b3;
  cout << "ar nach Zuweisung ar=b3:\n";
  ar.ausgabe();
  cout << '\n';
  assert(ar == b3);

  // Klasse C
  cout << "\nTest 4\n";
  C c1(1, 2, 3);
  C c2(4, 5, 6);
  c1.ausgabe();
  cout << '\n';
  c1 = c2;
  cout << "c1 nach Zuweisung c1=c2:\n";
  c1.ausgabe();
  cout << '\n';
  assert(c1 == c2);

  cout << "\nTest 5 :  polymorphe Zuweisung A& = C\n";
  C c3(7, 8, 9);
  A& arc = c2;                              // Oberklassenreferenz
  arc = c3;
  cout << "arc nach Zuweisung arc=c3:\n";
  arc.ausgabe();
  cout << '\n';
  assert(arc == c3);

  cout << "\nTest 6 :  polymorphe Zuweisung B& = C\n";
  B& brc(c2);                               // Oberklassenreferenz
  brc = c3;
  cout << "brc nach Zuweisung brc=c3:\n";
  brc.ausgabe();
  cout << '\n';
  assert(brc == c3);

  cout << "\nTest 7 :  falscher Typ: b1 = c3\n";
  try {
    b1 = c3;
  } catch (const bad_typeid& e) {
    cerr << "Falscher Typ! Exception: " << e.what() << '\n';
  }

  cout << "\nTest 8 :  falscher Typ: a1 = c3\n";
  try {
    a1 = c3;
  } catch (const bad_typeid& e) {
    cerr << "Falscher Typ! Exception: " << e.what() << '\n';
  }
  cout << "Test-Ende\n";
}
