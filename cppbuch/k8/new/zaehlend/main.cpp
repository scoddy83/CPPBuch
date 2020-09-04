/* cppbuch/k8/new/zaehlend/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"
using namespace std;

int main() {
  Person person("Lena");
  cout << "Name : " << person.getName() << '\n';
  ZaehlendesObjekt::status();
  Person* ptr1{new Person("Jens")};
  cout << "Name : " << ptr1->getName() << '\n';
  ZaehlendesObjekt::status();
  delete ptr1;
  ZaehlendesObjekt::status();
}
