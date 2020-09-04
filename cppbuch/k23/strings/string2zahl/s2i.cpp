/* cppbuch/k23/strings/string2zahl/s2i.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

// Wandelt Zeichenkette in int um, bis ein nicht umwandelbares
// Zeichen kommt. Überlauf wird geprüft.
int s2i(const std::string& str) {
  int vorzeichen = 1;
  int ergebnis = 0;
  bool fehler = true;
  if (str.length() > 0) {
    std::size_t idx = 0;
    if (str[idx] == '-') {
      vorzeichen = -1;
      ++idx;
    }
    while (idx < str.length() && isdigit(str[idx])) {
      // Überlaufprüfung
      std::string bereichsfehler("Zahl ist zu groß für diesen Typ!");
      int grenze = std::numeric_limits<int>::max() / 10;
      if (ergebnis > grenze) {
        throw std::out_of_range(bereichsfehler);
      }
      int ziffer = str[idx] - '0';
      if (ergebnis == grenze) {
        int maxziffer = (vorzeichen == 1 ? 7 : 8);  // gilt auch f. long
        if (ziffer > maxziffer) {
          throw std::out_of_range(bereichsfehler);
        }
      }
      // kein Überlauf und wenigstens eine Ziffer gefunden
      ergebnis = 10 * ergebnis + ziffer;
      fehler = false;
      ++idx;
    }
  }
  if (fehler)
    throw std::invalid_argument("Konversion nicht möglich!");
  return vorzeichen * ergebnis;
}

using namespace std;

int main() {
  cout << "Bitte Zeichenkette eingeben (z.B. -12345): ";
  string zeile;
  getline(cin, zeile);
  try {
    cout << s2i(zeile) << '\n';
  } catch (const invalid_argument& ia) {
    cerr << ia.what() << '\n';
  } catch (const out_of_range& oor) {
    cerr << oor.what() << '\n';
  }
}
