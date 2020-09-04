/* cppbuch/k15/prodcons/Consumer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef CONSUMER_H
#define CONSUMER_H
#include "Ablage.h"
#include <iostream>

class Consumer {
public:
  Consumer(Ablage& a) : ablage(a) {}
  void operator()() {
    try {
      while (true) {              // Abbruch mit Exception
        int wert = ablage.get();  // Exception-Quelle
        std::lock_guard<std::mutex> lock(ausgabeMutex);
        std::cout << "Consumer hat " << wert << " geholt." << std::endl;
      }
    } catch (...) {
      std::lock_guard<std::mutex> lock(ausgabeMutex);
      std::cout << "Consumer beendet sich." << std::endl;
    }
  }

private:
  Ablage& ablage;
};
#endif
