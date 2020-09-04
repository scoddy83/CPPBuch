/* cppbuch/k12/genericlambda.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

auto plusOp = [](auto a, auto b) {  // generische Lambda-Funktion
  return a + b;
};

using std::cout;
using std::string;

int main() {
  // Benutzung der generischen Lambda-Funktion
  cout << plusOp(42, 43) << '\n';
  string s1{"Guten "};
  string s2{"Tag!"};
  cout << plusOp(s1, s2) << '\n';

  auto f = plusOp;
  cout << f(42, 43) << '\n';
}
