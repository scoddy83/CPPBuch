/* cppbuch/k27/woerterbuch.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <functional>                       // für ggf. \tt{greater<string>}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  using MapType = map<string, string>;
  //using MapType = map<string, string, greater<string>>;
  using Paar = MapType::value_type;
  MapType woerterbuch;
  woerterbuch.insert(Paar("Firma", "company"));   // Schlüssel, Daten
  woerterbuch.insert(pair<string, string>("Objekt", "object"));
  // mit  \tt{make\_pair()}:
  woerterbuch.insert(make_pair("Blume", "flower"));
  // direkt, ohne \tt{make\_pair()} (Aggregat-Initialisierung):
  woerterbuch.insert({"Buch", "book"});
  // einfügen mit \tt{emplace()}
  woerterbuch.emplace("Kuchen", "cake");
  cout << woerterbuch["Buch"] << '\n';  // assoziativer Zugriff
  // Alphabetisch sortierte Ausgabe deutsch : englisch
  for (const auto& eintrag : woerterbuch) {
    cout << eintrag.first << " : " << eintrag.second << '\n';   // Schlüssel, Daten
  }
}
