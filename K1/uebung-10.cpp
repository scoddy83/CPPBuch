//CPPBuch/K1/Übung 1.10
#include <iostream>
#include <string>
using namespace std;


struct Person {
  string vorname;
  string nachname;
  int alter;
};

int main () {
  Person p1;

  cout << "Bitte geben Sie Daten zur Ihrer Person an : \n\n";
  cout << "Vorname :  ";
  cin >> p1.vorname;
  cout << "\nNachname :  ";
  cin >> p1.nachname;
  cout << "\nAlter :  ";
  cin >> p1.alter;

  cout << "\n\n";
  cout << "Vielen Dank für die Angaben zur Ihrer Person!\n";
  cout << "Bitte prüefen Sie diese.\n\n";

  cout << "Vorname :  " << p1.vorname << '\n';
  cout << "Nachname :  " << p1.nachname << '\n';
  cout << "Alter :  " << p1.alter << '\n';

}
