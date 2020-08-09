//CPPBuch/K2/Übung 2.1
#include <iostream>
using namespace std;

struct Dauer {
  int stunden;
  int minuten;
  int sekunden;
} dauer;

int dauerInSekunden(int, int, int);

int main() {
  cout << "Bitte geben Sie die Sunden an: ";
  cin >> dauer.stunden;
  cout << "Bitte geben Sie die Minuten an: ";
  cin >> dauer.minuten;
  cout << "Bitte geben Sie die Sekunden an: ";
  cin >> dauer.sekunden;

  cout << "Dauer in Sekunden:  " << dauerInSekunden(dauer.stunden, dauer.minuten, dauer.sekunden);

  return 0;
}

int dauerInSekunden(int stunden, int minuten, int sekunden) {
  return sekunden + minuten*60 + stunden*3600;
}
