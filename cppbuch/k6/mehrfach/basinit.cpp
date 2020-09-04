/* cppbuch/k6/mehrfach/basinit.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

class Basis {
public:
  Basis() { std::cout << "Basis-Standardkonstruktor\n"; }
  Basis(const char* a) { std::cout << a << '\n'; }
  virtual ~Basis() = default;  // virtueller Destruktor
  Basis(const Basis&) = default;
  Basis& operator=(const Basis&) = default;
};

class Links : virtual public Basis {
public:
  Links(const char* a)
  //  : Basis(a)                      // siehe Text
  {}
};

class Rechts : virtual public Basis {
public:
  Rechts(const char* a) : Basis(a) {}
};

class Unten : public Links, public Rechts {
public:
  Unten(const char* a)
      :  //       Basis(a),               // siehe Text
        Links(a),
        Rechts(a) {}
};

int main() {
  Unten x("Unten");
  Links li("Links");
}
