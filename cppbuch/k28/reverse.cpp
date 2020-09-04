/* cppbuch/k28/reverse.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "reverse_iterator:\n";
  auto revIter = v.rbegin();
  // Alternativen:
  // \tt{reverse\_iterator<vector<int>::iterator>
  // revIter(v.rbegin());}
  // \tt{vector<int>::reverse\_iterator revIter(v.rbegin());}
  // Zahlen verdoppelt in umgekehrter Folge ausgeben
  while (revIter != v.rend()) {
    *revIter *= 2;  // Wert über den Iterator ändern
    cout << *revIter++ << ' ';
  }
  cout << '\n';
  // Falls Werte \emph{nicht} geändert werden sollen, kann der von
  // der
  // Klasse
  // \tt{vector} bereitgestellte Typ \tt{const\_reverse\_iterator}
  // verwendet werden. Eine eigene Klasse
  // \tt{const\_reverse\_iterator} gibt es nicht  \cite{ISOC++}.
  cout << "const_reverse_iterator:\n";
  auto constRevIter = v.crbegin();  // \tt{auto} =
  // \tt{vector<int>::const\_reverse\_iterator}
  while (constRevIter != v.crend()) {
    cout << *constRevIter++ << ' ';
  }
  cout << '\n';
}
