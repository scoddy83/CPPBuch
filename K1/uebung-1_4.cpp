/* cppbuch/loesungen/k1/4.cpp
   Übung zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
*/
#include <iostream>
using namespace std;

int main() {
  int zahl1;
  int zahl2;
  int zahl3;

  cout << "Bitte gebe 3 Zahlen an: " << '\n';
  cout << "Zahl 1: ";
  cin >> zahl1;
  cout << "Zahl 2: ";
  cin >> zahl2;
  cout << "Zahl 3: ";
  cin >> zahl3;

  if(zahl1 > zahl2 && zahl1 > zahl3) {
    cout << "Zahl 1 " << zahl1 << " ist groesser wie die Zahl 2 " << zahl2 << " und Zahl 3 " << zahl3 << '\n';
  } else if(zahl2 > zahl3) {
    cout << "Zahl 2 " << zahl2 << " ist groesser wie die Zahl 1 " << zahl1 << " und Zahl 3 " << zahl3 << '\n';
  } else {
    cout << "Zahl 3 " << zahl3 << " ist groesser wie die Zahl 1 " << zahl1 << " und Zahl 2 " << zahl2 << '\n';
  }

}
