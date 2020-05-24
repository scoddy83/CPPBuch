//CPPBuch/K1/Übung 1.13
#include <iostream>
#include <vector>
using namespace std;



int main () {
  const int kleinsteZahl {-99};
  const int groessteZahl {100};
  int zahl {0};
  int temp;

  vector<int> intervalle(200/10);

  cout << "Bitte gebe eine Zahl zwischen " << kleinsteZahl << " und " << groessteZahl << " an\n";
  cout << "Um zu Beenden gebe eine Zahl ausserhalb des bereichs an\n";

  while (zahl >= kleinsteZahl && zahl <= groessteZahl) {
    cout << "Neue Zahl :  ";
    cin >> zahl;
    temp = kleinsteZahl;

    for (int i = 0; i < 200/10; i++) {
      if(zahl >= temp && zahl < temp+10) {
          intervalle[i] += 1;
      }
      temp += 10;
    }
  }

  cout << "Ausgabe je Intervall: \n";
  zahl = kleinsteZahl;

  for (int i = 0; i < intervalle.size(); i++) {
    cout << "Intervall von " << zahl << " bis " << zahl + 10 << " : " << intervalle[i] << '\n';
    zahl += 10;
  }
}
