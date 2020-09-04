/* cppbuch/loesungen/k32/1/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "prof.h"
#include "student.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
  vector<shared_ptr<Person>> diePersonen;
  diePersonen.push_back(
      make_shared<StudentIn>("Herder", "Johann Gottfried", "635374"));
  diePersonen.push_back(
      make_shared<ProfessorIn>("Kant", "Immanuel", "Philosophie"));
  diePersonen.push_back(
      make_shared<StudentIn>("von Schön", "Theodor", "123429"));

  cout << "Vornamen:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->getVorname() << '\n';
  }

  cout << "toString() ergibt:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->toString() << '\n';
  }
  /* Da im obigen Programm shared_ptr auf Person verwendet werden,
  erfordert ein Zugriff auf Methoden, die nicht in Person
  deklariert sind, eine Typumwandlung. Beispiel: */

  cout << "Matrikelnummern:\n";
  for (auto personPtr : diePersonen) {
    auto kandidat = dynamic_pointer_cast<StudentIn>(personPtr);
    if (kandidat) {
      cout << kandidat->getNachname() << "   "
           << kandidat->getMatrikelnummer() << '\n';
    }
  }
}
