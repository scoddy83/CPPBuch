/* cppbuch/k10/einf/mitSTL.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> einContainer(100);  // Container definieren

  // Container mit beliebigen Werten füllen (hier: gerade Zahlen)
  for (unsigned int i = 0; i < einContainer.size(); ++i) {
    einContainer[i] = 2 * i;
  }

  int zahl{0};
  while (zahl != -1) {
    cout << " gesuchte Zahl eingeben (-1 = Ende):";
    cin >> zahl;
    if (zahl != -1) {  // weitermachen?
      // \tt{std::find()} benutzen
      // \tt{auto = vector<int>::const\_iterator}
      auto position = find(einContainer.begin(),  // Container-Methoden
                           einContainer.end(), zahl);
      if (position != einContainer.end()) {
        cout << "gefunden an Position " << (position - einContainer.begin())
             << '\n';
      } else {
        cout << zahl << " nicht gefunden!\n";
      }
    }
  }
}
