/* cppbuch/k15/async.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>                          // \tt{iota()}
#include <future>

long long summe(const std::vector<int>& v, std::size_t von, std::size_t bis) {
  long long ergebnis = 0;
  for(std::size_t i = von; i < bis; ++i) {
    ergebnis += v[i];
  }
  return ergebnis;
}

long long parallelSumme(const std::vector<int>& v) {
  std::size_t anzahlTasks = 
      std::thread::hardware_concurrency();  // Anzahl der Prozessorkerne
  std::vector<std::future<long long> > tasks; 
  // Berechnung der \tt{laenge} eines einzelnen Bereichs:
  std::size_t laenge = 1000 +  v.size()/anzahlTasks;   // Minimum 1000
  std::size_t start = 0;
  while(start < v.size()) {
    std::size_t ende = start + laenge;
    if(ende > v.size()) {
      ende = v.size();
    }
    // Task für Teilbereich [start, ende) starten und \tt{future}-Objekt speichern:
    tasks.push_back(std::async(std::launch::async, summe, v, start, ende));
    // nur zur Dokumentation der Aufteilung:
    std::cout << "Bereich " << tasks.size() << ": " << start << '-' 
              << ende-1 << '\n';   // -1, weil \tt{v[ende]} nicht mehr addiert wird
    start += laenge;
  }
  // Zwischenergebnisse einsammeln:
  long long ergebnis = 0;
  for(std::future<long long>& f : tasks) {  // oder \tt{ for(auto\& f : tasks)}
    ergebnis += f.get();
  }
  return ergebnis;
}

int main() {
  std::vector<int> v(1'000'000);
  std::iota(v.begin(), v.end(), 1);       // \tt{v} mit 1, 2, 3 ... belegen
  auto erg =  parallelSumme(v);
  std::cout << "Die Summe ist " << erg << ".\n";
  long long n = v.size();
  assert(erg == n*(1+n)/2);                 // Überprüfung mit Gaußformel
}
