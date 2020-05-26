//CPPBuch/K1/Übung 1.13
#include <iostream>
#include <vector>
using namespace std;



int main () {
  const int MINIMUM {-99};
  const int MAXIMUM {100};
  const int INTERVALL {10};
  const int INTERVALBREITE {(MAXIMUM - MINIMUM + 1) / INTERVALL};
  int eingabe {0};

  vector<int> intervalle(INTERVALL);

  cout << "Bitte gebe eine Zahl zwischen " << MINIMUM << " und " << MAXIMUM << " an\n";
  cout << "Um zu Beenden gebe eine Zahl ausserhalb des bereichs an\n";

  while (eingabe >= MINIMUM && eingabe <= MAXIMUM) {
    cout << "Neue Zahl :  ";
    cin >> eingabe;
    intervalle[(eingabe-MINIMUM)/INTERVALBREITE]++;
  }

  cout << "Ausgabe je Intervall: \n";

  for (int i = 0; i < INTERVALL; i++) {
    cout << "Intervall von " << i * INTERVALBREITE +  MINIMUM << " : "
         << (i + 1) * INTERVALBREITE +  MINIMUM - 1 << " : " << intervalle[i]
         << '\n';
  }
}
