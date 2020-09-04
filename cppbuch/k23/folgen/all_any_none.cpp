/* cppbuch/k23/folgen/all_any_none.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

auto istPositiv = [](int x) { return x >= 0; };  // zu prüfendes Prädikat

int main() {
  vector<int> folge(12);
  for (size_t i = 0; i < folge.size(); ++i) {
    folge[i] = -i - 1;  // ggf. verändern
  }
  cout << "Folge = ";
  showContainer(folge);
  if (all_of(folge.begin(), folge.end(), istPositiv)) {
    cout << "Bedingung >=0 gilt für alle Elemente\n";
  } else {
    cout << "Bedingung >=0 gilt nicht für alle Elemente\n";
  }
  if (none_of(folge.begin(), folge.end(), istPositiv)) {
    cout << "Bedingung >= 0 gilt für kein Element\n";
  } else {
    cout << "Bedingung  >=0 gilt für mindestens ein Element\n";
  }
  if (any_of(folge.begin(), folge.end(), istPositiv)) {
    cout << "Bedingung >= 0 gilt für wenigstens ein Element\n";
  } else {
    cout << "Bedingung >=0 gilt für kein Element\n";
  }
}
