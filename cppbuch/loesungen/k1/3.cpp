/* cppbuch/loesungen/k1/3.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main() {
  int anfang;
  int ende;
  cout << "Nur ganze Zahlen eingeben:\nBereichsanfang:";
  cin >> anfang;
  cout << "Bereichsende:";
  cin >> ende;
  if (anfang > ende) {
    cout << "Der Bereichsanfang darf nicht nach dem Bereichsende "
            "liegen!\n";
  } else {
    cout << "Zahl:";
    int zahl;
    cin >> zahl;
    if (zahl >= anfang && zahl <= ende) {
      cout << zahl << " liegt im Bereich " << anfang << ".." << ende << '\n';
    } else {
      cout << zahl << " liegt nicht im Bereich " << anfang << ".." << ende
           << '\n';
    }
  }
}
