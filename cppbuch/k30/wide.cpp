/* cppbuch/k30/wide.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
  locale dt("de_DE.utf-8");
  // cout << "dt.name()= " << dt.name() << '\n';
  // Ausgabe mit cout stört nachfolgende wcout-Ausgaben (GNU C++
  // 4.x)

  locale::global(dt);  // dt fuer alles setzen
  wstring ws(L"ÄÖÜäöüß");
  wcout.imbue(dt);
  wcout << "Ausgabe mit wcout: " << ws << '\n';
  wcout << L"Länge=" << ws.length() << '\n';
  wcout << "sizeof(wchar_t): " << sizeof(wchar_t) << '\n';
  wofstream wdatei("ausgabe.txt");
  wdatei << "Ausgabe in wofstream: " << ws << '\n';
  for (unsigned int i = 0; i < ws.length(); ++i) {
    wdatei << "WZeichen " << i << ": " << ws[i] << '\n';
  }
  for (auto& wc : ws) {
    wc = toupper(wc, dt);
  }
  wcout << "nach toupper(): " << ws << '\n';
}
