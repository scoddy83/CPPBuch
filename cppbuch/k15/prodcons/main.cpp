/* cppbuch/k15/prodcons/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Ablage.h"
#include "Consumer.h"
#include "Producer.h"
using namespace std;

int main() {
  Ablage ablage;
  Producer p1(ablage, 1);
  Producer p2(ablage, 2);
  Consumer c(ablage);
  // Threads starten:
  thread tp1(std::ref(p1));
  thread tp2(std::ref(p2));
  thread tc(std::ref(c));
  // Ende der Producer abwarten:
  tp1.join();
  tp2.join();
  // Warten, bis alles abgeholt ist. Hier wird eine Zeitlang gewartet, weil der Consumer 
  // nicht wissen kann, wielange noch etwas abgelegt werden könnte.
  this_thread::sleep_for(chrono::seconds(2));
  ablage.beenden();  // wartende get()-Aufrufe beenden
  tc.join();         // Ende des Consumers abwarten
}
