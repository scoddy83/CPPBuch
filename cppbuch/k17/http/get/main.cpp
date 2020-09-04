/* cppbuch/k17/http/get/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "AntwortAuswerter.h"
#include "ClientAnfrage.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Gebrauch: " << argv[0]
         << " WWW-Adresse (OHNE http:// eingeben)\n";
    return 1;
  }
  ClientAnfrage clientAnfrage(argv[1]);
  AntwortAuswerter antwortAuswerter(clientAnfrage);
  clientAnfrage.send();
  antwortAuswerter.receive();
  cout << "Header:\n" << antwortAuswerter.getHeader() << '\n';
  cout << "Status (200=OK): " << antwortAuswerter.getStatus() << "  ";
  string stat;
  switch (antwortAuswerter.getStatus() / 100) {
  case 2:
    stat = "erfolgreich";
    break;
  case 3:
    stat = "Umleitung u.a.";
    break;
  case 4:
    stat = "Clienten-Fehler";
    break;
  case 5:
    stat = "Server-Fehler";
    break;
  default:
    stat = "darf nicht vorkommen";
    break;
  }
  cout << stat << '\n';
  if (antwortAuswerter.getStatus() >= 300) {
    cout << "siehe Datei " << clientAnfrage.getDateiname() << '\n';
  }
  if (antwortAuswerter.getHeader().find("chunked") != string::npos) {
    cout << "Transfer-Encoding: chunked nicht implementiert\n"
            "nur 1 Chunk gelesen, siehe "
         << clientAnfrage.getDateiname() << '\n';
  }
}
