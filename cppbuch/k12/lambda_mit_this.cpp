/* cppbuch/k12/lambda_mit_this.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <initializer_list>
#include <iostream>
#include <vector>

class LambdaTest {
public:
  LambdaTest(std::initializer_list<int> il) : v(il) {}
  int summe(int ergebnis) {
    auto func = [&, *this]() {              // Definition der Lambda-Funktion
      for (auto el : v) {                   // Zugriff auf Attribut v
        ergebnis += el;
      }
      return ergebnis;
    };
    return func();  // Aufruf
  }
private:
  std::vector<int> v;
};

int main() {
  LambdaTest test{-1, 0, 1, 2, 3, 4};
  std::cout << test.summe(10) << '\n';      // Offset 10
}
