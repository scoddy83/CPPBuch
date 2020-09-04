/* cppbuch/k23/folgen/count.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <algorithm>
#include <cstddef>
#include <showContainer.h>
#include <vector>
using namespace std;

bool ungerade(int zahl) { return zahl % 2 != 0; }

int main() {
  vector<int> v;
  Random zufall(1000);
  for (size_t i = 0; i < 20; ++i) {
    v.push_back(zufall());
  }
  showContainer(v);
  int gesucht = 383;
  cout << "Es sind " << count(v.begin(), v.end(), gesucht)
       << " Elemente mit dem Wert " << gesucht << " vorhanden.\n";

  cout << "Es sind " << count_if(v.begin(), v.end(), ungerade)
       << " ungerade Elemente vorhanden.\n";
}
