/* cppbuch/k30/geld/euro.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Geld.h"
#include <iostream>
#include <locale>
#include <string>

using MeinMoneypunct =
    std::moneypunct_byname<char, true>;      // \tt{true} für Internationalisierung

class MeinWaehrungsformat : public MeinMoneypunct {
protected:
  // Überschreiben der virtuellen Funktion \tt{do\_curr\_symbol()}, die von der 
  //\tt{public}-Funktion \tt{curr\_symbol()} der Basisklasse {\tt moneypunct} gerufen wird:
  std::string do_curr_symbol() const { return wsymbol; }

public:
  MeinWaehrungsformat(const std::locale& loc, const char* ws)
      : MeinMoneypunct(loc.name().c_str()), wsymbol(ws) {
  }

private:
  const char* wsymbol;
};

using namespace std;

int main() {
  locale locUS("en_US");
  Geld derBetrag;
  cout << "Eingabe in Cent(!), z.B. 123456:?";
  cin >> derBetrag;
  cout << "direkte Abfrage mit voreingestellter locale (" 
       << locale().name()                          // \tt{locale 'C'}
       << ") :" << derBetrag.getBetrag() << '\n';  // 123456
  cout.imbue(locUS);                               // \tt{cout} auf enUS umschalten
  cout << "Es wurde " << derBetrag
       << " eingegeben (US-Format).\n";            // USD 1,234.56
  locale deDEeuro("de_DE");
  cout << "Ausgabe Standard-Währungssymbol EUR und Dezimalkomma statt "
          "Dezimalpunkt :\n";
  // Achtung: KEINE Währungsumrechnung, nur Darstellungsänderung!
  cout.imbue(deDEeuro);                            // \tt{cout} auf deDE@euro umschalten
  cout << derBetrag << '\n';                       // 1.234,56 EUR
  MeinWaehrungsformat mwf(deDEeuro, 
                   "\u20ac");                      // Euro in UTF-8
                                                   // \tt{\BS xA4} in ISO-8859-15
  cout << "Ausgabe eigenes Währungssymbol und Dezimalkomma statt "
          "Dezimalpunkt :\n";
  cout.imbue(locale(deDEeuro, &mwf));
  cout << derBetrag << '\n';  // 1.234,56 \euro
}
