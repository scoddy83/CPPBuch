/* cppbuch/k3/sequenzkonstruktor/zahlenfolge2.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ZAHLENFOLGE2_H
#define ZAHLENFOLGE2_H
#include <initializer_list>
#include <iostream>
#include <vector>

class Zahlenfolge {
public:
  Zahlenfolge() { std::cout << "Zahlenfolge() "; }

  Zahlenfolge(int i) {
    std::cout << "Zahlenfolge(int) ";
    folge.push_back(i);
  }

  Zahlenfolge(int i1, int i2) {
    std::cout << "Zahlenfolge(int, int) ";
    folge.push_back(i1);
    folge.push_back(i2);
  }

  Zahlenfolge(std::initializer_list<int> liste) {
    std::cout << "Zahlenfolge(initializer_list) ";
    folge.assign(liste);
  }

  void print() const {
    std::cout << "Folge: ";
    for (auto element : folge) {
      std::cout << element << " ";
    }
    std::cout << '\n';
  }

private:
  std::vector<int> folge;
};
#endif
