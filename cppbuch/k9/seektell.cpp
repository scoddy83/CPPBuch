/* cppbuch/k9/seektell.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel zum Positionieren von Dateien

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream einIfstream("seek.dat", ios::binary);
  einIfstream.seekg(9);  // absolute Leseposition 9 suchen (Zählung ab 0)
  char c;
  einIfstream.get(c);  // get schaltet Pos. weiter
  cout << c << " an Position 9 gefunden\n";
  // 2 relativ zur aktuellen Position (10) weiterbewegen
  einIfstream.seekg(2, ios::cur);
  ios::pos_type position = einIfstream.tellg();
  einIfstream.get(c);
  cout << c << " an Position 12 gefunden\n";
  einIfstream.seekg(-4, ios::end);  // 4 Positionen vor dem Ende
  einIfstream.get(c);
  cout << c << " an der viertletzten Position gefunden\n";
  einIfstream.seekg(position, ios::beg);  // an alte Position (12) gehen
  einIfstream.get(c);
  cout << c << " an Position 12 gefunden\n";
}
