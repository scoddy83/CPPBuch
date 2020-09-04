/* cppbuch/loesungen/k6/4_5/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../2/prof.h"
#include "../2/student.h"
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main() {
  vector<Person*> diePersonen;
  diePersonen.push_back(
      new StudentIn("Herder", "Johann Gottfried", "635374"));
  diePersonen.push_back(new ProfessorIn("Kant", "Immanuel", "Philosophie"));
  diePersonen.push_back(new StudentIn("von Schön", "Theodor", "123429"));

  cout << "toString() ergibt:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->toString() << '\n';
  }

  cout << "Die Matrikelnummern mit dynamic_cast:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->getVorname() << ": ";
    StudentIn* ps = dynamic_cast<StudentIn*>(personPtr);
    if (ps) {
      cout << ps->getMatrikelnummer() << '\n';
    } else {
      cout << " hat keine Matrikelnummer.\n";
    }
  }

  cout << "\nDie Matrikelnummern mit typeid:\n";
  for (auto personPtr : diePersonen) {
    cout << personPtr->getVorname();
    if (typeid(StudentIn) == typeid(*personPtr)) {
      cout << ": "
           << (static_cast<StudentIn*>(personPtr))->getMatrikelnummer()
           << '\n';
    } else {
      cout << " (interner Typ: " << typeid(*personPtr).name()
           << ") hat keine Matrikelnummer.\n";
    }
  }
  // Freigabe
  for (auto personPtr : diePersonen) {
    delete personPtr;
  }
}
