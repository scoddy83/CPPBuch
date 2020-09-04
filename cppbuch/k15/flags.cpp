/* cppbuch/k15/flags.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "CallWrapper.h"
#include "Worker.h"
using namespace std;

int main() {
  Worker worker;
  CallWrapper<Worker> aufrufer(worker);
  thread t(aufrufer);
  int stunde{8};
  while (!worker.istBeendet()) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << ++stunde << " Uhr: ";
    switch (stunde) {
    case 10:
      worker.warten();  // Pause
      break;
    case 13:
      worker.weiter();  // Fortsetzung
      break;
    case 16:
      worker.beenden();  // Ende
      t.join();          // Ende abwarten
      break;
    default:
      if (stunde > 16) {
        throw "Fehler!";
      }
    }
  }
}
