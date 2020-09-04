/* cppbuch/k15/rw/Writer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WRITER_H
#define WRITER_H
#include "ReaderOderWriter.h"

class Writer : public ReaderOderWriter {
public:
  Writer(Ressource& r, const std::string& i)
      : ReaderOderWriter(r, std::string("Writer ") + i) {}
  void operator()() {
    int nr = 0;
    while (!ende) {
      std::string nachricht("Nachricht Nr.");
      // Umwandlung der Zahl in einen string
      nachricht += std::to_string(++nr);
      ressource.write(nachricht, id);
      // Den nächsten Schreibvorgang zufällig verzögern:
      std::this_thread::sleep_for(std::chrono::milliseconds(derZufall()));
    }
    Ressource::println(id + " beendet sich.");
  }
};

#endif
