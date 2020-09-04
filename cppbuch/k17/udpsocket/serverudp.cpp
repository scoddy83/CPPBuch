/* cppbuch/k17/udpsocket/serverudp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/asio.hpp>
#include <cstddef>
#include <ctime>
#include <iostream>
using boost::asio::ip::udp;
using namespace std;

const char* getZeitstring(const char* format) {
  constexpr size_t MAX = 80;
  static char buf[MAX] = {0};
  time_t jetzt = time(NULL);
  // Sonderbehandlung für %s, das nicht jeder Compiler kennt
  if (format[1] == 's') {
    size_t pos = MAX;
    while (jetzt > 0) {  // Zahl > 0 in C-String umwandeln
      buf[--pos] = jetzt % 10 + '0';
      jetzt /= 10;
    }
    return (buf + pos);
  } else {  // Umwandlung je nach Format-String mit strftime
    tm* z = localtime(&jetzt);
    strftime(buf, MAX, format, z);
    return buf;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Gebrauch: " << argv[0] << " <port>\n";
    return 1;
  }
  boost::asio::io_service ioService;
  unsigned short port = atoi(argv[1]);
  udp::socket socket(ioService, udp::endpoint(udp::v4(), port));
  while (true) {  // Abbruch mit Strg+C
    cout << "lauschen  an Port " << port << " ... (Abbruch mit Strg+C)\n";
    boost::asio::ip::udp::endpoint entfernt;
    char daten[256] = {0};
    socket.receive_from(boost::asio::buffer(daten), entfernt);
    const char* format = "%c";
    // nur erstes Byte ist relevant
    switch (daten[0]) {
    case '1':
      format = "%c";
      break;
    case '2':
      format = "%A, %d. %B %Y, %X Uhr";
      break;
    case '3':
      format = "%X";
      break;
    case '4':
      format = "%s";
      break;
    }
    const char* zeitstring = getZeitstring(format);
    socket.send_to(boost::asio::buffer(zeitstring, strlen(zeitstring) + 1),
                   entfernt);
  }
}
