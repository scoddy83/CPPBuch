// cppbuch/k6/include/ort.h
#ifndef ORT_H
#define ORT_H
#include <cmath>            // wegen sqrt()
#include <iostream>

class Ort {
public:
    Ort(int einX = 0, int einY = 0)
    : xKoordinate {einX}, yKoordinate {einY} {}

    int getX() const {
        return xKoordinate;
    }

    int getY() const {
        return yKoordinate;
    }
    void aendern(int x, int y) {
        xKoordinate = x;
        yKoordinate = y;
    }

private:
    int xKoordinate;
    int yKoordinate;
};

inline void anzeigen(const Ort& o) {            // globale Funktion
    std::cout << '(' << o.getX() << ", " << o.getY() << ')';
}

// globale Funktion zur Berechnung der Entfernung zwischen zwei Orten
inline auto entfernung(const Ort& ort1, const Ort& ort2) {
    double dx = static_cast<double>(ort1.getX() - ort2.getX());
    double dy = static_cast<double>(ort1.getY() - ort2.getY());
    return std::sqrt(dx*dx + dy*dy);
}


#endif // ORT_H