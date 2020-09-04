/* cppbuch/k8/new/eigene/Speicherverwaltung.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SPEICHERVERWALTUNG_T
#define SPEICHERVERWALTUNG_T
#include <cstddef>
#include <new>        // bad_alloc
#include <stdexcept>  // invalid_argument

template <typename T, int N> class Speicherverwaltung {
public:
  Speicherverwaltung() {
    for (std::size_t i = 0; i < N; ++i) {  // Freispeicherliste initialisieren
      freierSpeicherListe[i] = &speicher[sizeof(T) * i];
    }
  }
  static void* getMemory(std::size_t size) {
    if (size != sizeof(T)) {
      throw std::invalid_argument("getMemory(): Typ mit falscher Groesse!");
    }
    if (anzahlFreierPlaetze == 0) {
      throw std::bad_alloc();
    }
    return freierSpeicherListe[--anzahlFreierPlaetze];
  }

  static void freeMemory(void* ptr) {
    if (ptr) {  // Null-Zeiger ignorieren
      // Es wird vorausgesetzt, wie in C++ üblich, dass exakt *ein*
      // delete pro
      // new aufgerufen wird! Diesbezügliche Fehler werden nicht
      // abgefangen.
      // Nunmehr freigewordene Stelle in die Freispeicherliste
      // eintragen:
      freierSpeicherListe[anzahlFreierPlaetze++] = ptr;
    }
  }
  static std::size_t freiePlaetze() { return anzahlFreierPlaetze; }

private:
  static std::size_t anzahlFreierPlaetze;
  static void* freierSpeicherListe[N];
  static char speicher[sizeof(T) * N];
};

// Definitionen
template <typename T, int N>
std::size_t Speicherverwaltung<T, N>::anzahlFreierPlaetze = N;

template <typename T, int N>
void* Speicherverwaltung<T, N>::freierSpeicherListe[N];

template <typename T, int N>
char Speicherverwaltung<T, N>::speicher[sizeof(T) * N];

#endif
