/* cppbuch/k30/inout.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
using namespace std;

int main() {
  cin.imbue(locale("de_DE"));
  cout.imbue(locale("en_US"));
  double f;
  while (cin >> f) {  // implizite Nutzung von \tt{num\_get}
    cout << f << '\n';
  }  // implizite Nutzung von \tt{num\_put}
}
