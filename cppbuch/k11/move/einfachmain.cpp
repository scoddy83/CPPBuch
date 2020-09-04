/* cppbuch/k11/move/einfachmain.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "einfacherstring.h"
#include <iostream>
using namespace std;

int main() {
  StringTyp a("einA");
  StringTyp b("einB");
  StringTyp c("einC");
  cout << " Fall 1 : a = \"Hallo\" + b;\n";
  a = "Hallo" + b;

  cout << "\n Fall 2 :  a = b + \" hallo\";\n";
  a = b + " hallo";

  cout << "\n Fall 3 : a = StringTyp(\"guten\") + \" Tag\";\n";
  a = StringTyp("guten") + " Tag";

  cout << "\n Fall 4 : a = b + c;\n";
  a = b + c;

  cout << "\n Fall 5 : StringTyp neu = b + c;\n";
  StringTyp neu = b + c;

  cout << "\n Fall 6 :  neu = a + \"eins\" + \"zwei\" + \"drei\";\n";
  neu = a + "eins" + "zwei" + "drei";

  cout << "\na  = " << a;
  cout << "\nb  = " << b;
  cout << "\nc  = " << c;
  cout << "\nneu= " << neu;

  cout << "\n\n Fall 7 : neu = a + b + c + neu;\n";
  neu = a + b + c + neu;
  cout << "\na  = " << a;
  cout << "\nb  = " << b;
  cout << "\nc  = " << c;
  cout << "\nneu= " << neu << '\n';
}
