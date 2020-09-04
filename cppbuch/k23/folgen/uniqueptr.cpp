/* cppbuch/k23/folgen/uniqueptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <showContainer.h>
#include <vector>
using namespace std;

void anzeige(const vector<string*>& v) {  // Hilfsfunktion
  for (string* strPtr : v) {
    cout << *strPtr << "  ";
  }
  cout << '\n';
}

bool gleich(const string* p1, const string* p2) {
  return *p1 == *p2;  // Vergleich der Werte, nicht der Zeiger
}

bool kleiner(const string* p1, const string* p2) {
  return *p1 < *p2;  // Vergleich der Werte, nicht der Zeiger
}

int main() {
  // Vektor mit Strings
  vector<string> stringvector{"string",    "vektor",    "mit",      "mit",
                              "dubletten", "dubletten", "dubletten"};
  // Vektor mit Zeigern auf Strings
  vector<string*> v;
  for (string& str : stringvector) {
    v.push_back(&str);  // Adresse eintragen
  }
  cout << "Original:\n";
  anzeige(v);
  // Voraussetzung: Container ist sortiert
  sort(v.begin(), v.end(), kleiner);
  cout << "sortiert:\n";
  anzeige(v);
  v.erase(unique(v.begin(), v.end(), gleich), v.end());
  cout << "nach unique und erase:\n";
  anzeige(v);
}
