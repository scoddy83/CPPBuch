/* cppbuch/k27/mergemap.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, string> woerterbuch1;
  woerterbuch1.insert({"Buch", "book"});
  woerterbuch1.insert({"Gesellschaft", "society"});
  woerterbuch1.insert_or_assign("Lehrer", "teacher");// neu

  map<string, string> woerterbuch2;
  woerterbuch2.insert({"Gesellschaft", "party"});  // Schlüssel "Gesellschaft" existiert
  // Übertragen aller Elemente, zu denen *kein* Schlüssel in woerterbuch2 existiert
  woerterbuch2.merge(woerterbuch1);

  cout << "Wörterbuch 1:\n";
  for (const auto& eintrag : woerterbuch1) {
    cout << eintrag.first << " : " << eintrag.second << '\n';   // Schlüssel, Daten
  }
  cout << "Wörterbuch 2:\n";
  for (const auto& eintrag : woerterbuch2) {
    cout << eintrag.first << " : " << eintrag.second << '\n';   // Schlüssel, Daten
  }
}
