/* cppbuch/k9/binaer/arrayIO.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <array>
#include <cassert>
#include <fstream>
#include <string>
#include <string_view>
#include <system_error>

template <typename T, auto N>
void writeArray(std::string_view filename, const std::array<T, N>& a) {
  std::ofstream dest(filename.data(), std::ios::binary);
  if (!dest) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  dest.write(reinterpret_cast<const char*>(a.data()), a.size()*sizeof(T));
}

template <typename T, auto N>
void readArray(std::string_view filename, std::array<T, N>& a) {
  std::ifstream source(filename.data(), std::ios::binary);
  if (!source) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  source.read(reinterpret_cast<char*>(a.data()), a.size()*sizeof(T));
}

int main() {
  std::string_view dateiname("binaerdaten.bin");
  std::array<double, 5> a1 { 1.2, 3.4, 5.678, 9.01234, 100.83653};
  writeArray(dateiname, a1);                // a1 schreiben
  decltype(a1) a2 {};                       // enthält 0.0
  readArray(dateiname, a2);                 // a2 lesen
  assert(a1 == a2);                         // auf Gleichheit prüfen

  // funktioniert auch für Matrizen, z.B.
  const std::string_view dateiname1("binaerdatenMatrix.bin");
  std::array<std::array<double, 3>, 2> am1 =    // 2-dimensionale Matrix
     {{  {{1.1, 2.2, 3.3}},  {{4.4, 5.5, 6.6}} }};
  writeArray(dateiname1, am1);              // am1 schreiben
  decltype(am1) am2 {};                     // enthält 0.0
  readArray(dateiname1, am2);               // am2 lesen
  assert(am1 == am2);                       // auf Gleichheit prüfen
}
