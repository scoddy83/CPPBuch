/* cppbuch/loesungen/k1/2.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/
*/
#include <iostream>
using namespace std;

int main() {
  unsigned int ui = 0u;         // u = unsigned
  unsigned long int uli = 0ul;  // ul = unsigned long
  unsigned long long int ulli = 0ull;
  cout << "max. unsigned int          = " << ~ui << '\n';
  cout << "max. unsigned long int     = " << ~uli << '\n';
  cout << "max. unsigned long long int= " << ~ulli << '\n';
  cout << "max. int                   = " << static_cast<int>(~ui >> 1)
       << '\n';
  cout << "max. long int              = " << static_cast<long int>(~uli >> 1)
       << '\n';
  cout << "max. long long int         = "
       << static_cast<long long int>(~ulli >> 1) << '\n';

  cout << "Annahme: char = 8 Bits; short = 16 Bits\n";
  cout << "max. unsigned char           = " << 0b11111111 << '\n';
  cout << "max. signed char             = " << 0b01111111 << '\n';
  cout << "max. unsigned short          = " << 0b1111'1111'1111'1111 << '\n';
  cout << "max. signed short            = " << 0b0111'1111'1111'1111 << '\n';

  cout << "Je nach System können manche der Werte gleich sein, also "
          "dieselbe"
          " Anzahl Bits verwenden.\n";
}
