/* cppbuch/k1/inttypen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <limits>
using namespace std;  // Alle Typen sind in std

int main() {
  // erforderliche Typen. Annahme: 1 Byte = 8 Bits
  static_assert(sizeof(int_fast8_t) >= 1, "Fehler!");
  static_assert(sizeof(int_fast16_t) >= 2, "Fehler!");
  static_assert(sizeof(int_fast32_t) >= 4, "Fehler!");
  static_assert(sizeof(int_fast64_t) >= 8, "Fehler!");
  static_assert(sizeof(uint_fast8_t) >= 1, "Fehler!");
  static_assert(sizeof(uint_fast16_t) >= 2, "Fehler!");
  static_assert(sizeof(uint_fast32_t) >= 4, "Fehler!");
  static_assert(sizeof(uint_fast64_t) >= 8, "Fehler!");

  static_assert(sizeof(int_least8_t) >= 1, "Fehler!");
  static_assert(sizeof(int_least16_t) >= 2, "Fehler!");
  static_assert(sizeof(int_least32_t) >= 4, "Fehler!");
  static_assert(sizeof(int_least64_t) >= 8, "Fehler!");
  static_assert(sizeof(uint_least8_t) >= 1, "Fehler!");
  static_assert(sizeof(uint_least16_t) >= 2, "Fehler!");
  static_assert(sizeof(uint_least32_t) >= 4, "Fehler!");
  static_assert(sizeof(uint_least64_t) >= 8, "Fehler!");

  static_assert(sizeof(intmax_t) >= sizeof(size_t), "Fehler!");
  static_assert(sizeof(uintmax_t) >= sizeof(size_t), "Fehler!");

  // optionale Typen (d.h. Fehlermeldungen des Compilers,
  // wenn die Typen nicht vorhanden sind)
  static_assert(sizeof(int8_t) == 1, "Fehler!");
  static_assert(sizeof(int16_t) == 2, "Fehler!");
  static_assert(sizeof(int32_t) == 4, "Fehler!");
  static_assert(sizeof(int64_t) == 8, "Fehler!");

  const char* pc = "Literal";
  const void* voidzeiger = static_cast<const void*>(pc);
  // Umwandlung der Adresse in eine Zahl
  const uintptr_t uintptr_tZahl = reinterpret_cast<uintptr_t>(voidzeiger);
  // Die Rückumwandlung muss dieselbe Adresse ergeben
  assert(voidzeiger == reinterpret_cast<void*>(uintptr_tZahl));
}
