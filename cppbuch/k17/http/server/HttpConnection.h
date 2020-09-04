/* cppbuch/k17/http/server/HttpConnection.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H
#include "AnfrageHandler.h"
#include "DateiHandler.h"
#include <boost/asio.hpp>
#include <cstddef>
#include <iostream>
#include <string>

class HttpConnection {
public:
  HttpConnection(boost::asio::ip::tcp::acceptor& a, const std::string& v)
      : acceptor(a), socket(a.get_io_service()), verzeichnis(v) {}

  void accept() { 
    acceptor.accept(socket); 
  }

  void operator()() {
    constexpr std::size_t BUFSIZE = 1024;
    char daten[BUFSIZE + 1] = {0};
    // Anfrage lesen
    auto anzahl = socket.read_some(boost::asio::buffer(daten, BUFSIZE));
    daten[anzahl] = '\0';
    std::cout << daten << '\n';
    std::string header(daten);
    auto leerzeichen = header.find(' ');
    // Fehlermeldung bei falschem Protokoll
    if (header.substr(0, leerzeichen) != "GET") {
      HttpResponse httpResponse(400);
      httpResponse.addToHeader("Content-Type", "text/html");
      std::string msg =
          httpResponse.getHTMLMessage("Protokoll nicht implementiert!");
      httpResponse.addToHeader("Content-Length",
                               std::to_string(msg.length()));
      httpResponse.sendHeader(socket);
      socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
      return;                               // Abbruch!
    }
    auto leerzeichen2 = header.find(' ', leerzeichen + 1);
    auto pfad = header.substr(leerzeichen + 1, leerzeichen2 - leerzeichen - 1);
    // Gibt es eine Anfrage oder ist eine Datei gewünscht?
    auto qpos = pfad.find('?');
    if (qpos != std::string::npos) {        // Anfrage
      AnfrageHandler ah(socket, pfad.substr(qpos + 1));
      ah.process();
    } else {                                // Datei
      auto dateiname = verzeichnis + pfad;
      if (pfad == "/" || pfad == "/favicon.ico") {
        dateiname = verzeichnis + "/index.html";
      }
      DateiHandler dh(socket, dateiname);
      dh.process();
    }
    socket.close();
  }

private:
  boost::asio::ip::tcp::acceptor& acceptor;
  boost::asio::ip::tcp::socket socket;
  std::string verzeichnis;
};
#endif
