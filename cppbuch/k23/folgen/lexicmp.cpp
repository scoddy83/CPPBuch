/* cppbuch/k23/folgen/lexicmp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
using namespace std;

int main() {
  // Anwendung auf char-Array
  char text1[] = "Arthur";
  size_t length1 = sizeof(text1);
  char text2[] = "Vera";
  size_t length2 = sizeof(text2);
  if (lexicographical_compare(text1, text1 + length1, text2,
                              text2 + length2)) {
    cout << text1 << " kommt vor " << text2 << '\n';
  } else {
    cout << text2 << " kommt vor " << text1 << '\n';
  }
  if (lexicographical_compare(text1, text1 + length1, text2, text2 + length2,
                              greater<char>())) {  // umgekehrte Reihenfolge
    cout << text1 << "  kommt nach " << text2 << '\n';
  } else {
    cout << text2 << "  kommt nach " << text1 << '\n';
  }
  // Anwendung auf string
  string s1("Annabell");
  string s2("Francesco");
  if (lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end())) {
    cout << s1 << " kommt vor " << s2 << '\n';
  } else {
    cout << s2 << " kommt vor " << s1 << '\n';
  }
}
