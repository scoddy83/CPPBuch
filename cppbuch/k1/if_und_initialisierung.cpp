/* cppbuch/k1/if_und_initialisierung.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  float eingabe;
  cin >> eingabe;

  {  // Blockbeginn
    float x = sin(eingabe);
    if (x >= 0) {
      cout << x << " ist null oder positiv!\n";
    } else {
      cout << x << " ist negativ!\n";
    }
  }  // x ist ab hier ungültig

  // kürzer und gleichwertig ist:
  if (float x = sin(eingabe); x >= 0) {
    cout << x << " ist null oder positiv!\n";
  } else {
    cout << x << " ist negativ!\n";
  }  // x ist hier ungültig

  auto f{8.};
  cout << f << '\n';
}
