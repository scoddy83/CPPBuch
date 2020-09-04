/* cppbuch/k27/vector/strvec.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel mit Vektor von Strings
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> stringVec(4);
  stringVec[0] = "First";
  stringVec[1] = "Second";
  stringVec[2] = "Third";
  stringVec[3] = "Fourth";

  // vector increases size on demand
  stringVec.insert(stringVec.end(), string("Last"));
  cout << "size() = " << stringVec.size() << '\n';  // 5

  // Element 'Second' entfernen
  auto iter = stringVec.begin();
  ++iter;  // 2. Position
  cout << "erase: " << *iter << '\n';
  stringVec.erase(iter);                            // Second loeschen
  cout << "size() = " << stringVec.size() << '\n';  // 4
  for (auto iter1 = stringVec.begin(); iter1 != stringVec.end(); ++iter1)
    cout << *iter1 << '\n';

  cout << "backwards with reverse_iterator:\n";
  for (auto revI = stringVec.rbegin(); revI != stringVec.rend(); ++revI)
    cout << *revI << '\n';
}
