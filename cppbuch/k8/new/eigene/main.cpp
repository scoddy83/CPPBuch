/* cppbuch/k8/new/eigene/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Person.h"
using std::cout;

int main() {
  Person person("Lena");  // Stack-Objekt
  cout << "Name : " << person.getName() << '\n';
  Person* pJens = new Person("Jens");  // Heap-Objekt
  cout << "Name : " << pJens->getName() << '\n';
  delete pJens;  // Löschen des Heap-Objekts
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  Person* pOtto = new Person("Otto");  // Heap-Objekt
  cout << "Name : " << pOtto->getName() << '\n';
  delete pOtto;  // Löschen des Heap-Objekts
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  Person* pAnne = new Person("Anne");
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  Person* pBerta = new Person("Berta");
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  Person* pDoro = new Person("Doro von und zu Wachau");
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  delete pBerta;
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  Person* pErna = new Person("Erna");
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  cout << "Name : " << pDoro->getName() << '\n';
  cout << "Name : " << pErna->getName() << '\n';
  delete pAnne;
  delete pDoro;
  delete pErna;
  cout << "freie Plaetze : " << Person::freiePlaetze() << '\n';
  cout << "Testausgabe mit der Variablen test in Person.h "
          "steuern.\n";
}
