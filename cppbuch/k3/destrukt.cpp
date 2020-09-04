/* cppbuch/k3/destrukt.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>

class Beispiel {
public:
  Beispiel(int i = 0)  // Konstruktor
      : zahl{i} {
    std::cout << "Objekt " << zahl << " wird erzeugt.\n";
  }

  ~Beispiel() {  // Destruktor
    std::cout << "Objekt " << zahl << " wird zerstört.\n";
  }

private:
  int zahl;
};

// globale Variable, durch Vorgabewert mit 0 initialisiert
Beispiel ein_globales_Beispiel;

int main() {
  std::cout << "main wird begonnen\n";
  Beispiel einBeispiel(1);
  {
    std::cout << "    neuer Block\n    ";
    Beispiel einBeispiel(2);
    std::cout << "    Block wird verlassen\n    ";
  }
  std::cout << "main wird verlassen\n";
}
