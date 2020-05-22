//CPPBuch/K1/Übung 1.9
#include <iostream>
using namespace std;

int main () {
  char c;
  bool laufen {true};

  while (laufen) {
    cout << "Waehlen Sie : a, b, x = Ende : ";
    cin >> c;

    switch (c) {
      case 'a':
        cout << "Programm a\n";
        break;
      case 'b':
        cout << "Programm b\n";
        break;
      case 'x':
        laufen = false;
        break;
      default:
        cout << "Falsche Eingabe! Bitte wiederholen!\n";
    }
  }
  cout << "\n Programmende mit break\n";
}
