/* cppbuch/k4/thisdemo.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

class ThisDemo {
public:
  int get() const { return wert; }
  // Addition von w auf das Attribut wert
  ThisDemo& add(int w) {                    // Rückgabe per Referenz!
    wert += w;
    return *this;                           // Rückgabe des Objekts
  }
  // Zuweisung von td (Ersatz für =-Operator)
  ThisDemo& assign(const ThisDemo& td) {    // Rückgabe per Referenz!
    wert = td.wert;
    return *this;
  }
private:
  int wert = 0;
};

int main() {
  ThisDemo td;
  td.add(1);                                // Rückgabewert wird ignoriert
  std::cout << td.get() << '\n';            // 1
  td.add(2).add(3);                         // *** Verkettung von Aufrufen
  std::cout << td.get() << '\n';            // 6
  ThisDemo a, b;
  a.assign(b.assign(td));                   // entspricht a = b = td;
  std::cout << a.get() << '\n';             // 6
}
