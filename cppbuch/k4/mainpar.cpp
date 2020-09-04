/* cppbuch/k4/mainpar.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;

int main(int argc, char* argv[], char* env[]) {
  cout << "Aufruf des Programms = " << argv[0] << '\n';

  cout << (argc - 1) << " weitere Argumente wurden main() übergeben:\n";

  int i{1};
  while (argv[i]) {
    cout << argv[i++] << '\n';
  }

  cout << "\n*** Umgebungs-Variablen: ***\n";
  i = 0;
  while (env[i]) {
    cout << env[i++] << '\n';
  }
}
