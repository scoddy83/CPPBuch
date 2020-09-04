/* cppbuch/loesungen/k6/2/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "prof.h"
#include "student.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<Person*> diePersonen;
  diePersonen.push_back(
      new StudentIn("Herder", "Johann Gottfried", "635374"));
  diePersonen.push_back(new ProfessorIn("Kant", "Immanuel", "Philosophie"));
  diePersonen.push_back(new StudentIn("von Schön", "Theodor", "123429"));

  cout << "Vornamen:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->getVorname() << '\n';
  }

  cout << "toString() ergibt:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->toString() << '\n';
  }
  // Freigabe
  for (auto personPtr : diePersonen) {
    delete personPtr;
  }
}
