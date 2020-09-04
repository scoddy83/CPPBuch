/* cppbuch/loesungen/k10/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "liste.t"
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  Liste<int> einContainer;  // Container definieren

  // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
  for (int i = 0; i < 100; ++i) {
    einContainer.push_front(2 * i);
  }

  int zahl{0};
  while (zahl != -1) {
    cout << " gesuchte Zahl eingeben (-1 = Ende):";
    cin >> zahl;
    if (zahl != -1) {  // weitermachen?
      // std::find() benutzen
      auto position = find(einContainer.begin(),  // Container-Methoden
                           einContainer.end(), zahl);
      if (position == einContainer.end()) {
        cout << " nicht gefunden!\n";
      } else {
        cout << *position  // Dereferenzierung des Iterators
             << " gefunden!\n";
      }
    }
  }
  // Liste kopieren
  Liste<int> kopie(einContainer);
  cout << "Kopie: \n";
  while (!kopie.empty()) {
    cout << *kopie.begin() << " size()=" << kopie.size() << '\n';
    kopie.pop_front();
  }
  // Liste zuweisen
  kopie = einContainer;
  cout << "zugewiesene Kopie:\n";
  while (!kopie.empty()) {
    cout << *kopie.begin() << " size()=" << kopie.size() << '\n';
    kopie.pop_front();
  }
  // Test von erase
  zahl = 6;
  auto position = find(einContainer.begin(),  // Container-Methoden
                       einContainer.end(), zahl);
  auto next = einContainer.erase(position);
  cout << "Wert nach dem gelöschten: " << *next << '\n';
}
