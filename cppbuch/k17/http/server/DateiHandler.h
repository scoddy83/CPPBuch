/* cppbuch/k17/http/server/DateiHandler.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef DATEIHANDLER_H
#define DATEIHANDLER_H
#include "HttpResponse.h"
#include <boost/asio.hpp>
#include <boost/filesystem/operations.hpp>
#include <cstddef>
#include <fstream>
#include <string>

class DateiHandler {
public:
  DateiHandler(boost::asio::ip::tcp::socket& s, const std::string& d)
      : socket(s), dateiname(d) {
  }
  
  void process() {
    std::ifstream quelle(dateiname.c_str(), std::ios::binary);
    if (quelle) {
      sendeDatei(quelle);
    } else {                // Datei nicht vorhanden. Header zusammenbauen und senden:
      HttpResponse httpResponse(404);       // not found
      httpResponse.addToHeader("Content-Type", "text/html");
      std::string msg = httpResponse.getHTMLMessage("Datei nicht gefunden!");
      httpResponse.addToHeader("Content-Length",
                               std::to_string(msg.length()));
      httpResponse.sendHeader(socket);
      // \tt{msg} senden (html-Seite)
      socket.write_some(boost::asio::buffer(msg.c_str(), msg.length()));
    }
  }

private:
  boost::asio::ip::tcp::socket& socket;
  std::string dateiname;

  std::string getContentType() {
    std::string typ("application/octet-stream");   // Vorgabe
    // Datei-Extension ermitteln und in Großschreibung umwandeln
    auto punkt = dateiname.rfind('.');
    if (punkt < std::string::npos) {
      std::string extension = dateiname.substr(punkt + 1);
      for (std::size_t i = 0; i < extension.length(); ++i) {
        extension[i] = toupper(extension[i]);
      }
      // unvollständige Auswahl aus \link{https://wiki.selfhtml.org/wiki/Referenz:MIME-Typen}:
      if (extension == "HTML")
        typ = "text/html";
      else if (extension == "TXT")
        typ = "text/plain; charset=iso-8859-1";
      else if (extension == "JPG")
        typ = "image/jpeg";
      else if (extension == "PNG")
        typ = "image/png";
      else if (extension == "PDF")
        typ = "application/pdf/";
    }
    return typ;
  }

  void sendeDatei(std::ifstream& quelle) {
    boost::filesystem::path p(dateiname);
    auto bufsize = boost::filesystem::file_size(p);
    // Header zusammenbauen und senden
    HttpResponse httpResponse(200);
    httpResponse.addToHeader("Content-Type", getContentType());
    httpResponse.addToHeader("Content-Length", std::to_string(bufsize));
    httpResponse.sendHeader(socket);
    char* const buf = new char[bufsize];
    std::size_t pos = 0;
    while (quelle.get(buf[pos++])) {        // Datei lesen und in buf abspeichern
      ;
    }
    socket.write_some(boost::asio::buffer(buf, bufsize));
    delete[] buf;
  }
};
#endif
