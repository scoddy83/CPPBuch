/* cppbuch/k23/strings/split.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <showContainer.h>
#include "split.h"

int main() {
  std::string text("The quick brown,fox jumps.over the lazy dog's back.");
  showContainer(split(text, " ,."), "", "*\n");
}
