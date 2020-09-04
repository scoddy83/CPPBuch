/* cppbuch/k23/vermischtes/generate.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <Random.h>
#include <algorithm>
#include <showContainer.h>
#include <vector>
using namespace std;

int zweierpotenz() {
  static int wert = 1;  //  mit 1 anfangen
  return wert <<= 1;    // Wert verdoppeln
}

int main() {
  vector<int> v(10);
  generate(v.begin(), v.end(), zweierpotenz);
  showContainer(v);  // 2 4 8 16 32 64 128 256 512 1024

  Random zufall(10000);
  generate_n(v.begin(), v.size() / 2, zufall);
  showContainer(v);
}
