/* cppbuch/k1/is_signed.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <limits>  // hier sind die Bereichsinformationen
using namespace std;

int main() {
  if (numeric_limits<char>::is_signed) {
    cout << "char wird auf diesem System als signed "
            "interpretiert.\n";
  } else {
    cout << "char wird auf diesem System als unsigned "
            "interpretiert.\n";
  }
  cout << "Grenzwerte für char, in int umgewandelt:\n";
  cout << "Minimum =      " << static_cast<int>(numeric_limits<char>::min())
       << '\n';
  cout << "Maximum =       " << static_cast<int>(numeric_limits<char>::max())
       << '\n';
}
