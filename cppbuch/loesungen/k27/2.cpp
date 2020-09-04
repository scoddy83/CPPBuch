/* cppbuch/loesungen/k27/2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

int main() {
  priority_queue<pair<int, string>> promis;
  promis.push(make_pair(7, "Jack Nicholson"));
  promis.push(make_pair(10, "Bill Clinton"));
  promis.push(make_pair(7, "Thomas Gottschalk"));
  promis.push(make_pair(8, "Brad Pitt"));
  promis.push(make_pair(8, "Peter Jackson"));
  promis.push(pair<int, string>(10, "Tina Turner"));
  while (!promis.empty()) {
    cout << promis.top().second << ", Priorität " << promis.top().first
         << '\n';
    promis.pop();
  }
}
