/* cppbuch/loesungen/k15/1/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Ablage.h"
#include "Consumer.h"
#include "Producer.h"
using namespace std;

int main() {
  Ablage ablage(10);
  Producer p1(ablage, 1);
  Producer p2(ablage, 2);
  Consumer c1(ablage, 1);
  Consumer c2(ablage, 2);
  // Threads starten:
  thread tp1(p1);
  thread tp2(p2);
  this_thread::sleep_for(chrono::milliseconds(400));
  thread tc1(c1);
  thread tc2(c2);
  // Ende der Producer abwarten:
  tp1.join();
  tp2.join();
  // warten, bis alle Objekte konsumiert worden sind
  this_thread::sleep_for(chrono::seconds(2));
  ablage.beenden();  // get-waits beenden
  tc1.join();        // Ende des Consumers 1 abwarten
  tc2.join();        // Ende des Consumers 2 abwarten
}
