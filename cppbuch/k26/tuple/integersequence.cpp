/* cppbuch/k26/tuple/integersequence.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// wie indexsequence.cpp, aber mit integer_sequence statt
// index_sequence
#include <iostream>
#include <tuple>
#include <utility>

// Abbruch der Rekursion bei leerer Folge
template <typename Tuple>
auto berechnesumme(const Tuple& nichtbenutzt,
                   std::integer_sequence<std::size_t>) {
  return 0;
}

template <typename Tuple, size_t I, size_t... Zahlenfolge>
auto berechnesumme(const Tuple& t,
                   std::integer_sequence<std::size_t, I, Zahlenfolge...>) {
  return std::get<I>(t) +
         berechnesumme(t,
                       std::integer_sequence<std::size_t, Zahlenfolge...>());
}

template <typename... T> auto tupelsumme(const std::tuple<T...>& t) {
  using indexfolge = std::make_integer_sequence<std::size_t, sizeof...(T)>;
  return berechnesumme(t, indexfolge());
}

int main() {
  auto tupel = std::make_tuple(3.1, 4.2, -17.0);
  std::cout << tupelsumme(tupel) << '\n';
}
