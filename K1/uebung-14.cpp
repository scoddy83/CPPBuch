//CPPBuch/K1/Übung 1.14
#include <iostream>
using namespace std;

int main () {
  long long zahl {0};

  cout << "Bitte geben Sie eine Zahl ein :  ";
  cin >> zahl;

  int iterationen {0};
  long long max {zahl};

  do {
    if(zahl%2 == 0) {
      zahl /= 2;
    } else {
      zahl = zahl * 3 + 1;
    }
    cout << "Zahl = " << zahl << '\n';
    if (zahl > max) {
      max = zahl;
      cout << "neues Maximum. Weiter mit ENTER\n";
      string dummy;
      getline(cin, dummy);  // weiter mit Tastendruck
    }
    iterationen++;
  } while(zahl > 1);
  cout << "Max = " << max << '\n';
  cout << "Iterationen = " << iterationen << '\n';

}
