/* cppbuch/k30/numpunct.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
using namespace std;

int main() {
  locale loc;  // Kopie des aktuellen globalen \tt{locale}-Objekts
  char dezPunkt = use_facet<numpunct<char>>(loc).decimal_point();
  cout << "Dezimalpunkt = " << dezPunkt << '\n';
  // oder
  string wahr = use_facet<numpunct<char>>(loc).truename();
  cout << wahr << '\n';  // Ausgabe: {\sl true}

  locale de("en_US");  // standard-locale loc: grouping bleibt
  // leer (Zahlen ohne Tausenderpunkt)
  string grouping = use_facet<numpunct<char>>(de).grouping();
  cout << "grouping() =\n";
  for (char c : grouping) {
    cout << static_cast<int>(c) << '\n';  // 3 3
  }
}
