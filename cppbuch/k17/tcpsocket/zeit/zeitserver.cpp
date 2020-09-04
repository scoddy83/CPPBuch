/* cppbuch/k17/tcpsocket/zeit/zeitserver.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/asio.hpp>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Gebrauch: " << argv[0] << " <port>" << endl;
    return 1;
  }
  boost::asio::io_service ioService;
  unsigned short port = atoi(argv[1]);
  tcp::acceptor acceptor(ioService, tcp::endpoint(tcp::v4(), port));
  while (true) {  //    Abbruch mit Strg+C
    tcp::socket socket(ioService);
    cout << "Lauschen  an Port " << port << " ... (Abbruch mit Strg+C)"
         << endl;
    acceptor.accept(socket);
    cout << "Lokaler Endpunkt:  " << socket.local_endpoint() << '\n';
    cout << "Verbindung mit " << socket.remote_endpoint() << " hergestellt."
         << endl;
    time_t jetzt = time(NULL);
    const char* zeitstring = ctime(&jetzt);
    socket.write_some(
        boost::asio::buffer(zeitstring, strlen(zeitstring) + 1));
  }
}
