/* cppbuch/loesungen/k5/4/meinstack.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Ein  Stack-Template, das intern ein vector-Objekt benutzt.
// Dabei befindet sich das jeweils zuletzt auf dem Stack abgelegte
// Element am Ende des Vectors.
#ifndef MEINSTACK_T
#define MEINSTACK_T
#include <cassert>
#include <vector>

template <typename T> class MeinStack {
public:
  bool empty() const { return vec.empty(); }

  auto size() const { return vec.size(); }

  void clear() {  // Stack leeren
    vec.clear();
  }

  const T& top() const {  // letztes Element sehen
    assert(!empty());     // assert, weil back() undefiniert
    return vec.back();    // reagiert, wenn vec leer ist.
  }

  void pop() {         // Element entfernen
    assert(!empty());  // assert, weil pop_back() undefiniert
    vec.pop_back();    // reagiert, wenn vec leer ist.
  }

  void push(const T& x) {  // x auf den Stack legen
    vec.push_back(x);
  }

private:
  std::vector<T> vec;  // Behälter für Elemente
};
#endif  // MEINSTACK_T
