/* cppbuch/loesungen/k3/1/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "person.h"
#include <iostream>
using namespace std;

int main() {
  Person person("Annabella Meier", 22, Geschlecht::w);
  cout << person.getName() << " ist " << person.getAlter() << " Jahre alt.\n";
  person.setAlter(person.getAlter() + 1);  // Geburtstag
  cout << person.getName() << " hatte Geburtstag. Sie ist jetzt "
       << person.getAlter() << " Jahre alt.\n";
  person.setName("Annabella Schulz");  // Namensänderung
  cout << "Sie hat auch geheiratet. Ihr Name ist jetzt " << person.getName()
       << ".\n";

  if (person.istFrau()) {
    cout << person.getName() << " ist eine Frau.\n";
  }
  if (person.istMann()) {
    cout << person.getName() << " ist ein Mann.\n";
  }
}
