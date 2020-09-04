/* cppbuch/k27/vector/intvec.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <vector>
#include <showContainer.h>
using namespace std;

int main() {
  // int-Vektor mit 10 Elementen
  vector<int> intV(10);

  for (size_t i = 0; i < intV.size(); ++i) {
    intV[i] = static_cast<vector<int>::value_type>(i);  // Vektor füllen
  }
  // Vektor wächst dynamisch
  intV.insert(intV.end(), 100);  //  100 anhängen

  // Benutzung wie Array
  for (size_t i = 0; i < intV.size(); ++i)
    cout << intV[i] << '\n';

  // Benutzung mit Iterator
  for (auto I = intV.begin(); I != intV.end(); ++I)
    cout << *I << '\n';

  vector<int> neuerVektor(20, 0);  // alle Elemente nullen

  cout << " neuerVektor = ";

  for (size_t i = 0; i < neuerVektor.size(); ++i)
    cout << neuerVektor[i] << ' ';

  // swap() ist eine schnelle Methode zur Vertauschung zweier
  // Vektoren
  neuerVektor.swap(intV);

  cout << "\n neuerVektor nach swap() = ";
  for (size_t i = 0; i < neuerVektor.size(); ++i)
    cout << neuerVektor[i] << ' ';  // alter Inhalt von  intV

  cout << "\n\n intV        = ";
  for (size_t i = 0; i < intV.size(); ++i)
    cout << intV[i] << ' ';  //  alter Inhalt von  neuerVektor
  cout << "\nAlternativ mit showContainer():\n";
  showContainer(intV);
  cout << '\n';
}
