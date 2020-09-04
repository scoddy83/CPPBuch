/* cppbuch/k4/cstrarray.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiele für Zugriff auf String-Array
#include <iostream>
using namespace std;

int main() {
  const char* sa[] = {"eins", "zwei"};
  const char** sp = sa;  // Zeiger auf const char*
  // Programmausgabe:
  cout << sa[0] << '\n';     // eins
  cout << *sa << '\n';       // eins
  cout << sa[1] << '\n';     // zwei
  cout << sa[1][0] << '\n';  // z
  cout << *sp << '\n';       // eins
  cout << sp[1] << '\n';     // zwei
}
