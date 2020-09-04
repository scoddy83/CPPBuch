/* cppbuch/k1/schleifenInContainern.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>  // size_t
#include <iostream>
#include <string>  // Standard-String einschließen
#include <vector>  // Standard-Vektor einschließen
using namespace std;

int main() {
  vector<double> einVektor = {1.41, 2.72, 3.14159, 4.09};
  string einString("eine Zeichenkette");

  cout << "klassische Zählschleife:\n";
  for (size_t i = 0; i < einVektor.size(); ++i) {
    cout << einVektor[i] << '\t';
  }
  cout << '\n';
  for (size_t i = 0; i < einString.length(); ++i) {
    cout << einString[i];
  }
  cout << '\n';

  cout << "vector: Schleifenkurzformen:\n";
  for (double wert : einVektor) {  // Kopie, könnte geändert werden
    cout << wert << '\t';
  }
  cout << '\n';
  for (const double wert : einVektor) {  // nicht veränderliche Kopie
    cout << wert << '\t';
  }
  cout << '\n';
  for (double& wert : einVektor) {  // Referenz zum Ändern
    wert *= 2.0;
  }
  for (const double& wert : einVektor) {  // Referenz zum Lesen
    cout << wert << '\t';
  }
  cout << '\n';

  cout << "string: Schleifenkurzformen\n";
  for (char zeichen : einString) {  // Kopie
    cout << zeichen;
  }
  cout << '\n';
  for (char& zeichen : einString) {  // Referenz zum Ändern
    if (zeichen == ' ') {
      zeichen = '_';
    }
  }
  for (const char& zeichen : einString) {  // Referenz zum Lesen
    cout << zeichen;
  }

  cout << "\n\nMit auto:\n";

  cout << "vector: Schleifenkurzformen\n";
  for (auto wert : einVektor) {  // Kopie
    cout << wert << '\t';
  }
  cout << '\n';
  for (auto& wert : einVektor) {  // Referenz zum Ändern
    wert *= 2.0;
  }
  for (const auto& wert : einVektor) {  // Referenz zum Lesen
    cout << wert << '\t';
  }
  cout << '\n';

  cout << "string: Schleifenkurzformen\n";
  for (auto zeichen : einString) {  // Kopie
    cout << zeichen;
  }
  cout << '\n';
  for (auto& zeichen : einString) {  // Referenz zum Ändern
    if (zeichen == '_') {
      zeichen = ' ';
    }
  }
  for (const auto& zeichen : einString) {  // Referenz zum Lesen
    cout << zeichen;
  }
  cout << '\n';
}
