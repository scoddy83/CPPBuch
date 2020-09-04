/* cppbuch/k5/meinstring/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "meinstring.h"
#include <iostream>
using namespace std;

int main() {
  MeinString leererString;
  cout << "leerer String. Länge = " << leererString.length() << '\n';

  MeinString einString("Hallo");
  cout << "Hallo: Länge = " << einString.length() << '\n';
  anzeigen(cout, einString);
  cout << "\nzeichenweise Ausgabe:\n";
  for (size_t i = 0; i < einString.length(); ++i) {
    cout << '*' << einString.at(i);
  }
  cout << "*\n";
  for (auto c : einString) {
    cout << '_' << c;
  }
  cout << "_\n";
  // Zuweisen
  MeinString zweiterString;
  zweiterString = einString;
  cout << "zugewiesener String: ";
  anzeigen(cout, zweiterString);
  cout << '\n';
  cout << "Zuweisen einer kurzen Zeichenkette (Platz reicht)\n";
  einString.assign("ABC");
  const void* adresse1 = static_cast<const void*>(einString.data());
  cout << adresse1 << '\n';
  cout << "Inhalt: " << einString.data() << "  Länge: " << einString.length()
       << '\n';
  cout << "Zuweisen einer langen Zeichenkette (Platz muss neu "
          "beschafft werden)\n";
  einString.assign("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  cout << "Inhalt: " << einString.data() << "  Länge: " << einString.length()
       << '\n';
  // Prüfung der Optimierung von vector::operator=
  MeinString kurz("abcd");
  // einString hat genug Platz. Bleiben Adressen erhalten?
  const void* adresse2 = static_cast<const void*>(einString.data());
  cout << adresse2 << '\n';
  if (adresse1 != adresse2) {
    cout << "Es wurde Speicher beschafft.\n";
  } else {
    cout << "Es wurde vorhandener Speicher benutzt.\n";
  }
  einString = kurz;
  cout << "Inhalt: " << einString.data() << "  Länge: " << einString.length()
       << '\n';
  const void* adresse3 = static_cast<const void*>(einString.data());
  cout << adresse3 << '\n';
  if (adresse3 != adresse2) {
    cout << "Es wurde Speicher beschafft.\n";
  } else {
    cout << "Es wurde vorhandener Speicher benutzt.\n";
  }
}
