//CPPBuch/K2/Übung 2.3
#include <iostream>
using namespace std;

long fakultaet(int);

int main() {
  int zahl {0};
  cout << "Gebe eine positive Zahl ein: ";
  cin >> zahl;
  cout << "Die Fakultaet der Zahl " << zahl << " ist " << fakultaet(zahl);
  return 0;
}

 long fakultaet( int zahl) {
  if(zahl > 1) {
    return zahl * fakultaet(zahl -1);
  } else {
    return 1;
  }
}
