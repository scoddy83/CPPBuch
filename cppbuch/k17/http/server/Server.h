/* cppbuch/k17/http/server/Server.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SERVER_H
#define SERVER_H
#include "HttpConnection.h"

class Server {
public:
  Server(int p, const std::string& v)
    : port(p), verzeichnis(v),
      acceptor(ioService, boost::asio::ip::tcp::endpoint(
                          boost::asio::ip::tcp::v4(), port)) {}
  void run() {
    while (true) {                          // Abbruch mit Strg+C
      std::cout << "lauschen  an Port " << port << " ... (Abbruch mit Strg+C)"
                << std::endl;
      HttpConnection conn(acceptor, verzeichnis);
      conn.accept();                        // warten auf eingehende Verbindung
      conn();                               // bearbeiten
    }
  }

private:
  int port;
  const std::string verzeichnis;
  boost::asio::io_service ioService;
  boost::asio::ip::tcp::acceptor acceptor;
};
#endif
