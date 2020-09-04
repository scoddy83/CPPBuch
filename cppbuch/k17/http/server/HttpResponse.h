/* cppbuch/k17/http/server/HttpResponse.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <boost/asio.hpp>
#include <iostream>
#include <string>

class HttpResponse {
public:
  HttpResponse(int st) : status(st) {
    std::string zeile("HTTP/1.1 ");
    zeile += std::to_string(status);
    zeile += std::string(" ") + getStatusText() + "\r\n";
    header = zeile;
  }

  void addToHeader(const std::string& key, const std::string& value) {
    header += key + ": " + value + "\r\n";
  }

  void sendHeader(boost::asio::ip::tcp::socket& socket) {
    header += "\r\n";
    socket.write_some(boost::asio::buffer(header.c_str(), header.length()));
    std::cout << "GESENDETER HEADER:\n" << header;
  }

  auto getHTMLMessage(const std::string& text = "") {
    std::string statusMsg(std::to_string(status) + " " + getStatusText());
    std::string msg("<html><head><title>");
    msg += statusMsg + "</title></head>";
    msg += "<body><h1>" + statusMsg + "</h1>" + text + "</body></html>";
    return msg;
  }

private:
  std::string getStatusText() {
    std::string txt;
    switch (status) {                       // reduzierte Auswahl
    case 200:
      txt = "OK";
      break;
    case 400:
      txt = "Bad Request";
      break;
    case 404:
      txt = "Not Found";
      break;
    case 500:
      txt = "Internal Server Error";
      break;
    case 501:
      txt = "Not Implemented";
      break;
    default:
      txt = "undefined";
    }
    return txt;
  }
  int status;
  std::string header;
};
#endif
