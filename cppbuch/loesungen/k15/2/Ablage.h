/* cppbuch/loesungen/k15/2/Ablage.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ABLAGE_H
#define ABLAGE_H
#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

inline std::mutex ausgabeMutex;

class Ablage {
public:
  Ablage(unsigned int platz) : beendet(false), kapazitaet(platz) {}


  int get() {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (inhalt.size() == 0) {  // leer
      cond.wait(lock);
      if (beendet) {
        throw "get()-wait beendet";
      }
    }
    cond.notify_all();
    auto erstes = inhalt.front();
    inhalt.pop_front();
    return erstes;
  }
  void put(int wert) {
    std::unique_lock<std::mutex> lock(monitorMutex);
    while (kapazitaet == inhalt.size()) {  // voll
      cond.wait(lock);
      if (beendet) {
        throw "put()-wait beendet";
      }
    }
    inhalt.push_back(wert);
    cond.notify_all();
  }
  void beenden() {  // Alle waits zwangsläufig beenden
    beendet = true;
    cond.notify_all();
  }

private:
  bool beendet;
  unsigned int kapazitaet;
  std::deque<int> inhalt;
  std::mutex monitorMutex;
  std::condition_variable cond;
};

#endif
