/* cppbuch/k26/tuple/tuple.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main() {
  using tupeltyp = tuple<string, string, int>;  // Abkürzung
  tupeltyp tupel("Donald", "Duck", 17);
  // \tt{get<>()} gibt Referenzen zurück
  cout << "Zugriff mit get<0> und get<1>: " << get<0>(tupel) << " "
       << get<1>(tupel);       // Donald Duck
  get<0>(tupel) = "Dagobert";  // Änderung
  cout << "\ngeändertes Element 0: " << get<0>(tupel) << " "
       << get<1>(tupel);  // Dagobert Duck
  // Abfrage der Anzahl der Elemente mit tuple_size<T>::value
  cout << "\ntupeltyp hat " << tuple_size<tupeltyp>::value << " Elemente\n";
  cout << "Zugriff mit get<int> : " << get<int>(tupel) << '\n';  // 17
  // Zugriff mit get<string> ist nicht eindeutig.

  // Tupel aneinanderhängen:
  tuple<double, int> dt = make_tuple(3.1415926, 42);
  auto neu = tuple_cat(tupel, dt);
  cout << "letztes Element des verlängerten Tupels: " << get<4>(neu) << '\n';
  // Variablen aus Tupel extrahieren
  auto [a, b, c] = tupel;
  cout << "extrahierte Variablen: " << a << ' ' << b << ' ' << c << '\n' ;
}
