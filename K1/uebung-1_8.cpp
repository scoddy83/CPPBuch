//CPPBuch/K1/Übung 1.8
#include <iostream>
using namespace std;

int main() {
  int inpZahl1, inpZahl2, outpSumme;

  // Eingabe der beiden Zahlen
  cout << "Bitte geben sie zwei Zahlen an" << '\n';
  cout << "Erste kleinere Zahl :  ";
  cin >> inpZahl1;
  // Prüfen, dass die zweite Zahl grösser ist wie die erste Zahl
  do {
    cout << "Zweite groessere Zahl :  ";
    cin >> inpZahl2;
  } while(inpZahl1 >= inpZahl2);

  // Variante A
  outpSumme = 0;

  for(int i = inpZahl1; i <= inpZahl2; i++) {
    outpSumme += i;
  }
  cout << "Variante A: for-Schleife" << '\n';
  cout << "Die Summe aller Zahlen von " << inpZahl1 << " bis " << inpZahl2 << " lautet :  " << outpSumme << '\n';

  // Variante B
  int n = inpZahl1;
  outpSumme = 0;

  while(n <= inpZahl2) {
    outpSumme += n;
    n++;
  }
  cout << "Variante B: while-Schleife" << '\n';
  cout << "Die Summe aller Zahlen von " << inpZahl1 << " bis " << inpZahl2 << " lautet :  " << outpSumme << '\n';

  // Variante B
  int y = inpZahl1-1;
  outpSumme = 0;

  do {
    y++;
    outpSumme += y;
  } while(y < inpZahl2);
  cout << "Variante C: do  while-Schleife" << '\n';
  cout << "Die Summe aller Zahlen von " << inpZahl1 << " bis " << inpZahl2 << " lautet :  " << outpSumme << '\n';

  // Variante D
  outpSumme = inpZahl2*(inpZahl2+1)/2-inpZahl1*(inpZahl1+1)/2+inpZahl1;
  cout << "Variante D: ohne Schleife" << '\n';
  cout << "Die Summe aller Zahlen von " << inpZahl1 << " bis " << inpZahl2 << " lautet :  " << outpSumme << '\n';

  return 0;
}
