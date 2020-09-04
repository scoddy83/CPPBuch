/* cppbuch/k27/array/array.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <array>
#include <cstddef>
#include <iostream>
using namespace std;

int main() {
  constexpr size_t ANZAHL = 3;
  array<int, ANZAHL> tabelle{
      {9, -10}};  // Initialisierung, letztes Element ist 0

  // Benutzung mit Iterator
  for (array<int, ANZAHL>::const_iterator i = tabelle.begin();
       i != tabelle.end(); ++i) {
    cout << *i << ' ';
  }
  cout << '\n';
  // Benutzung mit Iterator und auto
  for (auto i = tabelle.begin(); i != tabelle.end(); ++i) {
    cout << *i << ' ';
  }
  cout << '\n';
  // Benutzung wie Vektor
  for (size_t i = 0; i < tabelle.size(); ++i) {
    cout << tabelle[i] << ' ';
  }
  cout << '\n';
  // Benutzung wie allg. Container
  for (auto el : tabelle) {
    cout << el << ' ';
  }
  cout << '\n';
  // Benutzung wie Tupel
  cout << get<0>(tabelle) << ' ' << get<1>(tabelle) << ' ' << get<2>(tabelle)
       << '\n';
}
