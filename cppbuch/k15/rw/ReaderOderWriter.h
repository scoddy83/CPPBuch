/* cppbuch/k15/rw/ReaderOderWriter.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef READERODERWRITER_H
#define READERODERWRITER_H
#include <Random.h>
#include "Ressource.h"

class ReaderOderWriter {
public:
  virtual void operator()() = 0;
  virtual void beenden() final { ende = true; }

protected:
  ReaderOderWriter(Ressource& r, const std::string& i) : ressource(r), id{i} {}
  virtual ~ReaderOderWriter() = default;
  ReaderOderWriter(const ReaderOderWriter&) = default;
  ReaderOderWriter& operator=(const ReaderOderWriter&) = default;
  bool ende{false};
  Ressource& ressource;
  std::string id;
  Random derZufall {500, 1000};
};
#endif
