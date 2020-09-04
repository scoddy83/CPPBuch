/* cppbuch/k17/http/server/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Server.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Gebrauch: " << argv[0] << " <port>\n";
    return 1;
  }
  unsigned short port = atoi(argv[1]);
  Server server(port, "web");
  server.run();
}
