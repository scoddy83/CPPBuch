/* cppbuch/loesungen/k23/1/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "heap.t"
#include <iostream>
using namespace std;

int main() {
  Heap<pair<int, string>> promis;
  promis.push(make_pair(7, "Jack Nicholson"));
  promis.push(make_pair(10, "Bill Clinton"));
  promis.push(make_pair(7, "Thomas Gottschalk"));
  promis.push(make_pair(8, "Brad Pitt"));
  promis.push(make_pair(8, "Peter Jackson"));
  promis.push(pair<int, string>(10, "Tina Turner"));

  cout << "Sortiert:\n";
  for (const auto& paar : promis.toSortedVector()) {
    cout << paar.second << ", Priorität " << paar.first << '\n';
  }

  cout << "Leeren:\n";
  while (!promis.empty()) {
    cout << promis.top().second << ", Rang " << promis.top().first
         << " size=" << promis.size() << '\n';
    promis.pop();
  }
}
