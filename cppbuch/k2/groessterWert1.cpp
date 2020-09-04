/* cppbuch/k2/groessterWert1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstdlib>  // \tt{abs(int)}
#include <iostream>
#include <string>
#include <vector>


// Die folgende Funktion würde auch mit einer Parameterliste \tt{(T a, T b)}
// arbeiten, d.h. einer  Kopie per Wert. Da \tt{T} aber für einen beliebigen 
// Datentyp steht, wird eine Referenz bevorzugt,
// um Kopien von möglicherweise sehr großen Objekten zu vermeiden.
template <typename T> 
bool kleiner(const T& a, const T& b) {  // Vergleich
  return a < b;  // zu \tt{<} siehe auch Text am  Abschnittsende
}

template<>
bool kleiner<int>(const int& a, const int& b) {
   //  Das \tt{<int>} in \tt{kleiner<int>} darf weggelassen werden (Typdeduktion).
   return abs(a) < abs(b);                  // Vergleich nach dem Absolutbetrag!
}

template <typename T> 
void drucke(const std::vector<T>& V) {
  for (const T& wert : V) {
    std::cout << wert << " ";
  }
  std::cout << '\n';
}

template <typename T>
T groessterWert(const std::vector<T>& vek) {
  T max = vek[0];                           // \tt{vek} darf nicht leer sein 
  for(const auto& element : vek) {
    if(kleiner(max, element)) {
      max = element;
    }
  }
  return max;
}

int main() {
  std::vector<int> iV{-100, 22, -3, 44, 6, -9, -2, 1, 8, 9};
  // In den folgenden beiden Anweisungen werden vom Compiler, gesteuert durch den
  //  Datentyp \tt{vector<int>} des Parameters \tt{iV}, aus den obigen
  //  Templates die Funktionen \tt{groessterWert(const vector<int>\&)} und 
  // \tt{drucke(const vector<int>\&)} erzeugt, ebenso wie die implizit aufgerufenen 
  // Funktion \tt{kleiner(const int\&, const int\&)}. 
  std::cout << "Der größte Absolutbetrag von ";
  drucke(iV);
  std::cout << "ist " << abs(groessterWert(iV)) << '\n';
  std::vector<double> dV{1.09, 2.2, 79.6, -1.9, 2.7, 100.9, 18.8, 99.9};
  // Generierung der überladenen Funktionen \tt{groessterWert(const vector<double>\&)
  // und \tt{drucke(const vector<double>\&)} (und der aufgerufenen Funk\-tio\-n
  // \tt{kleiner(const double\&, const double\&)}):
  std::cout << "Der größte Wert von ";
  drucke(dV);
  std::cout << "ist " << groessterWert(dV) << '\n';
  // Das funktioniert auch für Strings:
  std::vector<std::string> sV {"alpha", "beta", "zebra", "eins", "elf"};
  std::cout << "Der größte Wert von ";
  drucke(sV);
  std::cout << "ist " << groessterWert(sV) << '\n';
}  // Ende von \tt{main()}
