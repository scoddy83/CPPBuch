/* cppbuch/k23/vermischtes/remove.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <showContainer.h>
#include <string>
#include <vector>

bool istVokal(char c) {
  const static std::string vokale("aeiouAEIOU");
  return vokale.find(c) != std::string::npos;
}
using namespace std;

int main() {
  vector<char> v(26);
  iota(v.begin(), v.end(), 'a');  // Alphabet mit Kleinbuchstaben erzeugen
  showContainer(v, "\n", "");
  cout << "remove 't': ";
  auto last = remove(v.begin(), v.end(), 't');
  // \tt{last} = neues Ende nach der Verschiebung, \tt{v.end()}
  // bleibt
  // unverändert!
  // Die Sequenz wird hier nicht mit \tt{showContainer()} angezeigt,
  // weil nur die Zeichen von \tt{begin()} bis Iterator \tt{last}
  // signifikant sind.
  ostream_iterator<char> ausgabe(cout, "");
  copy(v.begin(), last, ausgabe);  // abcdefghijklmnopqrsuvwxyz   (t fehlt)
  cout << '\n';
  last = remove_if(v.begin(), last, istVokal);
  cout << "nur noch Konsonanten übrig: ";
  copy(v.begin(), last, ausgabe);  // bcdfghjklmnpqrsvwxyz
  cout << "\nVollständige Sequenz einschließlich bedeutungsloser "
          "Elemente am Ende:\n";
  showContainer(v, "\n", "");
}
