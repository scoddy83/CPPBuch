#include <iostream>
#include <string>

bool istAlphanumerisch(const std::string& text);

int main() {
  std::string text;
  std::cout << "Zeichenfolge eingeben: ";
  std::getline(std::cin, text);
  if(istAlphanumerisch(text))
    std::cout << "Eingabe besteht nur aus Buchstaben und Ziffern.\n";
  else
    std::cout << "Eingabe besteht NICHT nur aus Buchstaben und Ziffern.\n";
  return 0;
}


bool istAlphanumerisch(const std::string& text) {
  bool ergebnis{true};
  for (char zeichen : text) {
    bool istZiffer = zeichen >= '0' && zeichen <= '9';
    bool istBuchstabe = (zeichen >= 'A' && zeichen <= 'Z') ||
                        (zeichen >= 'a' && zeichen <= 'z');
    if (!istZiffer && !istBuchstabe) {
      ergebnis = false;
      break;
    }
  }
  return ergebnis;
}
