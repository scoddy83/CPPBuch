//CPPBuch/K2/Übung 2.4
#include <iostream>

void bewegen (unsigned int n, unsigned int quelle, unsigned int ziel,
              unsigned int zwischen) {
  while (n > 0) {
    std::cout << "Bringe eine Scheibe von " << quelle
              << " nach " << ziel << '\n';
    bewegen(n-1, ziel, zwischen, quelle);
    n--;

  }
}

int main() {
  std::cout << "Tuerme von Hanoi! Anzahl der Scheiben: ";
  unsigned int scheiben;
  std::cin >> scheiben;
  bewegen(scheiben, 1, 2, 3);
}
