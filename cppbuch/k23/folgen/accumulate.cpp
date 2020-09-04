/* cppbuch/k23/folgen/accumulate.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> v(10);
  iota(v.begin(), v.end(), 1);
  cout << "Summe = " << accumulate(v.begin(), v.end(), 0)  // 55
       << '\n';

  cout << "Produkt = " << accumulate(v.begin(), v.end(), 1L,
                                     multiplies<long>())  // 3628800
       << '\n';

  // accumulate mit string
  vector<string> vstr(26);
  iota(vstr.begin(), vstr.end(), 'A');  // Vektor mit Buchstaben füllen
  cout << accumulate(vstr.begin(), vstr.end(), string("Alphabet: ")) << '\n';
}
