/* cppbuch/loesungen/k29/2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "rangvergleich.h"
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
  multimap<int, string, greater<int>> promis;
  promis.insert(make_pair(7, "Jack Nicholson"));
  promis.insert(make_pair(10, "Bill Clinton"));
  promis.insert(make_pair(7, "Thomas Gottschalk"));
  promis.insert(make_pair(8, "Brad Pitt"));
  promis.insert(make_pair(8, "Peter Jackson"));
  promis.insert(pair<int, string>(10, "Tina Turner"));
  for (const auto& paar : promis) {
    cout << paar.second << ", Priorität " << paar.first << '\n';
  }

  // nur der Rang interessiert, siehe rangvergleich.h
  pair<int, string> gesuchtesPaar(8, "Dummy");
  cout << "Es gibt folgende Einträge mit Rang " << gesuchtesPaar.first
       << ":\n";

  //   pair<multimap<int, string, greater<int> >::iterator,
  //        multimap<int, string, greater<int> >::iterator>
  auto bereich = equal_range(promis.begin(), promis.end(), gesuchtesPaar,
                             Rangvergleich());

  for (auto iter = bereich.first; iter != bereich.second; ++iter) {
    cout << (*iter).second << '\n';
  }
}
