/* cppbuch/loesungen/k2/7.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/
*/
#include <iostream>
#include <string>

bool istAlphanumerisch(const std::string& text);

int main() {
  std::string einText;
  std::cout << "Zeichenfolge eingeben :";
  std::getline(std::cin, einText);
  if (istAlphanumerisch(einText)) {
    std::cout << "Die eingegebene Zeichenkette enthält "
                 "nur Buchstaben und Ziffern.\n";
  } else {
    std::cout << "Die eingegebene Zeichenkette enthält NICHT "
                 "nur Buchstaben und Ziffern.\n";
  }
}

bool istAlphanumerisch(const std::string& text) {
  bool ergebnis{true};
  for (char zeichen : text) {
    bool istZiffer = zeichen >= '0' && zeichen <= '9';
    bool istBuchstabe = (zeichen >= 'A' && zeichen <= 'Z') ||
                        (zeichen >= 'a' && zeichen <= 'z');
    // && bindet stärker, die Klammern sind nur zur besseren
    // Lesbarkeit
    if (!istZiffer && !istBuchstabe) {
      ergebnis = false;
      break;  // weitere Prüfungen sind nicht notwendig
    }
  }
  return ergebnis;
}
