/* cppbuch/k15/atomicstruct.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ThreadGroup.h"
#include <iostream>
#include <atomic>

struct Daten {
  int a = 0;
  int b = 0;
  void incr() {
    ++a;
    ++b;
  }
};

Daten nonAtomicDaten;
std::atomic<Daten> atomicDaten;

void testeAtomizitaet() { 
  constexpr int anzahl = 10000;
  for (int i = 0; i < anzahl; ++i) {        // atomar
    Daten temp = atomicDaten.load();        // Daten aus Memory nach \tt{temp} kopieren
    temp.incr();                            // Werte erhöhen
    atomicDaten.store(temp);                // \tt{temp} zurückschreiben
    if (temp.a != temp.b) {
      std::cout << "atomicDaten: a und b sind ungleich! Ende.\n";
      break;                                // Abbruch
    }
  }
  for (int i = 0; i < anzahl; ++i) {        // nicht-atomar
    nonAtomicDaten.incr();
    if (nonAtomicDaten.a != nonAtomicDaten.b) {
      std::cout << "nonAtomicDaten: a und b sind ungleich! Ende.\n";
      break;                                // Abbruch
    }
  }
}

int main() {
  ThreadGroup threadgroup;
  for (int i = 0; i < 10; ++i) {
    threadgroup.add_thread(testeAtomizitaet);
  }
  threadgroup.join_all();
}
