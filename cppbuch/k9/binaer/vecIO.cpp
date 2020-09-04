/* cppbuch/k9/binaer/vecIO.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cassert>
#include <fstream>
#include <string>
#include <string_view>
#include <system_error>
#include <vector>

template <typename T>
void writeVector(std::string_view filename, const std::vector<T>& v) {
  std::ofstream dest(filename.data(), std::ios::binary);
  if (!dest) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  dest.write(reinterpret_cast<const char*>(v.data()), v.size()*sizeof(T));
}

template <typename T>
void readVector(std::string_view filename, std::vector<T>& v) {
  std::ifstream source(filename.data(), std::ios::binary);
  if (!source) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  source.read(reinterpret_cast<char*>(v.data()), v.size()*sizeof(T));
}

int main() {
  std::string_view dateiname("binaerdaten.bin");
  std::vector<double> v1 { 1.27, 3.4, 5.678, 9.01234, 100.836};
  writeVector(dateiname, v1);               // v1 schreiben
  decltype(v1) v2(v1.size(), 0.0);          // v2 mit 0 initialisieren
  readVector(dateiname, v2);                // v2 lesen
  assert(v1 == v2);                         // auf Gleichheit prüfen
}
