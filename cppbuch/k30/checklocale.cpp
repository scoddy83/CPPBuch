/* cppbuch/k30/checklocale.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <locale>
#include <stdexcept>
using namespace std;

int main() {
  locale env("");
  cout << "aktuell eingestellte Locale: " << env.name() << '\n';

  const char* locales[] = {
      // alle Systeme:
      "C",  // classic C
      "",   // eingestellte Umgebung
      // manche Systeme
      "de_DE", "en_US", "es_ES" };       // Deutsch, am. Englisch, Spanisch
  cout << "\nTest der locale-Unterstuetzung fuer C++:\n\n";
  for (auto locstring : locales) {
    cout << "locale \"" << locstring << "\" wird von diesem C++-Compiler ";
    try {
      locale loc(locstring);
      cout << "unterstuetzt.\n";
    } catch (const runtime_error& e) {
      cout << "NICHT unterstuetzt.\n";
    }
  }
}
