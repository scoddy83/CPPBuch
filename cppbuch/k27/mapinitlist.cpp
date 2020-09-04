/* cppbuch/k27/mapinitlist.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <map>
#include <string>

enum class Sortiermodus { aufsteigend, absteigend };

class Compare {
public:
  Compare(Sortiermodus m = Sortiermodus::absteigend) : sortiermodus{m} {}
  template <typename T> 
  bool operator()(const T& t1, const T& t2) const {
    return sortiermodus == Sortiermodus::aufsteigend ? t1 < t2 : t2 < t1;
  }

private:
  Sortiermodus sortiermodus;
};

int main() {
  // ohne Compare-Klasse, d.h. \tt{less<string>}
  std::map<std::string, int> m0{{"Lena", 3}, {"Hanna", 9}};
  for (const auto& paar : m0) {
    std::cout << paar.first << "   " << paar.second << '\n';
  }

  // mit Compare-Klasse, aber ohne Compare-Objekt, d.h. \tt{Sortiermodus::absteigend}
  // (im Konstruktor voreingestellt)
  std::map<std::string, int, Compare> m1{{"Lena", 3}, {"Hanna", 9}};
  for (const auto& paar : m1) {
    std::cout << paar.first << "   " << paar.second << '\n';
  }

  // mit Compare-Klasse und Compare-Objekt mit Argument
  std::map<std::string, int, Compare> m2({{"Lena", 3}, {"Hanna", 9}},
                                         Compare(Sortiermodus::aufsteigend));
  for (const auto& paar : m2) {
    std::cout << paar.first << "   " << paar.second << '\n';
  }
}
