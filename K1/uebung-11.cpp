//CPPBuch/K1/Übung 1.11
#include <iostream>
#include <string>
using namespace std;



int main () {
  const string str{"22"};
  long int z{0L};

  for (auto zeichen : str) {
    z *= 10;
    z+= static_cast<int>(zeichen) - static_cast<int>('0');
  }
  cout << "str = " << str << '\n';
  cout << "z = " << z << '\n';

  int quersumme{};
  while(z > 0) {
    quersumme += z % 10;
    z /= 10;
  }
  cout << "Quersumme = " << quersumme << '\n';
}
