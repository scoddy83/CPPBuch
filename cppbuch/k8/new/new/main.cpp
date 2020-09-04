/* cppbuch/k8/new/new/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"

int main() {
  Person person("Lena");  // Stack-Objekt
  std::cout << "Name : " << person.getName() << '\n';
  Person* ptr1{new Person("Jens")};  // Heap-Objekt
  std::cout << "Name : " << ptr1->getName() << '\n';
  delete ptr1;  // Löschen des Heap-Objekts

  constexpr size_t anz{2};
  Person* arr{new Person[anz]};  // dynamisches Array anlegen
  for (size_t i = 0; i < anz; ++i) {
    std::cout << i << ": " << arr[i].getName() << '\n';
  }
  delete[] arr;  // dynamisches Array löschen
}  // Destruktor-Aufruf des Stack-Objekts
