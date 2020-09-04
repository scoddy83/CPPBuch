/* cppbuch/k30/sortv.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <locale>
#include <showContainer.h>
#include <string>
#include <vector>
using namespace std;

int main() {
  locale dt("de_DE");
  cout << "dt.name()= " << dt.name() << '\n';
  locale::global(dt);  // dt für alles setzen, Rückgabewert ignorieren
  vector<string> v;
  v.push_back("Mucke");
  v.push_back("Mücke");
  v.push_back("Macke");
  v.push_back("Murks");
  sort(v.begin(), v.end());  // falsch  : Macke Mucke Murks Mücke
  showContainer(v);
  sort(v.begin(), v.end(), dt);  // korrekt: Macke Mucke Mücke Murks
  showContainer(v);
}
