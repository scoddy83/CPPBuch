/* cppbuch/k23/vermischtes/transform.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <locale>
#include <showContainer.h>
#include <string>
#include <vector>

std::string upper_case(std::string s) {  // unäre Operation als Funktion
  transform(s.begin(), s.end(), s.begin(), toupper);
  return s;
}

struct Verketten {  //  binäre Operation als Funktor
  std::string operator()(const std::string& a, const std::string& b) const {
    return a + " und " + b;
  }
};

using namespace std;

int main() {
  locale::global(locale("de_DE"));  // falls Umlaute vorkommen
  // (Windows und MinGW-Compiler: Zeile streichen, locale("de_DE")
  // ist
  // nicht vorhanden

  vector<string> maedels{"Annabelle", "Scheherazade", "Julia"};
  vector<string> jungs{"Nikolaus", "Amadeus", "Romeo"};
  if (maedels.size() != jungs.size()) {
    cout << "Paarbildung nicht möglich!\n";
  } else {
    vector<string> paare(maedels.size());

    transform(jungs.begin(), jungs.end(),
              jungs.begin(),  // Ziel == Quelle
              upper_case);    // in Großbuchstaben wandeln

    transform(maedels.begin(), maedels.end(), jungs.begin(), paare.begin(),
              Verketten());

    showContainer(paare, "", "\n");  // gebildete Paare ausgeben
  }
}
