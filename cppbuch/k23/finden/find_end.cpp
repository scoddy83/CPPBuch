/* cppbuch/k23/finden/find_end.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> folge{0, 2, 4, 6, 8, 10, 12, 14, 4, 6, 8};
  vector<int> teilfolge1{4, 6, 8};
  vector<int> teilfolge2{2, 1};

  cout << "Folge  ";
  showContainer(folge);
  // Suche nach Teilfolge 1
  cout << "Teilfolge 1  (";
  showContainer(teilfolge1, ") ");
  auto iter =
      find_end(folge.begin(), folge.end(), teilfolge1.begin(), teilfolge1.end());
  if (iter != folge.end()) {
    cout << "ist Teil der Folge. Das letzte Vorkommen beginnt an "
            "Position "
         << (iter - folge.begin()) << ".\n";
  } else {
    cout << "ist nicht Teil der Folge." << endl;
  }
  // Suche nach Teilfolge 2
  cout << "Teilfolge 2  (";
  showContainer(teilfolge2, ") ");
  iter = find_end(folge.begin(), folge.end(), teilfolge2.begin(), teilfolge2.end());
  if (iter != folge.end()) {
    cout << "ist Teil der Folge. Das letzte Vorkommen beginnt an "
            "Position "
         << (iter - folge.begin()) << ".\n";
  } else {
    cout << "ist nicht Teil der Folge.\n";
  }
}
