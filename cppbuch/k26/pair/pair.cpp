/* cppbuch/k26/pair/pair.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <utility>
using namespace std;

int main() {
  pair<string, string> p1 = make_pair("Donald", "Knuth");
  pair<string, string> p2 = make_pair("Donald", "Duck");

  cout << "Vergleich zweier Paare\n";
  if (p1 > p2) {  // Anwendung von Operator >
    cout << p2.first << " " << p2.second << " liegt alphabetisch vor "
         << p1.first << " " << p1.second << '\n';
  } else {
    cout << p1.first << " " << p1.second << " liegt alphabetisch vor "
         << p2.first << " " << p2.second << '\n';
  }
}
