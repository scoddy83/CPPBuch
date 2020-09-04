/* cppbuch/k17/host/ihost.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
/*
HINWEISE für die Benutzung unter Windows:

1. Bei der Compilation in einem Eingabeaufforderungs-
Fenster die Optionen -lwsock32 und -lws2_32 setzen, z.B.
g++ ihost.cpp -ihost.exe -lwsock32 -lws2_32
(wird bei Aufruf von make automatisch erledigt)
2. Bei der Compilation mit einer IDE im Fenster Werkzeuge->
Compiler-Optionen o.ä. ein Häkchen bei
"Diese Befehle zur Linker-Kommandozeile hinzufügen"
machen und im Feld darunter -lwsock32 -lws2_32 eintragen.
*/

#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#endif
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "Gebrauch: ihost Rechnername\n";
  } else {
#ifdef WIN32
    WSADATA wsaData = {0};
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
      cerr << "WSAStartup() gescheitert!\n";
      return 1;
    }
#endif
    struct addrinfo* result;
    int error = getaddrinfo(argv[1], NULL, NULL, &result);
    if (error == 0) {
      struct addrinfo* item = result;
      while (item) {
        char hostname[NI_MAXHOST] = "";
        // Namen extrahieren, wenn möglich
        error = getnameinfo(item->ai_addr, item->ai_addrlen, hostname,
                            NI_MAXHOST, NULL, 0, 0);
        if (error == 0) {
          cout << hostname;
        }
        // IP-Adresse als String extrahieren, wenn möglich
        error |= getnameinfo(item->ai_addr, item->ai_addrlen, hostname,
                             NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
        if (error == 0) {
          cerr << "   " << hostname << '\n';
        } else {
          cerr << argv[1] << " : Fehler in getnameinfo().\n";
        }
        item = item->ai_next;
      }
      freeaddrinfo(result);
    } else {
      cout << argv[1] << " kann nicht ermittelt werden.\n";
    }
  }
#ifdef WIN32
  WSACleanup();
#endif
}
