/* cppbuch/k17/tcpsocket/zeit/zeitclient.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/asio.hpp>
#include <cstddef>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Gebrauch: " << argv[0] << " <IP-Adresse> <port>\n";
    return 1;
  }
  boost::asio::io_service ioService;
  unsigned short port = atoi(argv[2]);
  boost::asio::ip::tcp::endpoint server(
      boost::asio::ip::address::from_string(argv[1]), port);
  boost::asio::ip::tcp::socket socket(ioService);
  socket.connect(server);
  cout << "Lokaler Endpunkt:  " << socket.local_endpoint();
  cout << "\nVerbindung mit " << socket.remote_endpoint() << " hergestellt."
       << endl;
  constexpr size_t SZ = 80;
  char buf[SZ + 1];
  // Es werden maximal SZ Bytes gelesen:
  size_t anzahlBytes = socket.read_some(boost::asio::buffer(buf, SZ));
  buf[anzahlBytes] = '\0';  // Rest für Ausgabe ignorieren
  cout << buf << '\n';
}
