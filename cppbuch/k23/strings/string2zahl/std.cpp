/* cppbuch/k23/strings/string2zahl/std.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
using namespace std;

int main() {
  cout << "Bitte Zeichenkette eingeben (z.B. 3.14 oder 12345 oder "
           "0x78 FF oder 0123): ";
  string zeile;
  getline(cin, zeile);
  size_t endpos;  // erste nicht mehr ausgewertete Position
  int modus[]{-1, 0, 2, 8, 10, 16};
  vector<string_view> modusText {"double",           // -1
                     "Standard (0 okt/0x hex/dez)",  //  0
                     "Binärzahl",                    //  2
                     "Oktalzahl",                    //  8
                     "Dezimalzahl",                  // 10
                     "Hexadezimalzahl"};             // 16
  for (size_t i = 0; i < modusText.size(); ++i) {
    try {
      cout << "Interpretation als " << modusText[i] << ": ";
      if (-1 == modus[i]) {                          // double
        cout << stod(zeile, &endpos);
      } else {                                       // int
        cout << stoi(zeile, &endpos, modus[i]);
      }
      if (endpos < zeile.length()) {
        cout << " nicht ausgewertet: " << (zeile.c_str() + endpos);
      }
      cout << '\n';
    } catch (const invalid_argument&) {
      cerr << "Konversion ist nicht möglich!\n";
    } catch (const out_of_range&) {
      cerr << "Zahl ist außerhalb des Bereichs für diesen Typ!\n";
    }
  }
}
