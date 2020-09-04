/* cppbuch/k27/sortedmap.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, long> dieKaffeerunde;
  dieKaffeerunde.emplace("Ulrike", 24439404);
  dieKaffeerunde.emplace("Andreas", 635352723);
  dieKaffeerunde.emplace("Manfred", 535353);
  dieKaffeerunde.insert(
      {{"Thomas", 9273539}, {"Uli", 42536347}});  // mit Initialisierungsliste
  // Das zweite Einfügen von Thomas mit einer anderen Nummer wird
  // \emph{nicht} ausgeführt, weil der Schlüssel schon existiert.
  dieKaffeerunde.emplace("Thomas", 1000000);

  // Wegen der auf einer Baumstruktur basierenden Implementierung
  // ist die Ausgabe nach Namen sortiert.
  std::cout << "Ausgabe:\n";
  for (const auto& paar : dieKaffeerunde) {
    std::cout << paar.first << ':'               // Name
         << paar.second << '\n';            // Nummer
  }
  std::cout << "Ausgabe der Nummer nach Eingabe des Namens\nName: ";
  std::string derName;
  std::cin >> derName;
  std::cout << "Suche mit Iterator: ";
  auto iter = dieKaffeerunde.find(derName);  //  \emph{O(log N)}
  if (iter != dieKaffeerunde.end()) {
    std::cout << (*iter).second << '\n';
  } else {
    std::cout << "Nicht gefunden!\n";
  }
  try {
    std::cout << "Suche mit at(): " << dieKaffeerunde.at(derName) << '\n';      // \emph{O(log N)}
  } catch (const std::exception& e) {
    std::cerr << "Nicht gefunden! Exception: " << e.what() << '\n';
  }
}
