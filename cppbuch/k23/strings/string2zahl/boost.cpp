/* cppbuch/k23/strings/string2zahl/boost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Bitte Zeichenkette eingeben (z.B. 3.14) : ";
  string zeile;
  getline(cin, zeile);
  try {
    double d = boost::lexical_cast<double>(zeile);
    cout << "Zahl = " << d << '\n';
  } catch (boost::bad_lexical_cast& blc) {
    cerr << blc.what() << '\n';
  }
}
