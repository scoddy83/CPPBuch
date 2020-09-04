/* cppbuch/k23/folgen/is_permutation.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <vector>

void permutationsanzeige(const std::vector<int>& v1,
                         const std::vector<int>& v2) {
  std::cout << "Die Zahlen ";
  showContainer(v2, " ", " ");
  if (is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end())) {
    std::cout << "sind eine Permutation von ";
  } else {
    std::cout << "sind keine Permutation von ";
  }
  showContainer(v1);
}

using namespace std;

int main() {
  vector<int> v1{0, 1, 2, 3};
  vector<int> v2{1, 2, 3, 0};
  vector<int> v3{1, 0, 2, 3, 4};
  vector<int> v4{1, 0, 2, 3, 5};

  permutationsanzeige(v1, v2);
  permutationsanzeige(v2, v1);
  permutationsanzeige(v3, v1);  // ungleiche Längen
  permutationsanzeige(v1, v3);  // ungleiche Längen
  permutationsanzeige(v3, v4);
}
