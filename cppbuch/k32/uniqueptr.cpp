/* cppbuch/k32/uniqueptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Ressource.h"
#include <memory>
using namespace std;

int main() {
  cout << "Zeiger auf dynamisches Objekt:\n";
  unique_ptr<Ressource> p1(new Ressource(1));
  cout << "Operator ->  ";
  p1->hi();
  cout << "Operator *   ";
  (*p1).hi();
  //  Null-Zeiger
  unique_ptr<Ressource> nullp(nullptr);
  // nullp->hi();   // Speicherzugriffsfehler!
  cout << "release()\n";
  // p1.release();  // verhindert Destruktor-Aufruf
  p1.reset(nullptr);  //  Destruktor-Aufruf ok
  cout << "Ende von main()\n";
  // unique_ptr transfer
  unique_ptr<Ressource> uniqueptr1(new Ressource(2));
  unique_ptr<Ressource> uniqueptr2(uniqueptr1.release());
  // Jetzt gehört uniqueptr2 das Objekt
}
