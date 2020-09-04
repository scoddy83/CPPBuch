/* cppbuch/k15/prodcons/Ablage.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ABLAGE_H
#define ABLAGE_H
#include <condition_variable>
#include <mutex>
#include <thread>

inline std::mutex ausgabeMutex;

class Ablage {
public:
  int get() {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (!belegt) {
      cond.wait(lock);
      if (beendet) {
        throw "get()-wait beendet";
      }
    }
    belegt = false;
    cond.notify_one();
    return inhalt;
  }
  void put(int wert) {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (belegt) {
      cond.wait(lock);
      if (beendet) {
        throw "put()-wait beendet";
      }
    }
    belegt = true;
    inhalt = wert;
    cond.notify_one();
  }
  void beenden() {  // Alle \tt{wait()}-Aufrufe zwangsläufig beenden
    beendet = true;
    cond.notify_all();
  }

private:
  bool belegt{false};
  bool beendet{false};
  int inhalt;
  std::mutex monitorMutex;
  std::condition_variable cond;
};

#endif
