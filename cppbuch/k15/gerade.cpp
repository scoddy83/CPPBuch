/* cppbuch/k15/gerade.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ThreadGroup.h"
#include <iostream>
#include <mutex>
using namespace std;

namespace {
mutex mtx;
}

class Gerade {
public:
  Gerade() : n(0) {}
  int next() {
    // Kommentarzeichen in der Folgezeile fuer korrekte Funktion entfernen!
    //lock_guard<mutex> lock(mtx); // neu
    ++n;
    ++n;
    return n;
  }
  int getWert() const { return n; }

private:
  int n;
};

Gerade g;

void testeGerade() {
  for (int i = 0; i < 10000; ++i) {
    int wert = g.next();
    if (wert % 2 != 0) {
      cout << wert << " ist ungerade! Thread beendet.\n";
      break;
    }
  }
}

int main() {
  ThreadGroup threadgroup;
  for (int i = 0; i < 20; ++i) {
    threadgroup.add_thread(testeGerade);
  }
  threadgroup.join_all();
}
