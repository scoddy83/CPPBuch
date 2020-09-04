/* cppbuch/loesungen/k1/10.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
using namespace std;

struct Person {  // Person-Typ anlegen
  string nachname;
  string vorname;
  int alter;
};

int main() {
  Person diePerson;  // Person-Objekt anlegen
  cout << "Nachnamen eingeben: ";
  cin >> diePerson.nachname;
  cout << "Vornamen eingeben: ";
  cin >> diePerson.vorname;
  cout << "Alter eingeben: ";
  cin >> diePerson.alter;
  cout << "Die Person hat folgende Daten:" << '\n';
  cout << "Nachname    : " << diePerson.nachname << '\n';
  cout << "Vorname     : " << diePerson.vorname << '\n';
  cout << "Alter       : " << diePerson.alter << '\n';
}
