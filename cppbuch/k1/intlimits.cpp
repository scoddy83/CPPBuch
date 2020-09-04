/* cppbuch/k1/intlimits.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <limits>  // hier sind die Bereichsinformationen
using namespace std;

int main() {
  cout << "Grenzwerte für Ganzzahl-Typen:" << '\n';  // = neue Zeile
  cout << "int Minimum =       " << numeric_limits<int>::min() << '\n';
  cout << "int Maximum =        " << numeric_limits<int>::max() << '\n';
  cout << "long Minimum =      " << numeric_limits<long>::min() << '\n';
  cout << "long Maximum =       " << numeric_limits<long>::max() << '\n';
  cout << "long long Minimum =     " << numeric_limits<long long>::min()
       << '\n';
  cout << "long long Maximum =      " << numeric_limits<long long>::max()
       << '\n';
  cout << "unsigned-Maxima (Minimum ist 0):\n";  // \n ebenfalls neue
                                                 // Zeile
  cout << "unsigned int  =  " << numeric_limits<unsigned int>::max() << '\n';
  cout << "unsigned long =  " << numeric_limits<unsigned long>::max() << '\n';
  cout << "unsigned long long = " << numeric_limits<unsigned long long>::max()
       << '\n';

  cout << "Anzahl der Bytes für:\n";
  cout << "int       " << sizeof(int) << '\n';
  cout << "long      " << sizeof(long) << '\n';
  cout << "long long " << sizeof(long long) << '\n';
  cout << "size_t    " << sizeof(size_t) << '\n';
}
