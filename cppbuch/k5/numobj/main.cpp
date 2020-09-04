/* cppbuch/k5/numobj/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// main.cpp: Demonstration von nummerierten Objekten
#include "numobj.h"
#include <iostream>
using namespace std;

int main() {
  // Testmodus für alle Objekte der Klasse einschalten
  NummeriertesObjekt::testmodus = true;

  NummeriertesObjekt dasNumObjekt_X;  // ... wird erzeugt
  cout << "Die Seriennummer von dasNumObjekt_X ist: " << dasNumObjekt_X.seriennummer()
       << '\n';

  // Anfang eines neuen Blocks
  {
    NummeriertesObjekt dasNumObjekt_Y;  // ... wird erzeugt

    cout << NummeriertesObjekt::anzahl() << " Objekte aktiv\n";

    // *p wird dynamisch erzeugt:
    NummeriertesObjekt* p{new NummeriertesObjekt};

    cout << NummeriertesObjekt::anzahl() << " Objekte aktiv\n";
    delete p;  // *p wird gelöscht

    cout << NummeriertesObjekt::anzahl() << " Objekte aktiv\n";

    // cout << "Fehler: ein  delete zuviel:\n";
    //       delete p;
  }  // Blockende: \tt{dasNumObjekt\_Y} wird gelöscht

  cout << " Kopierkonstruktor:\n";
  NummeriertesObjekt dasNumObjekt_X1 = dasNumObjekt_X;

  cout << "Die Seriennummer von dasNumObjekt_X ist: " << dasNumObjekt_X.seriennummer()
       << '\n';

  cout << "Die Seriennummer von dasNumObjekt_X1 ist: "
       << dasNumObjekt_X1.seriennummer() << '\n';

  // Zuweisung wird wegen Konstanz der serienNr vom Compiler
  // verboten
  //     dasNumObjekt_X1 = dasNumObjekt_X;  // Fehler

}  // \tt{dasNumObjekt\_X} wird gelöscht
