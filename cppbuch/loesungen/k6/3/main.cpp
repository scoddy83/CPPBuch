/* cppbuch/loesungen/k6/3/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "../2/prof.h"
#include "../2/student.h"
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

  /* Da im obigen Programm Zeiger auf Person verwendet werden,
  erfordert ein Zugriff auf Methoden, die nicht in Person
  deklariert sind, eine Typumwandlung. Beispiel: */

  cout << "Die Matrikelnummer von " << diePersonen[0]->getNachname()
       << " ist "
       << static_cast<StudentIn*>(diePersonen[0])->getMatrikelnummer()  // !
       << '\n';
  /* Die Typumwandlung in den Typ StudentIn*
  funktioniert natürlich nur, wenn man genau weiß, dass der
  Zeiger an der Stelle 0 auf ein Objekt des dynamischen Typs
  StudentIn verweist.
  Was aber, wenn man es nicht genau weiß? Dazu geben die Abschnitte
  'Standard-Typumwandlungsoperatoren' und
  'Typinformationen zur Laufzeit' Auskunft
  */
  // Freigabe
  for (auto personPtr : diePersonen) {
    delete personPtr;
  }
}
