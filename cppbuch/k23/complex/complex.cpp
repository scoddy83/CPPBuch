/* cppbuch/k23/complex/complex.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <complex>  // Header für komplexe Zahlen
#include <iostream>
#include <pi.h>  // $\pi$
using namespace std;

// Beispiele für komplexe Zahlen
// Anstatt \tt{double} sind auch \tt{float} und \tt{long double}
// möglich.
int main() {
  complex<double> c1;            // komplexe Zahl 0.0 + 0.0{\it i}
  complex<double> c2(1.2, 3.4);  // (1.2 + 3.4{\it i}) erzeugen
  cout << c2 << '\n';            // Standard-Ausgabeformat: (1.2,3.4)

  c1 += c2 + c1;  // beispielhafte Rechenoperationen
  c1 = c2 * 5.0;

  double re = c1.real();      // Realteil ermitteln
  cout << re << '\n';         // und ausgeben
  cout << c1.imag() << '\n';  // Imaginärteil direkt ausgeben

  // Beispiele mit Hilfsfunktionen

  complex<double> c3 = {1.0, 2.0};  // (1.0 + 2.0{\it i}) erzeugen
  c1 = conj(c3);                    // konjugiert komplex: (1.0 - 2.0{\it i})

  // Umrechnung aus Polarkoordinaten
  double betrag = 100.0;
  double phase = pi<double> / 4.0;  // pi/4 = 45 Grad
  c1 = polar(betrag, phase);

  // Umrechnung in Polarkoordinaten
  double rho = abs(c1);    // Betrag $\rho$
  double theta = arg(c1);  // Winkel $\theta$

  double nrm = norm(c1);  // Betragsquadrat

  cout << "Betrag  = " << betrag << '\n';
  cout << "rho     = " << rho << '\n';
  cout << "Norm    = " << nrm << '\n';
  cout << "Phase   = " << phase << '\n';
  cout << "theta   = " << theta << " = " << theta / pi<double> * 180.
       << " Grad\n";
  cout << "Komplexe Zahl eingeben. Erlaubte Formate (Beispiel):"
          "\n (1.78, -98.2)\n (1.78)\n 1.78\n:";
  cin >> c1;
  cout << "komplexe Zahl = " << c1 << '\n';

  // Erzeugung imaginärer Zahlen (Realteil ist 0) mit Suffix i
  complex<double> imaginaer{3.7i};
  cout << "imaginaere Zahl = " << imaginaer << '\n';
}
