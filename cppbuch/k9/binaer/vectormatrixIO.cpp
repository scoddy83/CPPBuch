/* cppbuch/k9/binaer/vectormatrixIO.cpp
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
using Matrix = std::vector<std::vector<T>>; // zur Abkürzung

template <typename T>
void writeVectorMatrix(std::string_view filename, const Matrix<T>& matrix) {
  std::ofstream dest(filename.data(), std::ios::binary);
  if (!dest) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  for(const auto& zeile : matrix) {         // zeilenweise schreiben
    dest.write(reinterpret_cast<const char*>(zeile.data()), zeile.size()*sizeof(T));
  }
}

template <typename T>
void readVectorMatrix(std::string_view filename, Matrix<T>& matrix) {
  std::ifstream source(filename.data(), std::ios::binary);
  if (!source) {
    throw std::ios::failure(__FILE__ ":" + std::to_string(__LINE__));
  }
  for(auto& zeile : matrix) {               // zeilenweise lesen
    source.read(reinterpret_cast<char*>(zeile.data()), zeile.size()*sizeof(T));
  }
}

int main() {
  std::string_view dateiname("binaerdatenMatrix.bin");
  Matrix<double> mat1 =  {{  {{1.1, 2.2, 3.3}},  {{4.4, 5.5, 6.6}} }};
  writeVectorMatrix(dateiname, mat1);       // mat1 schreiben
  // neue Matrix mat2 in der richtigen Größe anlegen:
  Matrix<double> mat2(mat1.size(), std::vector<double>(mat1[0].size()));  // enthält 0.0
  readVectorMatrix(dateiname, mat2);        // mat2 lesen
  assert(mat1 == mat2);                     // auf Gleichheit prüfen
}
