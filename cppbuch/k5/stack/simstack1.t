/* cppbuch/k5/stack/simstack1.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// ein einfaches Stack-Template (benutzt in simmain1.cpp)
#ifndef SIMSTACK1_T
#define SIMSTACK1_T
#include <cassert>

template <typename T> class SimpleStack {
public:
  static const unsigned int MAX_SIZE{20};  // siehe Text
  // inline definierte Methoden
  bool empty() const { return anzahl == 0; }

  bool full() const { return anzahl == MAX_SIZE; }

  auto size() const { return anzahl; }

  void clear() {                            // Stack leeren
    anzahl = 0;
  }

  // Methoden, deren Implementation unten folgt
  const T& top() const;                     // letztes Element sehen
  void pop();                               // Element entfernen
  // Vorbedingung für top und pop: Stack ist nicht leer

  void push(const T& x);                   // x auf den Stack legen
  // Vorbedingung für push: Stack ist nicht voll
private:
  unsigned int anzahl{0};                  // Anfangswert
  T array[MAX_SIZE];                       // Behälter für Elemente
};

// noch fehlende Methoden-Implementierungen nur als
// beispielhafte Alternative zur inline-Definition oben
template <typename T>
const T& SimpleStack<T>::top() const {
  assert(!empty());
  return array[anzahl - 1];
}

template <typename T>
void SimpleStack<T>::pop() {
  assert(!empty());
  --anzahl;
}

template <typename T>
void SimpleStack<T>::push(const T& x) {
  assert(!full());
  array[anzahl++] = x;
}
#endif  // SIMSTACK1_T
