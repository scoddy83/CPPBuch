/* cppbuch/loesungen/k27/4.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
  multimap<int, string, greater<int>> promis;
  // multimap<int, string> promis; // umgekehrte Sortierung
  promis.insert(make_pair(7, "Jack Nicholson"));
  promis.insert(make_pair(10, "Bill Clinton"));
  promis.insert(make_pair(7, "Thomas Gottschalk"));
  promis.insert(make_pair(8, "Brad Pitt"));
  promis.insert(make_pair(8, "Peter Jackson"));
  promis.insert(pair<int, string>(10, "Tina Turner"));
  for (const auto& paar : promis) {
    cout << paar.second << ", Priorität " << paar.first << '\n';
  }
}
