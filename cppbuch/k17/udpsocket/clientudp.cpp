/* cppbuch/k17/udpsocket/clientudp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/asio.hpp>
#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

char formatWahl() {
  char ein;
  do {
    cout << "\nFormatwahl : 1 = Standard, 2 = Langform für Tag und "
            "Monat,\n"
            "3 = nur die Uhrzeit, 4 = Sekunden seit 1.1.1970, 0 = "
            "Programmende: ";
    cin >> ein;
  } while (ein < '0' || ein > '4');
  return ein;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Gebrauch: " << argv[0] << " <IP-Adresse> <port>\n";
    return 1;
  }
  boost::asio::io_service ioService;
  unsigned short port = atoi(argv[2]);
  boost::asio::ip::udp::endpoint server(
      boost::asio::ip::address::from_string(argv[1]), port);
  char auftrag[2] = {0};
  while ((auftrag[0] = formatWahl()) != '0') {
    boost::asio::ip::udp::socket socket(ioService);
    socket.open(boost::asio::ip::udp::v4());
    socket.send_to(boost::asio::buffer(auftrag, 2), server);
    constexpr size_t SZ = 80;
    char buf[SZ + 1];
    ;
    // Antwort lesen
    boost::asio::ip::udp::endpoint hier;
    size_t anzahlBytes =
        socket.receive_from(boost::asio::buffer(buf, SZ), hier);
    buf[anzahlBytes] = '\0';  // Rest für Ausgabe ignorieren
    cout << buf << '\n';
  }
}
