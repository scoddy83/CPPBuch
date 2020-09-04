/* cppbuch/loesungen/k2/6.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cctype>
#include <iostream>

// ********** Funktionsprototypen **********
long zahl(char& c);
long ausdruck(char& c);
long summand(char& c);
long faktor(char& c);

// ********** Hauptprogramm **********
int main() {
  char ch;
  do {
    std::cout << "\n>>";
    std::cin.get(ch);
    if (ch != 'e')
      std::cout << ausdruck(ch);
  } while (ch != 'e');
}

// ********** Funktionsdefinitionen **********
long ausdruck(char& c) {  // Übergabe per Referenz!
  long a;                 // Hilfsvariable für Ausdruck
  if (c == '-') {
    std::cin.get(c);  // \tt{-} im Eingabestrom überspringen
    a = -summand(c);  // Rest an \tt{summand()} übergeben
  } else {
    if (c == '+')
      std::cin.get(c);  // \tt{+} überspringen
    a = summand(c);
  }
  while (c == '+' || c == '-')
    if (c == '+') {
      std::cin.get(c);  // \tt{+} überspringen
      a += summand(c);
    } else {
      std::cin.get(c);  // \tt{-} überspringen
      a -= summand(c);
    }
  return a;
}

long summand(char& c) {
  long s = faktor(c);
  while (c == '*' || c == '/')
    if (c == '*') {
      std::cin.get(c);  // \tt{*} überspringen
      s *= faktor(c);
    } else {
      std::cin.get(c);  // \tt{/} überspringen
      s /= faktor(c);
    }
  return s;
}

long faktor(char& c) {
  long f;

  if (c == '(') {
    std::cin.get(c);  // \tt{(} überspringen
    f = ausdruck(c);
    if (c != ')')
      std::cout << "Rechte Klammer fehlt!\n";  //*** s.u.
    else
      std::cin.get(c);  // \tt{)} überspringen
  } else
    f = zahl(c);
  return f;
}

long zahl(char& c) {
  long z = 0;
  while (isdigit(c)) {
    z = 10 * z + long(c - '0');
    std::cin.get(c);
  }
  return z;
}
