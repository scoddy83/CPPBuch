/* cppbuch/k23/strings/kleingrossISO8859.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "localeutils.t"
#include <iostream>
using namespace std;

int main() {
  locale::global(locale("de_DE"));  // deDE global setzen
  string text("Falsches �ben von Xylophonmusik qu�lt jeden "
              "gr��eren Zwerg.");
  cout << "anfangs:" << text << '\n';
  gross(text);
  cout << "gross: " << text << '\n';
  klein(text);
  cout << "klein: " << text << '\n';
}
