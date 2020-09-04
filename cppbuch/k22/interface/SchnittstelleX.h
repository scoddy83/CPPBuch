/* cppbuch/k22/interface/SchnittstelleX.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SCHNITTSTELLEX_H
#define SCHNITTSTELLEX_H
#include "Daten.h"

class SchnittstelleX {
public:
  virtual void service(Daten& d) = 0;   // abstrakte Klasse
  virtual ~SchnittstelleX() = default;  // virtueller Destruktor
  SchnittstelleX() = default;
  SchnittstelleX(const SchnittstelleX&) = default;
  SchnittstelleX& operator=(const SchnittstelleX&) = default;
};

#endif
