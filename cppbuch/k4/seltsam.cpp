/* cppbuch/k4/seltsam.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// Absurdes Programm nur zur Demonstration der Compilation
// komplizierter Alias-Typnamen
#include <iostream>
using namespace std;

const char* (*(*seltsam)(double, int))[3];

// mit typedef
// typedef const char *ArrayVon3CharZeigern[3];
// typedef ArrayVon3CharZeigern *ZeigerAufArrayVon3CharZeigern;
// alternativ typedef const char* (*ZeigerAufArrayVon3CharZeigern)
// [3];
// typedef ZeigerAufArrayVon3CharZeigern (*seltsamerTyp)(double,
// int);
// alternativ typedef const char*(*(*seltsamerTyp)(double,int))[3];

// mit using
using ArrayVon3CharZeigern = const char * [3];
using ZeigerAufArrayVon3CharZeigern = ArrayVon3CharZeigern*;
using seltsamerTyp = ZeigerAufArrayVon3CharZeigern (*)(double, int);
// alternativ using seltsamerTyp = const char*(*(*)(double,int))[3];

ArrayVon3CharZeigern arrayVon3CharZeigern1{"eins", "zwei", "drei"};
ArrayVon3CharZeigern arrayVon3CharZeigern2{"vier", "fünf", "sechs"};

ZeigerAufArrayVon3CharZeigern seltsameFunktion(double x, int y) {
  cout << "seltsameFunktion(" << x << ", " << y << ") aufgerufen!\n";
  ZeigerAufArrayVon3CharZeigern z = &arrayVon3CharZeigern1;
  if (y % 2)
    z = &arrayVon3CharZeigern2;
  return z;
}

int main() {
  ZeigerAufArrayVon3CharZeigern z;
  seltsam = seltsameFunktion;
  z = seltsam(3.1, 2);  // Ausführung über Zeiger
  cout << (*z)[0] << '\n';
  cout << (*z)[1] << '\n';
  cout << (*z)[2] << '\n';
  seltsamerTyp X{seltsam};
  z = X(0.081, 99);  // Ausführung über Zeiger
  cout << (*z)[0] << '\n';
  cout << (*z)[1] << '\n';
  cout << (*z)[2] << '\n';
}
