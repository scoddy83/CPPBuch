//CPPBuch/K1/Übung 1.18
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct StudentIn {
  string name;
  string martikelnummer;
};

int main () {
  vector<StudentIn> studenten;
  string dateiname;
  cout << "Quelldatei? : ";
  cin >> dateiname;

  ifstream datei(dateiname);
  if(!datei.good()) {
    cerr << dateiname << " kann nicht geoeffnet werden!\n";
    exit(-1);
  }
  while (datei) {
    string zeile;
    getline(datei, zeile);
    if(zeile == "#") { // Endekennung gefunden
      break;
    }
    StudentIn student;
    student.name = zeile;
    getline(datei, zeile);
    student.martikelnummer = zeile;
    studenten.push_back(student);
  }
  datei.close();

  // auslesen des Vectors
  for (StudentIn student : studenten) {
    cout << "\nName: " << student.name << " Martikelnummer: " << student.martikelnummer;
  }

  // Aufgabe B
  string input;
  while (true) {
    cout << "\n\nBitte geben Sie eine Martikelnummer ein (Beenden mit 'X'): ";
    cin >> input;
    if(input == "x" || input == "X") {
      break;
    } else {
      bool gefunden = false;
      for (StudentIn student : studenten) {
        if(input == student.martikelnummer) {
          cout << "Der Student mit der Martikelnummer " << input << " ist unter dem Namen : "
               << student.name << " angemeldet.";
          gefunden = true;
          break;
        }
      }
      if(!gefunden) {
        cout << "Keinen Studenten mit der Martikelnummer: " << input << " gefunden.";
      }
    }
  }
  cout << "Programm wird beendet!!";
}
