/* cppbuch/k19/templateInst/inklusion/meintyp.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef MEINTYP_T
#define MEINTYP_T
#include <vector>

template <typename T> class MeinTyp {
public:
  MeinTyp(T par) : attribut(par) {}
  T get() {
    std::vector<T> v;
    v.push_back(T());  // vector benutzen
    return attribut;
  }

private:
  T attribut;
};
#endif
