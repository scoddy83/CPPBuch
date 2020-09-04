/* cppbuch/k23/sortieren/partition.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <showContainer.h>
#include <vector>

using namespace std;
bool istNegativ(int x) { return x < 0; }

int main() {
  vector<int> v(12);
  iota(v.begin(), v.end(), -6);
  shuffle(v.begin(), v.end(), mt19937());  // verwürfeln

  vector<int> unstable = v;
  vector<int> stable = v;

  cout << "In negative und positive Elemente zerlegen\n";
  cout << "Sequenz vor der Zerlegung :";
  showContainer(v);  // -2 4 5 2 -6 -1 -4 -5 0 3 -3 1

  cout << "stabile Partitionierung   :";
  stable_partition(stable.begin(), stable.end(), istNegativ);
  showContainer(stable);  // -2 -6 -1 -4 -5 -3 4 5 2 0 3 1

  cout << "unstabile Partitionierung :";
  partition(unstable.begin(), unstable.end(), istNegativ);
  // Die Elemente innerhalb einer Partition sind nicht mehr in ihrer
  // ursprünglichen Reihenfolge:
  showContainer(unstable);  // -2 -3 -5 -4 -6 -1 2 5 0 3 4 1

  if (is_partitioned(unstable.begin(), unstable.end(), istNegativ)) {
    cout << "Folge ist partioniert. Der erste Wert des zweiten "
            "Teils "
            "ist "
         << *partition_point(unstable.begin(), unstable.end(), istNegativ)
         << '\n';
  }

  vector<int> negativeZahlen(v.size());
  vector<int> positiveZahlen(v.size());
  auto iteratorPaar = partition_copy(v.begin(), v.end(), negativeZahlen.begin(),
                                     positiveZahlen.begin(), istNegativ);
  cout << "\nPartition 1: ";
  for (auto iter = negativeZahlen.begin(); iter != iteratorPaar.first; ++iter) {
    cout << *iter << ' ';
  }
  cout << '\n';
  cout << "Partition 2: ";
  for (auto iter = positiveZahlen.begin(); iter != iteratorPaar.second;
       ++iter) {
    cout << *iter << ' ';
  }
  cout << '\n';
}
