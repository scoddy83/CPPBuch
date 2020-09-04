/* cppbuch/k26/pair/pairGet.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Dasselbe wie pair.cpp, aber mit get<>() anstatt first bzw. second
#include <iostream>
#include <utility>
using namespace std;

int main() {
  pair<string, string> p1 = make_pair("Donald", "Knuth");
  pair<string, string> p2 = make_pair("Donald", "Duck");

  cout << "Vergleich zweier Paare\n";
  if (p1 > p2) {  // Anwendung von Operator >
    cout << get<0>(p2) << " " << get<1>(p2) << " liegt alphabetisch vor "
         << get<0>(p1) << " " << get<1>(p1) << '\n';
  } else {
    cout << get<0>(p1) << " " << get<1>(p1) << " liegt alphabetisch vor "
         << get<0>(p2) << " " << get<1>(p2) << '\n';
  }
}
