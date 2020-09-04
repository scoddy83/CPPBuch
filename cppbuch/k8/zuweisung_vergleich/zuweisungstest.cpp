/* cppbuch/k8/zuweisung_vergleich/zuweisungstest.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Nur systemgenerierte Funktionen und direkten Wertevergleich nutzen
#include <iostream>
using std::cout;

struct Ober {
  Ober(int i) : iO(i) {}
  virtual ~Ober() = default;
  int iO;                                   // Daten der Klasse \tt{Ober}
};

struct Unter : public Ober {
  Unter(int i, int d) : Ober(i), iU(d) {}
  int iU;                                  // Daten der Klasse \tt{Unter}
};

void vergleicheUnterObjekte(const Ober& o1, const Ober& o2) {
  auto u1 = dynamic_cast<const Unter&>(o1);
  auto u2 = dynamic_cast<const Unter&>(o2);
  if (u2.iO && u1.iU == u2.iU) {
    cout << "Werte stimmen überein.\n";
  } else {
    cout << "Werte stimmen NICHT überein:\nOberklassenwerte:  "
         << u1.iO << ", " << u2.iO << " Unterklassenwerte: " 
         << u1.iU << ", " << u2.iU
         << '\n';
  }
}

int main() {
  Unter u1(1, 2);
  Unter u2(3, 4);
  cout << "'normale' Zuweisung Unter = Unter: ";
  u1 = u2;  // 'normale' Zuweisung
  vergleicheUnterObjekte(u1, u2);
  Unter u3(5, 6);
  // statischer und dynamischer Typ sind verschieden:
  cout << "poymorphe Zuweisung Ober& = Unter: ";
  Ober& rO2 = u2;                           // \tt{rO2} ist eine Referenz auf ein \tt{Unter}-Objekt
  rO2 = u3;              // funktioniert nicht mit dem systemgenerierten operator=(). Beweis:
  vergleicheUnterObjekte(rO2, u3);
}
