/* cppbuch/loesungen/k15/1/Ablage.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ABLAGE_H
#define ABLAGE_H
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>

inline std::mutex ausgabeMutex;

class Ablage {
public:
  Ablage(unsigned int platz)
      : beendet(false), inhalt(std::vector<int>(platz)), anzahl(0),
        lesePos(-1), schreibPos(0) {}  // -1 als Startwert

  int get() {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (anzahl == 0) {  // leer
      cond.wait(lock);
      if (beendet) {
        throw "get()-wait beendet";
      }
    }
    --anzahl;
    cond.notify_all();
    lesePos = (lesePos + 1) % inhalt.size();
    return inhalt[lesePos];
  }
  void put(int wert) {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (anzahl == inhalt.size()) {  // voll
      cond.wait(lock);
      if (beendet) {
        throw "put()-wait beendet";
      }
    }
    inhalt[schreibPos] = wert;
    ++anzahl;
    schreibPos = (schreibPos + 1) % inhalt.size();
    cond.notify_all();
  }
  void beenden() {  // Alle waits zwangsläufig beenden
    beendet = true;
    cond.notify_all();
  }

private:
  bool beendet;
  std::vector<int> inhalt;
  unsigned int anzahl;
  // Aufbau als Ringpuffer (FIFO)
  int lesePos;     // letzte gelesene Pos (nicht unsigned, s.o.)
  int schreibPos;  // nächste zu schreibende Pos
  std::mutex monitorMutex;
  std::condition_variable cond;
};

#endif
