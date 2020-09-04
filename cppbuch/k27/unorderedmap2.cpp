/* cppbuch/k27/unorderedmap2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Zwei Typdefinitionen zur Abkürzung
using MapType = unordered_map<string,
                              long>;  // Vergleichsobjekt: \tt{less<string>()}
using ValueType = MapType::value_type;

int main() {
  MapType aMap;
  aMap.insert(ValueType("Meier, Thomas", 5192835));
  aMap.insert(ValueType("Meier, Werner", 24439404));
  aMap.insert(ValueType("Meier, Manfred", 535353));
  aMap.insert(ValueType("Meier, Heiko", 635352723));
  aMap.insert(ValueType("Meier, Andreas", 42536347));
  aMap.insert(ValueType("Meier, Karin", 9273539));
  aMap.insert(ValueType("Meier, Otto", 51923835));
  aMap.insert(ValueType("Meier, Xaver", 244391404));
  aMap.insert(ValueType("Meier, Manni", 5353053));
  aMap.insert(ValueType("Meier, Jürgen", 635502723));
  aMap.insert(ValueType("Meier, Annabell", 425363047));
  aMap.insert(ValueType("Meier, Klaus", 92703539));
  aMap.insert(ValueType("Müller, Thomas", 519235));
  aMap.insert(ValueType("Müller, Werner", 2443404));
  aMap.insert(ValueType("Müller, Manfred", 535053));
  aMap.insert(ValueType("Müller, Heiko", 63532723));
  aMap.insert(ValueType("Müller, Andreas", 425306347));
  aMap.insert(ValueType("Müller, Karin", 92735039));
  aMap.insert(ValueType("Müller, Otto", 5192835));
  aMap.insert(ValueType("Müller, Xaver", 24491404));
  aMap.insert(ValueType("Müller, Manni", 53573053));
  aMap.insert(ValueType("Müller, Jürgen", 65502723));
  aMap.insert(ValueType("Müller, Annabell", 45363047));
  aMap.insert(ValueType("Müller, Klaus", 9203539));

  // Wegen der internen Hash-Struktur ist die Ausgabe unsortiert.
  cout << "Ausgabe:\n";
  for (const auto& paar : aMap) {
    cout << paar.first << ':'     // Name
         << paar.second << '\n';  // Nummer
  }

  cout << "Belegungsfaktor = " << aMap.load_factor() << '\n';
  cout << "Anzahl der Buckets = " << aMap.bucket_count() << '\n';

  for (size_t i = 0; i < aMap.bucket_count(); ++i) {
    if (aMap.bucket_size(i) > 0) {
      cout << "Bucket " << i << " : ";
      // MapType::const_local_iterator locIter = aMap.begin(i);
      auto locIter = aMap.begin(i);
      while (locIter != aMap.end(i)) {
        cout << (*locIter).first << ' ' << (*locIter).second << "    ";
        ++locIter;
      }
      cout << '\n';
    }
  }
}
