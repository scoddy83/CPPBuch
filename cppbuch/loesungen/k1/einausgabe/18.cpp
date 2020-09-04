/* cppbuch/loesungen/k1/einausgabe/18.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Loesung noch ohne Funktionen
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct StudentIn {
  string name;
  string matrikelnummer;
};

int main() {
  vector<StudentIn> studierende;
  cout << "Einlesen (Aufgabenteil A):\n";
  ifstream daten("datenzuAufg18.txt");
  while (daten) {
    string zeile;
    getline(daten, zeile);
    if (zeile == "#") {  // Endekennung gefunden
      break;
    }
    StudentIn student;
    student.name = zeile;
    getline(daten, zeile);
    student.matrikelnummer = zeile;
    studierende.push_back(student);
  }
  daten.close();
  if (studierende.empty()) {  // oder \tt{size() == 0}
    cout << "keine Daten vorhanden!\n";
    return 1;
  }
  // Testausgabe
  for (auto stud : studierende) {
    cout << stud.name << "   " << stud.matrikelnummer << '\n';
  }

  cout << "Namen suchen (Aufgabenteil B):\n";
  string gesuchteMatNr;
  while (true) {
    cout << "Matrikelnummer? (X = Ende)";
    cin >> gesuchteMatNr;
    if (gesuchteMatNr == "X" || gesuchteMatNr == "x") {
      break;
    } else {
      bool gefunden = false;
      for (auto stud : studierende) {
        if (gesuchteMatNr == stud.matrikelnummer) {
          cout << stud.name << " gefunden.\n";
          gefunden = true;
          break;
        }
      }
      if (!gefunden) {
        cout << "nicht gefunden!\n";
      }
    }
  }
  cout << "Programmende" << '\n';
}
