/* cppbuch/k5/stack/simstack2.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// ein einfaches Stack-Template (benutzt in simmain2.cc)
#ifndef SIMSTACK2_T
#define SIMSTACK2_T
#include <cassert>
// Parameter \tt{MAX\_SIZE} zur Festlegung der Stackgröße
template<typename T, unsigned int MAX_SIZE>
class SimpleStack {
public:
  bool empty() const { return anzahl == 0; }
  bool full() const { return anzahl == MAX_SIZE; }
  unsigned int size() const { return anzahl; }
  void clear() { anzahl = 0; }  // Stack leeren

  const T& top() const;  // letztes Element sehen
  void pop();            // Element entnehmen
  // Vorbedingung für top und pop: Stack ist nicht leer

  void push(const T& x);  // x auf den Stack legen
  // Vorbedingung für push: Stack ist nicht voll

private:
  unsigned int anzahl{0};  // Anfangswert
  T array[MAX_SIZE];        // Behälter für Elemente

};

// noch fehlende Implementierungen
template<typename T, unsigned int m>    // Parameter \tt{m} wird nicht benutzt
const T& SimpleStack<T, m>::top() const  { 
  assert(!empty());
  return array[anzahl-1];
}

template<typename T, unsigned int m>    // Parameter \tt{m} wird nicht benutzt
void SimpleStack<T, m>::pop() {
  assert(!empty());
  --anzahl;
}

template<typename T, unsigned int m>    // Parameter \tt{m} wird nicht benutzt
void SimpleStack<T, m>::push(const T& x) {
  assert(!full());
  array[anzahl++] = x;
}
#endif  // SIMSTACK2_T
