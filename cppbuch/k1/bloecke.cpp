/* cppbuch/k1/bloecke.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;
// \tt{a} und \tt{b} werden außerhalb eines jeden Blocks deklariert. Sie
// sind damit innerhalb
// eines jeden anderen Blocks gültig und heißen daher globale Variablen.
int a{1};
int b{2};

int main() {                            // Ein neuer \Index{Block} beginnt.
  cout << "globales a= " << a << '\n';  // Ausgabe von \tt{a}

  // Innerhalb des Blocks wird eine Variable \tt{a} deklariert. Ab jetzt ist
  // das \index{global} globale \tt{a} noch
  // gültig, aber nicht mehr unter dem Namen \tt{a} sichtbar, wie die
  // Folgezeile zeigt.
  int a{10};
  // Der Wert des lokalen \tt{a} wird ausgegeben:
  cout << "lokales a= " << a << '\n';

  // Das globale \tt{a} lässt sich nach der Deklaration des lokalen \tt{a}
  // nur noch mithilfe des
  // Bereichsoperators \tt{::} \engl{scope ope\-ra\-tor} ansprechen. Ausgabe
  // von \tt{::a}.

  cout << "globales ::a= " << ::a << '\n';
  {  // Ein neuer Block innerhalb des bestehenden beginnt.
    int b{20};
    // Variable \tt{b} wird innerhalb dieses Blocks deklariert.
    // Damit wird das globale \tt{b} zwar nicht ungültig, aber unsichtbar.
    int c{30};  //  \tt{c} wird innerhalb dieses Blocks deklariert.
    // Die Werte von \tt{b}  und \tt{c}  werden ausgegeben.
    cout << "lokales b = " << b << '\n';
    cout << "lokales c = " << c << '\n';

    // Wie oben beschrieben, ist das globale \tt{b} nur über den
    // Scope-Operator ansprechbar. Ausgabe von \tt{::b}.
    cout << "globales ::b = " << ::b << '\n';
  }  // Der innere Block wird geschlossen. Damit ist das globale \tt{b}
  // auch ohne Scope-Operator wieder sichtbar:
  cout << "globales b wieder sichtbar: b = " << b << '\n';

  // cout << "c = " << c << '\n'; // Fehler, siehe Text
}  //  Ende des äußeren Blocks
