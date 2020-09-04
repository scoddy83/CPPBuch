/* cppbuch/k8/new/waechter/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"

int main() {
  Person person("Lena");
  std::cout << "Name : " << person.getName() << '\n';
  ZaehlendesObjekt::status();
  Person* ptr1 = new Person("Jens");
  std::cout << "Name : " << ptr1->getName() << '\n';
  ZaehlendesObjekt::status();
  delete ptr1;   // auskommentieren, um Fehlermeldung zu erhalten
  ZaehlendesObjekt::status();
}
