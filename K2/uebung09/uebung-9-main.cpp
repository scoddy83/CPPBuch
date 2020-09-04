#include <iostream>
#include "uebung-9.hpp"

using namespace std;

int main() {
  char ch;
  do {
    cout << "\n>>";
    cin.get(ch);
    if(ch != 'e') {
      cout << ausdruck(ch);
    }
  } while (ch != 'e');

  return 0;
}
