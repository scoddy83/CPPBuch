/* cppbuch/loesungen/k15/1/Consumer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef CONSUMER_H
#define CONSUMER_H
#include "Ablage.h"
#include <iostream>

class Consumer {
public:
  Consumer(Ablage& a, int i) : ablage(a), id(i) {}
  void operator()() {
    try {
      while (true) {
        int wert = ablage.get();
        std::lock_guard<std::mutex> lock(ausgabeMutex);
        std::cout << "Consumer " << id << " hat " << wert << " geholt."
                  << std::endl;
      }
    } catch (...) {
      std::lock_guard<std::mutex> lock(ausgabeMutex);
      std::cout << "Consumer " << id << " beendet sich." << std::endl;
    }
  }

private:
  Ablage& ablage;
  int id;
};

#endif
