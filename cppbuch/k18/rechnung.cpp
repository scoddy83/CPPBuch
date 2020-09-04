/* cppbuch/k18/rechnung.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Datenbank.h"
#include <iostream>

namespace {
// SQL-Zahlen auf 2 dargestellte Nachkommazahlen bringen
std::string formatPreis(const std::string& s) {
  auto punkt = s.find('.');
  if (punkt == std::string::npos) {
    return s + ".00";
  } else if (s.length() - punkt == 2) {
    return s + "0";
  }
  return s;
}
}

int main(int argc, char** argv) {
  enum Struktur {
    NR,
    DATUM,
    NAME,
    PLZ,
    ORT,
    STRNR,
    MENGE,
    ARTNR,
    BEZ,
    EPREIS,
    GPREIS
  };

  try {
    Datenbank db("shopdb.db");
    Array2d<std::string> rechnungen = db.execute("select * from alles");
    std::string rechnNr("");
    unsigned int z = 1;
    bool rechnungskopfGedruckt = false;
    while (z < rechnungen.getZeilen()) {
      if (rechnNr != rechnungen[z][NR]) {  // neue Rechnung beginnt
        rechnNr = rechnungen[z][NR];
        rechnungskopfGedruckt = false;
      }
      if (rechnungen[z][NAME] != "") {  // Kunde existiert, kein Barverkauf
        unsigned int position = 0;
        if (!rechnungskopfGedruckt) {
          std::cout << "Herrn/Frau/Firma " << rechnungen[z][NAME] << '\n'
                    << rechnungen[z][STRNR] << '\n'
                    << rechnungen[z][PLZ] << " " << rechnungen[z][ORT]
                    << "\n\n\nRechnung Nr. " << rechnNr << "  vom "
                    << rechnungen[z][DATUM]
                    << "\nPos. Menge   Artikelnr.        Bezeichnung "
                       "Einzelpreis Gesamtpreis\n";
          rechnungskopfGedruckt = true;
          position = 1;
        }
        // Positionen ausgeben
        std::cout.width(4);
        std::cout << position++;
        std::cout.width(6);
        std::cout << rechnungen[z][MENGE];
        std::cout.width(12);
        std::cout << rechnungen[z][ARTNR];
        std::cout.width(20);
        std::cout << rechnungen[z][BEZ];
        std::cout.width(12);
        std::cout << formatPreis(rechnungen[z][EPREIS]);
        std::cout.width(12);
        std::cout << formatPreis(rechnungen[z][GPREIS]) << '\n';
      }
      ++z;
      if (rechnungskopfGedruckt &&
          (z == rechnungen.getZeilen() ||
           (z < rechnungen.getZeilen() && rechnNr != rechnungen[z][NR]))) {
        Array2d<std::string> summe =
            db.execute("select sum(Preis*Menge) from alles where "
                       "Rechnungsnr=" +
                       rechnNr + ";");
        std::cout.width(66);
        std::cout << "-----------\n";
        std::cout.width(66);
        std::cout << formatPreis(summe[1][0]) << "\n\f\n";  // Seitenvorschub
      }
    }
  } catch (const SQLError& e) {
    std::cerr << e.what() << '\n';
  }
}
