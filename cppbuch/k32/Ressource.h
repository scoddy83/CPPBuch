/* cppbuch/k32/Ressource.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <iostream>

class Ressource {
public:
  Ressource(int i) : id(i) { std::cout << "Konstruktor Ressource()\n"; }
  void hi() const {
    std::cout << "hier ist Ressource::hi(), Id=" << id << '\n';
  }
  ~Ressource() { std::cout << "Ressource::Destruktor, Id=" << id << '\n'; }

private:
  int id;
};
#endif
