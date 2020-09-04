/* cppbuch/k27/emplace.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <vector>

class A {
public:
  A(int i, int j) : i_(i), j_(j) {}

private:
  int i_;
  int j_;
};

int main() {
  std::vector<A> v;
  A a1(1, 2);
  std::cout << "v.push_back()\n";
  // v.push_back(3, 4);    nicht erlaubt!
  v.push_back({3, 4});  // Initialisierunsliste: erlaubt (entspricht
                        // \tt{A{3,4}})
  v.push_back(a1);      // echte Kopie (default-Kopierkonstruktor)
  std::cout << "v.emplace(v.end(), 3, 4)\n";
  v.emplace(v.end(), 3, 4);
}
