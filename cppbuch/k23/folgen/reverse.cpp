/* cppbuch/k23/folgen/reverse.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstring>
#include <showContainer.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  char s0[] = "Madam";
  reverse(s0, s0 + strlen(s0));
  cout << s0 << '\n';  //  madaM

  string s1("ABCDEFGH");
  reverse(s1.begin(), s1.end());
  cout << s1 << '\n';  // HGFEDCBA

  vector<string> vs;
  vs.push_back("eins");
  vs.push_back("zwei");
  vs.push_back("drei");
  showContainer(vs);  // eins zwei drei
  vector<string> kopie(vs.size());
  reverse_copy(vs.begin(), vs.end(), kopie.begin());
  showContainer(kopie);  // drei zwei eins
}
