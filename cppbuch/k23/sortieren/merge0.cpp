/* cppbuch/k23/sortieren/merge0.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <vector>
using namespace std;

int main() {
  vector<int> folge1{0, 1, 2, 3, 4, 5};
  showContainer(folge1);
  vector<int> folge2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  showContainer(folge2);
  vector<int> result(folge1.size() + folge2.size());  // Platz schaffen
  // Verschmelzen zweier Folgen \tt{v1} und \tt{v2}, Ablage in
  // \tt{result}
  merge(folge1.begin(), folge1.end(), folge2.begin(), folge2.end(),
        result.begin());
  showContainer(result);
}
