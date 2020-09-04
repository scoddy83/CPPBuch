/* cppbuch/k27/unorderedmap.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, long> dieKaffeerunde{{"Andreas", 5192835},
                                             {"Manfred", 535353},
                                             {"Thomas", 635352723},
                                             {"Uli", 42536347},
                                             {"Ulrike", 9273539}};
  // Das zweite Einfügen von Andreas mit einer anderen Telefonnummer
  // wird \emph{nicht} ausgeführt, weil der Schlüssel schon
  // existiert.
  dieKaffeerunde.insert({"Andreas", 1000000});

  // Wegen der internen Hash-Struktur ist die Ausgabe unsortiert.
  cout << "Ausgabe:\n";
  for (const auto& paar : dieKaffeerunde) {
    cout << paar.first << ':'     // Name
         << paar.second << '\n';  // Nummer
  }
  cout << "Ausgabe der Nummer nach Eingabe des Namens\nName: ";
  string derName;
  cin >> derName;
  cout << "Suche mit Iterator: ";
  auto iter = dieKaffeerunde.find(derName);  // O(1)
  if (iter != dieKaffeerunde.end()) {
    cout << (*iter).second << '\n';
  } else {
    cout << "Nicht gefunden!\n";
  }
  cout << "Belegungsfaktor = " << dieKaffeerunde.load_factor() << '\n';
  cout << "Anzahl der Buckets = " << dieKaffeerunde.bucket_count()
       << ". Belegt sind:\n";
  for (size_t i = 0; i < dieKaffeerunde.bucket_count(); ++i) {
    if (dieKaffeerunde.bucket_size(i) > 0) {
      cout << "Bucket " << i << " : ";
      auto locIter = dieKaffeerunde.begin(i);  // \tt{auto}:
      // \tt{unordered\_map<string, long>::const\_local\_iterator}
      while (locIter != dieKaffeerunde.end(i)) {
        cout << (*locIter).first << ' ' << (*locIter).second << "    ";
        ++locIter;
      }
      cout << '\n';
    }
  }
}
