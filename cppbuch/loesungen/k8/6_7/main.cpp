/* cppbuch/loesungen/k8/6_7/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "meinstring.h"
#include <iostream>
using namespace std;

int main() {
  MeinString einString("Hallo");
  cout << "operator<<():\n" << einString << '\n';
  cout << "operator[](1):" << einString[1] << '\n';
  cout << "operator+=():\n";
  MeinString str2(" guten");
  einString += str2;
  cout << einString << '\n';
  einString += " Tag!";
  cout << einString << '\n';
  cout << "operator+():\n";
  cout << einString + einString << '\n';
}
