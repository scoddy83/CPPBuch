//CPPBuch/K2/Übung 2.5
#include <iostream>
#include <string>

using namespace std;

void str_umkehr(string& s) {
  string newS;
  for (int i  = s.length()-1; i >= 0; i--) {
    cout << s.at(i);
  }
}

int main() {
  string input;
  cout << "Bitte geben Sie ein Wort an: ";
  getline(cin, input);
  str_umkehr(input);

  return 0;
}
