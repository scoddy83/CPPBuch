//CPPBuch/K1/Übung 1.5
#include <iostream>
using namespace std;

int main() {
  int zahl;
  cout << "Eingabe einer beliebigen Zahl:  ";
  cin >> zahl;
  int anzahlDerBytes = sizeof zahl;
  int anzahlderBites = anzahlDerBytes * 8;
  cout << "binaer : ";
  for (int k = anzahlderBites-1; k >= 0; k--)
  {
    if(zahl & (1 << k))
    {
      cout << '1';
    } else
    {
      cout << '0';
    }
  }
  return 0;
}
