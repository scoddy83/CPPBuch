/* cppbuch/loesungen/k15/2/Producer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PRODUCER_H
#define PRODUCER_H
#include "Ablage.h"
#include <Random.h>
#include <iostream>

class Producer {
public:
  Producer(Ablage& a, int i) : ablage(a), id(i), zufall(100) {}
  void operator()() {
    for (int i = 0; i < 5; ++i) {
      int wert = id * 10 + i;
      std::this_thread::sleep_for(std::chrono::milliseconds(100 + zufall()));

      try {
        ablage.put(wert);
        std::lock_guard<std::mutex> lock(ausgabeMutex);
        std::cout << "Producer Nr. " << id << "  legt ab: " << wert
                  << std::endl;
      } catch (...) {
        ;  // nichts tun, Producer ist beendet
      }
    }
    std::lock_guard<std::mutex> lock(ausgabeMutex);
    std::cout << "Producer " << id << " beendet sich." << std::endl;
  }

private:
  Ablage& ablage;
  int id;
  Random zufall;
};

#endif
