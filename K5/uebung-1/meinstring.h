// /cppbuch/k5/meinstring/meinstring.h
#ifndef MEINSTRING_H
#define MEINSTRING_H
#include <cstddef> // size_t
#include <iostream> // ostream
#include <vector>

class MeinString {
public:
    MeinString(const char* str = ""); // allg. Konstruktor
    MeinString& assign(const char*); // Zuweisung eines char*
    const char& at(std::size_t position) const; // Zeichen holen
    char& at(std::size_t position); // Zeichen holen
    // Wegen des Rückgabetyps Referenz kann das Zeichen geändert werden.
    auto length() const { return daten.size() - 1; } // Anzahl der Zeichen
    auto data() const { return daten.data(); } // Zeiger auf Inhalt zurückgeben
    void swap(MeinString&); // vertauschen
    auto begin() const { return daten.begin(); }
    auto end() const { return daten.end(); }

private:
    std::vector<char> daten;
};

void anzeigen(std::ostream &os, const MeinString &m);
#endif