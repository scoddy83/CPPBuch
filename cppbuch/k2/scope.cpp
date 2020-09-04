/* cppbuch/k2/scope.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;
int a{1};  // überall bekannt, also global

void f1() {  // Deklaration \emph{und} Definition
  int c{3};  // nur in \tt{f1()} bekannt, also lokal
  cout << "f1: c= " << c << '\n';
  cout << "f1: globales a= " << a << '\n';
}

int main() {
  cout << "main: globales a= " << a << '\n';

  // cout << "f1: c= " << c; // ist nicht compilierfähig,
  // weil \tt{c} in \tt{main()} unbekannt ist.
  f1();  // Aufruf von \tt{f1()}
}
