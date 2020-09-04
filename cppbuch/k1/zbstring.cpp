/* cppbuch/k1/zbstring.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>  // \tt{size\_t }
#include <iostream>
#include <string>  // Standard-String einschließen
using namespace std;

int main() {  // Programm mit typischen String-Operationen
  // String-Objekt einString anlegen und mit "hallo" initialisieren.
  // einString kann ein beliebiger Name sein.
  string einString{"hallo"};

  // String ausgeben
  cout << einString << '\n';

  // Beim Vektor wäre stattdessen für die Ausgabe
  //  eine Schleife notwendig, etwa der folgenden Art:

  // String zeichenweise ausgeben, ungeprüfter Zugriff wie bei
  // \tt{vector}:
  for (size_t i = 0; i < einString.size(); ++i) {
    cout << einString[i];
  }
  cout << '\n';

  // String zeichenweise mit Indexprüfung ausgeben. Die Anzahl der
  // Zeichen kann bei Strings auch mit \tt{length()} ermittelt
  // werden.
  for (size_t i = 0; i < einString.length(); ++i) {
    cout << einString.at(i);
  }
  cout << '\n';

  // Die Prüfung geschieht wie beim Vektor. Ein Versuch,
  // \tt{einString.at(i)}
  // mit \tt{i} $\ge$ \tt{einString.size()} abzufragen, führt zum
  // Programmabbruch mit Fehlermeldung.

  // Kopie des Strings \tt{einString} erzeugen
  string eineStringKopie(einString);
  cout << eineStringKopie << '\n';  // hallo

  // Kopie durch Zuweisung
  string diesIstNeu{"neu!"};
  eineStringKopie = diesIstNeu;
  cout << eineStringKopie << '\n';  // neu!

  // Zuweisung einer Zeichenkette in Anführungszeichen
  eineStringKopie = "Buchstaben";
  cout << eineStringKopie << '\n';  // Buchstaben

  // Zuweisung nur eines Zeichens vom Typ \tt{char}
  einString = 'X';
  cout << einString << '\n';  // X

  // Strings mit dem \tt{+=}-Operator verketten
  einString += eineStringKopie;
  cout << einString << '\n';  // XBuchstaben

  // Strings mit dem \tt{+}-Operator verketten
  einString = eineStringKopie + " ABC";
  cout << einString << '\n';  // Buchstaben ABC

  einString = "123" + eineStringKopie;
  cout << einString << '\n';  // 123Buchstaben

  // einString = "123" + "ABC";               // geht \emph{nicht}!
  // Erklärung folgt in Kapitel \ref{Ueberladen von Operatoren}
  einString = string("123") + "ABC";  // ok!

  // Vergleich von Strings
  string a{"Albert"};
  string z{"Alberta"};
  string b{a};
  if (a == b) {
    cout << a << " == " << b << '\n';
  } else {
    cout << a << " != " << b << '\n';
  }
  if (a < z) {
    cout << a << " < " << z << '\n';
  }
  if (z > a) {
    cout << z << " > " << a << '\n';
  }
  if (z != a) {
    cout << z << " != " << a << '\n';
  }

  // String mit Initialisierungsliste  {'a', 'b', 'c'}
  string str{'a', 'b', 'c'};
  cout << "mit Initialisierungsliste erzeugter String:" << str << '\n';
}
