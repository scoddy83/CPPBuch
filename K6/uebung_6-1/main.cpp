// cppbuch/k6/erben/main.cpp
#include "strecke.h"
using namespace std;

int main() {
    // Definition zweier grafischer Objekte
    Ort nullpunkt;
    GraphObj g0(nullpunkt);                 // 1
    Ort einOrt(10, 20);
    GraphObj g1(einOrt);                    // 2
    // Ausgabe beider Bezugspunkte auf verschiedene Art
    cout << "g0.getX() = " << g0.getX() << '\n';
    cout << "g0.getY() = " << g0.getY() << '\n';
    
    Ort ort = g1.bezugspunkt();
    cout << "ort.getX() = " << ort.getX() << '\n';
    cout << "ort.getY() = " << ort.getY() << '\n';
    // Ausgabe der Entfernung
    cout << "Entfernung = " << entfernung(g0, g1) << '\n';
    cout << "neuer Bezugspunkt für g0:\n";
    g0.bezugspunkt(ort);                    // Rückgabewert wird hier ignoriert
    cout << "g0.bezugspunkt() = ";
    anzeigen(g0.bezugspunkt());             // ort.h, siehe Seite 171
    cout << "\n Entfernung = " << entfernung(g0, g1) << '\n';
    Ort anf;
    Strecke s1(anf, ort);
    cout << "Strecke von ";
    anzeigen(anf);
    cout << " bis ";
    anzeigen(ort);
    cout << "\n Fläche der Strecke s1 = "
         << s1.flaeche()                    // geerbte Methode
         << '\n';
    cout << "Länge der Strecke s1 = "
         << s1.laenge()                     // zusätzliche Methode
         << '\n';

    einOrt = Ort(20, 30);                   // Neuzuweisung
    Ort O2(100, 50);
    Strecke s2(einOrt, O2);
    cout << "Entfernung der Bezugspunkte: "
         << entfernung(s1.bezugspunkt(), s2.bezugspunkt()) << '\n';
    cout << "Entfernung der Strecke s1, s2 = " << entfernung(s1, s2) << '\n';
    //
}
