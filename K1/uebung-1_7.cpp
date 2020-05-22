//CPPBuch/K1/Übung 1.7
#include <iostream>
using namespace std;

int main() {
  int n=1, sum=0;
  while(n <= 100) {
    sum += n;
    n++;
  }
  cout << "Variante 1: Die Summe aller Zahlen von 1 bis 100 lautet :  " << sum << '\n';

  n=100;
  sum = n*(n+1)/2;
  cout << "\nVariante n: Die Summe aller Zahlen von 1 bis 100 lautet :  " << sum << '\n';

  return 0;
}
