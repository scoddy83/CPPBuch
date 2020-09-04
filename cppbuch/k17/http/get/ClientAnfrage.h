/* cppbuch/k17/http/get/ClientAnfrage.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef CLIENTANFRAGE_H
#define CLIENTANFRAGE_H
#include <boost/asio.hpp>
#include <cctype>  // isalnum()
#include <cstddef>
#include <cstring>  // strchr()
#include <iostream>
#include <string>

namespace {
std::string urlencode(const std::string& s) {
  std::string ergebnis;
  for (std::size_t i = 0; i < s.length(); ++i) {
    char c = s[i];
    // 'unreserved' Zeichen laut RFC 3986, 2.3, nicht codieren
    if (isalnum(c) || strchr("-._~", c)) {
      ergebnis += c;
    } else {
      ergebnis += '%';
      unsigned int ic = c / 16;
      if (ic < 10)
        ic += 48;  // 0..9
      else
        ic += 55;  // A..F
      ergebnis += static_cast<char>(ic);
      ic = c % 16;
      if (ic < 10)
        ic += 48;  // 0..9
      else
        ic += 55;  // A..F
      ergebnis += static_cast<char>(ic);
    }
  }
  return ergebnis;
}
}

class ClientAnfrage {
public:
  ClientAnfrage(const std::string& wwwseite)
      : socket(ioService), gesendet(false) {
    std::string pfad;
    std::string hostname;
    auto schraegstrichPosition = wwwseite.find("/");
    if (schraegstrichPosition == std::string::npos) {  // nicht vorhanden
      hostname = wwwseite;
      pfad = "/";
    } else {  // extrahieren:
      hostname = wwwseite.substr(0, schraegstrichPosition);
      pfad = wwwseite.substr(schraegstrichPosition);
    }
    // neu
    std::string getQuery("");
    auto queryPosition = pfad.find("?");
    if (queryPosition != std::string::npos) {  // vorhanden
      // Query url-encodieren:
      getQuery = "?" + urlencode(pfad.substr(queryPosition + 1));
      pfad = pfad.substr(0, queryPosition);
    }
    anfrage = "GET ";  // s. RFC 2616 Kap. 5.1.2
    anfrage += pfad + getQuery + " HTTP/1.1\r\nHost: " + hostname +
               "\r\nAccept: */*\r\nConnection: "
               "close\r\n\r\n";  // Extra-Leerzeile

    dateiname = "antwort.html";  // Vorgegebener Dateiname für dieses Programm
    boost::asio::ip::tcp::resolver resolver(ioService);
    boost::asio::ip::tcp::resolver::query query(hostname, "http");
    server = *resolver.resolve(query);
  }

  void send() {
    // Anfrage senden
    socket.connect(server);
    socket.write_some(boost::asio::buffer(anfrage.c_str(), anfrage.length()));
    gesendet = true;
  }
  boost::asio::ip::tcp::socket& getSocket() { return socket; }
  const std::string& getDateiname() const { return dateiname; }
  bool istGesendet() const { return gesendet; }

private:
  boost::asio::io_service ioService;
  boost::asio::ip::tcp::socket socket;
  boost::asio::ip::tcp::endpoint server;
  std::string anfrage;
  std::string dateiname;
  bool gesendet;
};

#endif
