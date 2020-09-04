/* cppbuch/k8/vektor/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Beispiel zur Vektor-Klasse
#include <iostream>
#define PRINT(X) std::cout << (#X) << " = " << (X) << '\n'
#include "vektor.t"

// globaler Ausgabe-Operator für Vektoren
template < typename T>
std::ostream& operator<<(std::ostream& os, const Vektor<T>& v) {
  // Verbesserungen im Ausgabelayout sind möglich!
  for (auto i = 0u; i < v.size(); ++i) {
    os << v[i] << '\t';
    if ((i + 1) % 8 == 0 || i == v.size() - 1) {
      os << '\n';
    }
  }
  return os;
}

int main() {
  Vektor<int> v(3, 7);
  PRINT(v);
  PRINT(v.size());
  v[0] = 1000;
  PRINT(v);

  constexpr auto ANZ = 16u;
  std::cout << "Vektor bedarfsweise vergrößern:\n";
  for (auto i = 0u; i < ANZ; ++i) {
    if (i == v.size()) {  // Platz verbraucht
      v.groesseAendern(i + 10);
      std::cout << "neu: ";
      PRINT(v.size());
    }
    v[i] = i * i;
  }

  std::cout << "nur die ersten " << ANZ << " Elemente sind definiert:\n"
            << "Ausgabeoperator: cout << v:\n"
            << v << '\n';

  std::cout << "Vektor auf " << ANZ << " Elemente reduzieren:\n";
  v.groesseAendern(ANZ);
  PRINT(v);
  PRINT(v.size());
  std::cout << "\nProgrammabbruch mit Indexfehler provozieren:\n";
  try {
    v[v.size()] = 8;  // v.size() ist zuviel! korrekt wäre 0..(v.size()-1)
  } catch (const std::out_of_range& ex) {
    std::cerr << "Exception gefangen: " << ex.what() << '\n';
  }
  std::cout << "\nconst-Vektor erzeugen\n";
  const Vektor<int> vc(10, 1);
  std::cout << vc << '\n';
  // vc[0] = 1; // nicht erlaubt für const Vektor
  std::cout << "\nZuweisung\n";
  v = vc;
  PRINT(v);
  std::cout << "\nTest des Sequenzkonstruktors\n";
  Vektor<int> v1{9, 8, 7, 6, 5, 4, 3};
  PRINT(v1);
}
