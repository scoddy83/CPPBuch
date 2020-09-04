/* cppbuch/k17/http/server/AnfrageHandler.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ANFRAGEHANDLER_H
#define ANFRAGEHANDLER_H
#include "HttpResponse.h"
#include <boost/asio.hpp>
#include <cstddef>
#include <cstring>
#include <ctime>
#include <string>

class AnfrageHandler {
public:
  AnfrageHandler(boost::asio::ip::tcp::socket& s, const std::string& a)
      : socket(s), anfrage(a) {
    std::cout << "ANFRAGE=:" << a << '\n';
  }

  void process() {
    // In diesem einfachen Programm wird nur ein Schlüssel-Wert-Paar angenommen.
    // Tatsächlich können es mehr sein.
    auto pos = anfrage.find('=');
    auto key = anfrage.substr(0, pos);
    auto val = anfrage.substr(pos + 1);
    std::cout << "KEY=" << key << " VAL=" << val << '\n';
    if (key == "zeitabfrage" && val == "Datum") {
      time_t jetzt = time(NULL);
      std::string zeitstring(ctime(&jetzt));
      // Header zusammenbauen und senden
      HttpResponse httpResponse(200);
      httpResponse.addToHeader("Content-Type", "text/html");
      std::string msg = "<html><head><title>C++ "
                        "MiniWebServer</title></head><body>"
                        "<img src=\"bild.png\" width=\"80%\"<br><hr><p>";
      msg += zeitstring + "</body></html>";
      httpResponse.addToHeader("Content-Length",
                               std::to_string(msg.length()));
      httpResponse.sendHeader(socket);
      socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
    } else if (key == "begruessung") {
      // Header zusammenbauen und senden
      HttpResponse httpResponse(200);
      httpResponse.addToHeader("Content-Type", "text/html");
      std::string msg =
          "<html><head><title>C++ "
          "MiniWebServer</title></head><body>"
          "<img src=\"bild.png\" width=\"80%\"<br><hr><p><h1>Guten "
          "Tag, ";
      msg += val + "!<h1></body></html>";
      httpResponse.addToHeader("Content-Length",
                               std::to_string(msg.length()));
      httpResponse.sendHeader(socket);
      socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
    } else {
      // Header zusammenbauen und senden
      HttpResponse httpResponse(400);
      httpResponse.addToHeader("Content-Type", "text/html");
      std::string msg = httpResponse.getHTMLMessage("unbekannte Abfrage!");
      httpResponse.addToHeader("Content-Length", std::to_string(msg.length()));
      // Ergebnis als html-Seite senden
      httpResponse.sendHeader(socket);
      // Fehlermeldung als html-Seite senden
      socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
    }
  }

private:
  boost::asio::ip::tcp::socket& socket;
  std::string anfrage;
};
#endif
