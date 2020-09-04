/* cppbuch/k26/forward/forward.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../../k11/move/movingstring.h"
#include <utility>

#define USE_FORWARD

class Haustier {
public:
#ifdef USE_FORWARD
  template <class T> Haustier(T&& n) : name(std::forward<T>(n)) {}
#else
  Haustier(const StringTyp& n) : name(n) {}
  Haustier(StringTyp&& n) : name(std::move(n)) {  // 3 new
    //: name(n) {                         // 4 new (n ist Lvalue)
  }
#endif
private:
  StringTyp name;
};

int main() {
  StringTyp katzenname("Mauz");
  Haustier katze1(katzenname);  // Lvalue
  Haustier katze2("Miezi");     // Rvalue (StringTyp("Miezi"))
}
