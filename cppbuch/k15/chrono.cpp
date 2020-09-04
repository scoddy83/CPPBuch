/* cppbuch/k15/chrono.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

int main() {
  seconds fastEinTag = hours(23) + minutes(59) + seconds(59);
  // alternativ: seconds fastEinTag = 23h + 59min + 59s;
  cout << "23h 59m 59s sind " << fastEinTag.count() << " Sekunden\n";

  // Zeitmessung
  auto anfang = system_clock::now();
  // Rechnung, um Zeit vergehen zu lassen ....
  cout << "Rechnung läuft ..." << endl;
  double summe{0.0};
  for (long i = 0; i < 20'0000'000L; ++i) {
    summe += i / 1'000'000.0;
  }
  // Ausgabe, damit die Schleife nicht wegoptimiert wird
  cout << "Ergebnis = " << summe << '\n';
  // Rechnung beendet, Dauer ausgeben:
  nanoseconds ns = system_clock::now() - anfang;
  cout << "Dauer [ns] = " << ns.count()
       << "\nDauer [us] = " << duration_cast<microseconds>(ns).count()
       << "\nDauer [ms] = " << duration_cast<milliseconds>(ns).count()
       << "\nDauer [s]  = " << duration_cast<seconds>(ns).count() << '\n';

  cout << "1500 ms warten ..." << endl;
  this_thread::sleep_for(milliseconds(1500));

  cout << "noch einmal warten bis (jetzt + 5 Sekunden) ..." << endl;
  auto dann = system_clock::now() + seconds(5);
  this_thread::sleep_until(dann);
}
