/* cppbuch/k11/RVO/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "einfacherstring.h"
#include <iostream>
using namespace std;

int main() {
  StringTyp str1("Erster");
  StringTyp str2("Zweiter");
  cout << "Fall1: erg1(str1 + str2);\n";
  StringTyp erg1(str1 + str2);
  cout << "\nFall 2: erg2(StringTyp(\"Temporär\") + str2);\n";
  StringTyp erg2(StringTyp("Temporär") + str2);
  cout << "\nFall 3: Zuweisung ergstr = str1 + str2;\n";
  StringTyp ergstr("");
  ergstr = str1 + str2;
}
