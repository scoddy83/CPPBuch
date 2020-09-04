/* cppbuch/k1/primzahl.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Programm zum Berechnen einer Primzahl, die auf eine gegebene Zahl
// folgt

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  cout << "Berechnung der ersten Primzahl, die >="
          " der eingegebenen Zahl ist\n";
  // Hinweis: Mehrere, durch \tt{\dq} getrennte Texte ergeben
  //  {\em eine} lange Zeile in der Ausgabe.

  long z;

  // \tt{do while}-Schleife zur Eingabe und Plausibilitätskontrolle
  do {
    // Abfrage, solange \tt{z} $\le$ 3 ist
    cout << "Zahl > 3 eingeben :";
    cin >> z;
  } while (z <= 3);

  // Falls \tt{z} gerade ist, wird die nächste
  // ungerade Zahl als Startwert genommen.
  if (z % 2 == 0) {
    ++z;
  }
  bool gefunden{false};

  do {
    /* limit = Grenze, bis zu der gerechnet werden muss.
       sqrt() arbeitet mit  double, daher wird der Typ explizit
       umgewandelt.
    */
    long limit{1 + static_cast<long>(sqrt(static_cast<double>(z)))};
    long rest;
    long teiler{1};

    do {  // Kandidat \tt{z} durch alle ungeraden Teiler dividieren
      teiler += 2;
      rest = z % teiler;
    } while (rest > 0 && teiler < limit);

    if (rest > 0 && teiler >= limit) {
      gefunden = true;
    } else {  // sonst nächste ungerade Zahl untersuchen:
      z += 2;
    }
  } while (!gefunden);
  cout << "Die nächste Primzahl ist " << z << '\n';
}
