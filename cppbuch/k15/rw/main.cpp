/* cppbuch/k15/rw/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../ThreadGroup.h"
#include "Reader.h"
#include "Ressource.h"
#include "Writer.h"

int main() {
  Ressource ressource;

  Writer w1(ressource, "w1");
  Writer w2(ressource, "w2");
  Reader r1(ressource, "r1");
  Reader r2(ressource, "r2");
  Reader r3(ressource, "r3");
  Reader r4(ressource, "r4");

  ThreadGroup threadgroup;
  threadgroup.add_thread(w1);
  threadgroup.add_thread(r1);
  threadgroup.add_thread(r2);
  threadgroup.add_thread(r3);
  threadgroup.add_thread(r4);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  threadgroup.add_thread(w2);

  // Threads eine Zeit lang laufen lassen
  std::this_thread::sleep_for(std::chrono::seconds(10));
  w1.beenden();
  w2.beenden();
  r1.beenden();
  r2.beenden();
  r3.beenden();
  r4.beenden();
  threadgroup.join_all();                   // warten, bis alles beendet ist
}
