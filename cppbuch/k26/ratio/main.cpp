/* cppbuch/k26/ratio/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <ratio>

template <typename T> void printRatio() {
  std::cout << T::num << '/' << T::den << '\n';
}

using namespace std;

int main() {
  cout << mega::num << '\n';   // Zähler
  cout << mega::den << '\n';   // Nenner
  cout << micro::num << '\n';  // Zähler
  cout << micro::den << '\n';  // Nenner

  // Arithmetik zur Compilationszeit
  cout << ratio<7, -21>::num << '\n';  // -1
  cout << ratio<7, -21>::den << '\n';  // 3

  cout << ratio_add<mega, micro>::type::num << '\n';  // 1000000000001
  cout << ratio_add<mega, micro>::type::den << '\n';  // 1000000

  cout << ratio_multiply<ratio<7, -21>, ratio<9, -33>>::type::num << '\n';
  cout << ratio_multiply<ratio<7, -21>, ratio<9, -33>>::type::den << '\n';

  cout << "micro = ";
  printRatio<micro>();
  cout << "7/-21 = ";
  printRatio<ratio<7, -21>>();
  cout << "(7/-21)*(9/-33) = ";
  printRatio<ratio_multiply<ratio<7, -21>, ratio<9, -33>>::type>();
  cout << "kilo (=1000)*milli(=1/1000) = ";
  printRatio<ratio_multiply<kilo, milli>::type>();
}
