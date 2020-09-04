/* cppbuch/k26/type_traits/hasSortUeberladung.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <list>
#include <showContainer.h>
#include <type_traits>
#include <utility>  // \tt{declval}
#include <vector>

template <typename T,
          typename = void>  // \tt{void} = Rückgabetyp von \tt{sort()}
struct has_sort_function : std::false_type {};

/* Funktioniert nur, wenn T einen Default-Konstruktor hat:
template <typename T>
struct has_sort_function<T, decltype(T().sort())>
: std::true_type {};
daher declval einsetzen:
*/

template <typename T>
struct has_sort_function<T, decltype(std::declval<T>().sort())>
    : std::true_type {};

template <typename Container>
void sortiereContainer(Container& container, std::true_type) {
  std::cout << "Container.sort()\n";
  container.sort();
}

template <typename Container>
void sortiereContainer(Container& container, std::false_type) {
  std::cout << "std::sort()\n";
  std::sort(container.begin(), container.end());
}

template <typename Container> void sortiereContainer(Container& container) {
  sortiereContainer(container, has_sort_function<Container>());
}

int main() {
  std::cout << std::boolalpha;
  std::cout << has_sort_function<std::list<int>>::value << '\n';
  std::cout << has_sort_function<std::vector<int>>::value << '\n';

  std::list<int> liste{3, 6, 8, 9, 1, 3, 0};
  std::vector<int> vektor{3, 6, 8, 9, 1, 3, 0};

  sortiereContainer(liste);
  showContainer(liste);
  sortiereContainer(vektor);
  showContainer(vektor);
}
