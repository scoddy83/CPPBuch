/* cppbuch/include/Random.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RANDOM_H
#define RANDOM_H
#include <cstddef>
#include <limits>
#include <random>

class Random {
public:
  explicit Random(int min, int max) : verteilung(min, max) {}
  explicit Random(int max = std::numeric_limits<int>::max())
      : verteilung(0, max) {}
  void setSeed(std::size_t newseed) { generator.seed(newseed); }
  // gibt eine Pseudo-Zufallszahl zwischen min und max zurück
  int operator()() { return verteilung(generator); }

private:
  std::mt19937 generator;
  std::uniform_int_distribution<>
      verteilung;  // \tt{<>}: Vorgabe ist \tt{int}
};

#endif
