/* cppbuch/k15/rw/Reader.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef READER_H
#define READER_H
#include "ReaderOderWriter.h"

class Reader : public ReaderOderWriter {
public:
  Reader(Ressource& r, const std::string& i)
      : ReaderOderWriter(r, std::string("Reader ") + i) {}
  void operator()() {
    while (!ende) {
      std::string inhalt = ressource.read(id);  // hier nicht weiter verwendet,
      // es geht nur um den reinen Lesevorgang.
      // Den nächsten Lesevorgang zufällig verzögern:
      std::this_thread::sleep_for(std::chrono::milliseconds(derZufall()));
    }
    Ressource::println(id + " beendet sich.");
  }
};

#endif
