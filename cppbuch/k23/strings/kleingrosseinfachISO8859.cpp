/* cppbuch/k23/strings/kleingrosseinfachISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstring>
#include <iostream>
#include <locale>
#include <string>

void kleinEinfach(std::string& str) {
  for (auto& c : str) {
    c = tolower(c);  // benutzt eingestellte Locale
  }
}
void grossEinfach(std::string& str) {
  for (auto& c : str) {
    c = toupper(c);  // benutzt eingestellte Locale
  }
}
using namespace std;

int main() {
  locale::global(locale("de_DE"));  // deDE global setzen
  string text("Falsches Üben von Xylophonmusik quält jeden "
              "größeren Zwerg.");
  cout << "anfangs:" << text << '\n';
  grossEinfach(text);
  cout << "grossEinfach: " << text << '\n';
  kleinEinfach(text);
  cout << "kleinEinfach: " << text << '\n';
}
