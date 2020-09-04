/* cppbuch/k4/langstr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  const char* const TEXT = "Bei Initialisierung, Zuweisung, oder "
                           "Ausgabe kann ein Stringliteral wie hier auch aus "
                           "einzelnen Teilstrings zusammengesetzt werden.";
  cout << TEXT << "\nenthält " << strlen(TEXT) << " Zeichen\n";
}
