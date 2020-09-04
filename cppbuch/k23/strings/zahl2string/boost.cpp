/* cppbuch/k23/strings/zahl2string/boost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Bitte double-Zahl eingeben: ";
  double d;
  cin >> d;
  try {
    string ergebnis = boost::lexical_cast<string>(d);
    cout << "String =" << ergebnis << '\n';
  } catch (boost::bad_lexical_cast& blc) {
    cerr << blc.what() << '\n';
  }
}
