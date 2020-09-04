/* cppbuch/k5/klasseMitKonstanten/KlasseMitKonstanten.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef KLASSEMITKONSTANTE_H
#define KLASSEMITKONSTANTE_H
#include <string>

class KlasseMitKonstanten {
public:
  enum aufzaehlung { null, eins, zwei, drei };
  enum class RGB { rot = 0x0001, gelb = 0x0002, blau = 0x0004 };
  static constexpr double CONST_DOUBLE{ 0.1234};  // Literale erfordern \tt{constexpr}.
  static const int CONST_INT{1000};  // Bei integralen Literalen reicht  \tt{const}.
  static const std::string CONST_STR1;  // externe Initialisierung
  static inline const std::string CONST_STR2 = "ABC";  // inline-Initialisierung
private:
  static int cArray[CONST_INT];  // beispielhafte interne Verwendung
                                 // ..
};

#endif
