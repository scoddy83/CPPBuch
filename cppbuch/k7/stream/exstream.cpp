/* cppbuch/k7/stream/exstream.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

class DateiEnde : public exception {  // Hilfsklasse (siehe unten)
};                                    // erbt von \tt{exception},  siehe Seite
                                      // \pageref{exceptionklasse}

int liesZahl(std::istream& ein) {
  int i;
  ein >> i;
  // Das \tt{eof}-Bit bewirkt den Auswurf eines Objekts vom Typ
  // \tt{DateiEnde}, das hier
  // durch den Aufruf des systemgenerierten Konstruktors erzeugt
  // wird,
  // an den
  // umgebenden Kontext. Die Eingabe von falschen Zeichen setzt das
  // \tt{fail}-Bit, das
  // durch die Funktion \tt{fail()} abgefragt  wird und den Auswurf
  // eines
  // \tt{const char*}-Objekts bewirkt. Jedes \tt{throw} führt zum
  // Verlassen der Funktion.
  // Details zu \tt{eof()}, \tt{fail()} und  \tt{bad()} siehe
  // Abschnitt \ref{IOFehler}.
  if (ein.eof())
    throw DateiEnde();
  if (ein.fail())
    throw "Syntaxfehler";
  if (ein.bad())
    throw;  // nicht behebbarer Fehler
  return i;
}  // \tt{liesZahl()}

void zahlen_lesen_und_ausgeben() {
  int zahl;
  while (true) {
    cout << "Zahl eingeben: ";

    bool erfolgreich = true;
    // Versuchsblock
    try {
      //  Zahl von der Standardeingabe lesen:
      zahl = liesZahl(cin);
    }

    // Fehlerbehandlung: Der folgende Ausnahme-Handler wird
    // angesprungen,
    // wenn ein Objekt des Typs \tt{DateiEnde} im \tt{try}-Block
    // ausgeworfen wurde.
    catch (const DateiEnde& e) {
      cout << "Ende der Datei erreicht!\n"
           << "e.what() liefert: " << e.what() << '\n';
      cin.clear();  // Fehlerbits rücksetzen
      break;        // Schleife verlassen
    }
    // Der folgende Ausnahme-Handler wird angesprungen, wenn ein
    // Objekt des Typs
    // \tt{const char*} ausgeworfen wurde. Die Funktion
    // \tt{liesZahl()} wirft einen
    // C-String aus, wenn in der Eingabe die Syntax von
    // \tt{int}-Zahlen
    // verletzt wird, zum Beispiel Buchstaben statt Ziffern.
    catch (const char* z) {
      cerr << z << '\n';
      erfolgreich = false;
      cin.clear();  // Fehlerbits rücksetzen
      cin.get();    // fehlerhaftes Zeichen entfernen
    }

    // \tt{bad()} wird nicht abgefangen, ggf. Programmabbruch.
    // Fortsetzung des Programms nach der Fehlerbehandlung
    if (erfolgreich)
      cout << "Zahl =  " << zahl << '\n';
  }
}

int main() { zahlen_lesen_und_ausgeben(); }
