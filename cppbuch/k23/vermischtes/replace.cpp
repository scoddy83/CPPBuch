/* cppbuch/k23/vermischtes/replace.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <showContainer.h>
#include <string>
#include <vector>

struct Zitrusfrucht {
  bool
  operator()(const std::string& a) const {  // unäres Prädikat als Funktor
    return a == "Zitrone" || a == "Apfelsine" || a == "Limone";
  }
};

using namespace std;

int main() {
  vector<string> obstkorb{"Apfel", "Apfelsine", "Zitrone"};
  showContainer(obstkorb);  // Apfel Apfelsine Zitrone

  cout << "replace: Apfel durch Quitte ersetzen:\n";
  replace(obstkorb.begin(), obstkorb.end(), string("Apfel"),
          string("Quitte"));
  showContainer(obstkorb);  // Quitte Apfelsine Zitrone

  cout << "replace_if: Zitrusfrüchte durch Pflaumen ersetzen:\n";
  replace_if(obstkorb.begin(), obstkorb.end(), Zitrusfrucht(),
             string("Pflaume"));
  showContainer(obstkorb);  // Quitte Pflaume Pflaume

  cout << "replace_copy: kopieren und ersetzen der Pflaumen durch "
          "Limonen:\n";
  vector<string> kiste(obstkorb.size());
  replace_copy(obstkorb.begin(), obstkorb.end(), kiste.begin(),
               string("Pflaume"), string("Limone"));
  showContainer(kiste);  // Quitte Limone Limone

  cout << "replace_copy_if: kopieren und ersetzen der Zitrusfrüchte "
          "durch Tomaten:\n";
  replace_copy_if(kiste.begin(), kiste.end(), obstkorb.begin(),
                  Zitrusfrucht(), string("Tomate"));
  showContainer(obstkorb);  // Quitte Tomate Tomate
}
