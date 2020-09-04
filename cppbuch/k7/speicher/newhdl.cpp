/* cppbuch/k7/speicher/newhdl.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <new>  // \tt{set\_new\_handler()} und \tt{bad\_alloc}

void speicherfehler() {   
  std::cerr << "Memory erschöpft! Eigener new_handler aufgerufen!\n";
  // andere mögliche Operationen weggelassen
  // Annahme: Beschaffung weiteren Speichers ist gescheitert.
  // Daher: Exception weiterreichen.
  throw std::bad_alloc();
}

int main() {
  std::set_new_handler(speicherfehler);

  std::cout << "Anzahl zu reservierender Gigabytes: ";
  std::size_t anzahl;
  std::cin >> anzahl;
  try {
    char* speicher = new char[anzahl * 1'000'000'000L];
    std::cout << anzahl << " GB problemlos beschafft.\n";
    delete [] speicher;
  }
  catch(const std::bad_alloc& exc) {
    std::cerr << anzahl << " GB konnten nicht beschafft werden! "
              << exc.what() << '\n';
  }
}
