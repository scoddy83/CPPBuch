/* cppbuch/k23/strings/boostsplit.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <boost/algorithm/string/classification.hpp>  // is_any_of
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <showContainer.h>
#include <string>
#include <vector>

int main() {
  std::string text("The quick brown fox jumps over the lazy dog's back.");
  std::vector<std::string> v;
  boost::algorithm::split(v, text, boost::algorithm::is_any_of(" ,."));
  showContainer(v, "", "*\n");
}
