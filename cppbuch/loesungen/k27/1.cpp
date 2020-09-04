/* cppbuch/loesungen/k27/1.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Aufgabe 28.1 = Aufgabe 4.11, wobei die Rekursion durch
// einen Stack simuliert wird.
#include <iostream>
#include <stack>
using namespace std;

void bewegen(int n, int a, int b, int c) {
  stack<int> s;
  int t;  // zum Vertauschen der Werte
  // ersten Aufruf transformieren
  while (n > 0) {
    // aktuelle Daten sichern
    s.push(n);
    s.push(a);
    s.push(b);
    s.push(c);
    // Aufruf mit neuen Daten simulieren
    --n;
    t = b;
    b = c;
    c = t;
  }

  // Haupt-Schleife
  while (!s.empty()) {
    c = s.top();
    s.pop();  // Daten wiederherstellen
    b = s.top();
    s.pop();
    a = s.top();
    s.pop();
    n = s.top();
    s.pop();
    cout << "Bringe eine Scheibe von " << a << " nach " << b << '\n';
    --n;
    t = a;
    a = c;
    c = t;

    while (n > 0) {
      // aktuelle Daten sichern
      s.push(n);
      s.push(a);
      s.push(b);
      s.push(c);
      // Aufruf mit neuen Daten simulieren
      --n;
      t = b;
      b = c;
      c = t;
    }
  }
}

int main() {
  cout << "Türme von Hanoi! Anzahl der Scheiben: ";
  int scheiben;
  cin >> scheiben;
  bewegen(scheiben, 1, 2, 3);
}
