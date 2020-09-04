/* cppbuch/k4/ret_new.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Demonstration des Fehlers, ein mit new erzeugtes Objekt zurückzugeben

#include <iostream>
using namespace std;

class Testobjekt {
  char Name;

public:
  Testobjekt(char);
  Testobjekt(const Testobjekt& t);
  ~Testobjekt();
  void drucken() const;
};

Testobjekt::Testobjekt(char N) : Name(N) {
  cout << Name << ".Konstruktor aufgerufen! " << Name << ".this = " << this
       << '\n';  // Adresse ausgeben
}

Testobjekt::Testobjekt(const Testobjekt& t) : Name(t.Name) {
  cout << "Copy-Konstruktor aufgerufen! Argument: ";
  t.drucken();
  cout << "Copy-Konstruktor wird verlassen.\n";
}

Testobjekt::~Testobjekt() {
  cout << "Destruktor für " << Name << ".this=" << this << " aufgerufen!\n";
}

void Testobjekt::drucken() const {
  cout << "drucken: " << Name << ".this= " << this << '\n';
}

Testobjekt return_Testobjekt(char N) {  // Hier steckt der FEHLER!
  cout << "return_Testobjekt() vor return!\n";
  Testobjekt* ptr = new Testobjekt(N);
  cout << "Das Objekt an dieser Adresse wird nie gelöscht!\n";
  return *ptr;  // Rückgabe eines mit new erzeugten Objekts
}

int main() {
  Testobjekt A('A');
  Testobjekt& B = *new Testobjekt('B');
  Testobjekt C = return_Testobjekt('C');

  cout << "nach Aufruf von return_Testobjekt()\n";
  C.drucken();
  delete &B;  // expliziter Destruktoraufruf für Referenz
}
