/* cppbuch/k4/array2d/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "array2d.h"  // Klasse Array2d
#include <iostream>
using namespace std;

int main() {
  Array2d<int> arr(5, 7);
  arr.init(0);
  printArray(arr);  // Ausgabe mit Hilfsfunktion
  for (size_t z = 0; z < arr.getZeilen(); ++z) {
    for (size_t s = 0; s < arr.getSpalten(); ++s) {
      arr.at(z, s) = 10 * z + s;    // Benutzung, schreibend und ...
      cout << arr.at(z, s) << " ";  // lesend
    }
    cout << '\n';
  }
  printArray(arr);

  Array2d<int> arr1(arr);  // Kopierkonstruktor
  printArray(arr1);
  arr1.init(3);      // Neuinitialisierung
  arr.assign(arr1);  // Zuweisung
  printArray(arr);
  Array2d<double> arrd(3, 4, 99.013);  // \tt{double}-Array
  printArray(arrd);

  Array2d<string> arrs(2, 5, "hello");  // \tt{string}-Array
  printArray(arrs);
}
