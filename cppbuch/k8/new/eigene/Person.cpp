/* cppbuch/k8/new/eigene/Person.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"

// Instanziierung des Templates für die Speicherverwaltung, damit
// der Konstruktor die Freispeicherliste initialisiert.
namespace {
Person::Speicher derSpeicher;
}
