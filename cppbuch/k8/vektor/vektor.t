/* cppbuch/k8/vektor/vektor.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// dynamische Vektor-Klasse
#ifndef VEKTOR_T
#define VEKTOR_T
#include <algorithm>  // copy()
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>  // swap()

template <typename T> class Vektor {
public:
  Vektor(std::size_t anzahl = 1);           // Allg. Konstruktor
  Vektor(std::size_t n, T t);  // 2. Allg. Konstruktor: n Elemente mit Wert t
  Vektor(std::initializer_list<T>);         // Sequenzkonstruktor
  Vektor(const Vektor<T>& v);               // Kopierkonstruktor
  virtual ~Vektor() {                       // Destruktor
    delete[] start;
  }

  auto size() const { return anzahl; }

  void groesseAendern(std::size_t);         // dynamisch ändern

  T& operator[](std::size_t index) {        // Indexoperator inline
    if (index >= anzahl) {
      throw std::out_of_range("Indexüberschreitung!");
    }
    return start[index];
  }

  // Indexoperator für nicht-veränderliche Vektoren
  const T& operator[](std::size_t index) const {
    if (index >= anzahl) {
      throw std::out_of_range("Indexüberschreitung!");
    }
    return start[index];
  }

  // Zuweisungsoperator
  // Vektor<T>& operator=(const Vektor<T>&);
  Vektor<T>& operator=(Vektor<T>);  // Übergabe per Wert, siehe Impl. unten
  void swap(Vektor<T>& v);                  // Vektoren vertauschen

  // Zeiger auf Anfang und Position nach dem Ende für Vektoren
  // mit nichtkonstanten und konstanten Elementen
  T* begin() { return start; }
  T* end() { return start + anzahl; }
  const T* begin() const { return start; }
  const T* end() const { return start + anzahl; }
private:
  std::size_t anzahl;                       // Anzahl der Datenobjekte
  T* start;                                 // Zeiger auf Datenobjekte
};

/********** Implementierung ****************/

template <typename T>
Vektor<T>::Vektor(std::size_t anz)  // erster Allg. Konstruktor 
  : anzahl{anz}, start{new T[anz]} {}

template <typename T>
Vektor<T>::Vektor(std::size_t anz, T wert)  // Allg. Konstruktor 2
  : Vektor(anz) {                         // Delegation an obigen Konstruktor
  for (std::size_t i = 0; i < anzahl; ++i) {
    start[i] = wert;
  }
}

template <typename T>
Vektor<T>::Vektor(std::initializer_list<T> liste)  // Sequenzkonstruktor
  : Vektor(liste.size()) {                // Delegation an obigen Konstruktor
  std::copy(liste.begin(), liste.end(), start);
}

template <typename T>
Vektor<T>::Vektor(const Vektor<T>& v)       // Kopierkonstruktor
  : Vektor(v.anzahl) {                    // Delegation an obigen Konstruktor
  for (std::size_t i = 0; i < anzahl; ++i) {
    start[i] = v.start[i];
  }
}

template <typename T> void Vektor<T>::swap(Vektor<T>& v) {
  std::swap(anzahl, v.anzahl);
  std::swap(start, v.start);
}

// Alternative mit 'swap-Trick'
template <typename T>
Vektor<T>& Vektor<T>::operator=(Vektor<T> v) {  // Zuweisung
  swap(v);
  return *this;
}

template <typename T>
void Vektor<T>::groesseAendern(std::size_t neueGroesse) {
  T* pTemp{new T[neueGroesse]};// neuen Speicherplatz besorgen
  // die richtige Anzahl von Elementen kopieren
  std::size_t kleinereZahl{neueGroesse > anzahl ? anzahl : neueGroesse};
  for (std::size_t i = 0; i < kleinereZahl; ++i) {
    pTemp[i] = start[i];
  }
  delete[] start;                           // alten Speicherplatz freigeben
  start = pTemp;                            // Verwaltungsdaten aktualisieren
  anzahl = neueGroesse;                     // Verwaltungsdaten aktualisieren
}
#endif  // VEKTOR_T
