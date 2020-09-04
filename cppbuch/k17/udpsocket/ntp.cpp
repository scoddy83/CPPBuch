/* cppbuch/k17/udpsocket/ntp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/asio.hpp>
#include <ctime>
#include <iostream>
using boost::asio::ip::udp;

int main() {
  boost::asio::io_service ioService;
  udp::socket socket(ioService);
  static_assert(sizeof(unsigned int) == 4, "unsigned int muss 4 Bytes haben");
  unsigned int buf[12] = {0};
  constexpr unsigned int BUFSIZE = sizeof(buf);

  buf[0] = htonl((3 << 27) | (3 << 24));  // s. RFC 5905
  // http://www.ietf.org/rfc/rfc5905.txt
  udp::resolver resolver(ioService);
  // udp::resolver::query query(udp::v4(), "ptbtime2.ptb.de",
  // "123");
  udp::resolver::query query(udp::v4(), "europe.pool.ntp.org", "123");
  udp::endpoint zeitserver = *resolver.resolve(query);
  socket.open(boost::asio::ip::udp::v4());
  socket.send_to(boost::asio::buffer(buf, BUFSIZE), zeitserver);

  boost::asio::ip::udp::endpoint hier;
  socket.receive_from(boost::asio::buffer(buf, BUFSIZE), hier);
  time_t secs = ntohl(buf[8]) - 2208988800u;
  tm* z = localtime(&secs);
  double secfrac = static_cast<double>(ntohl(buf[9])) / 4294967296.0;
  std::cout << z->tm_mday << '.' << z->tm_mon + 1 << '.' << z->tm_year + 1900
            << "   " << z->tm_hour << ':' << z->tm_min << ':'
            << secfrac + z->tm_sec << '\n';
}
