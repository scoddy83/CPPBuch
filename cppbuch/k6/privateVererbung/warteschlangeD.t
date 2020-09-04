/* cppbuch/k6/privateVererbung/warteschlangeD.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WARTESCHLANGED_T
#define WARTESCHLANGED_T
#include <list>

template <typename T>
class Warteschlange {  // mit Delegation an ein \tt{list}-Objekt
                       // (Attribut \tt{liste})
public:
  bool empty() const { return liste.empty(); }
  auto size() const { return liste.size(); }
  void push(const T& x) {  // am Ende einfügen
    liste.push_back(x);
  }
  void pop() {  // am Anfang entnehmen
    liste.pop_front();
  }
  const T& front() const {  // am Anfang lesen
    return liste.front();
  }
  const T& back() const {  // am Ende lesen
    return liste.back();
  }

private:
  std::list<T> liste;
};
#endif
