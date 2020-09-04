/* cppbuch/k32/sharedptr.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Ressource.h"
#include <memory>
#include <vector>
using namespace std;

int main() {
  cout << "Zeiger auf dynamische Objekte:\n";
  cout << "Konstruktoraufruf\n";
  shared_ptr<Ressource> p1(new Ressource(1));
  cout << "Operator ->  ";
  p1->hi();
  cout << "Operator *   ";
  (*p1).hi();
  cout << "Benutzungszähler: " << p1.use_count() << '\n';  // 1
  {                                                        // Blockanfang
    // zweiter shared_ptr für dasselbe Objekt
    shared_ptr<Ressource> p2(p1);
    cout << "Benutzungszähler p1: " << p1.use_count() << '\n';  // 2
    cout << "Benutzungszähler p2: " << p2.use_count() << '\n';  // 2
    p2->hi();
  }  // p2 wird zerstört
  cout << "Benutzungszähler p1: " << p1.use_count() << '\n';  // 1
  cout << " Objekt existiert noch: ";
  p1->hi();
  // Zuweisung
  shared_ptr<Ressource> p3(new Ressource(3));
  p3 = p1;  // Ressource 3 wird freigegeben (delete), danach
  // verweisen beide auf das Objekt *p1
  p1->hi();
  p3->hi();
  //  Null-Zeiger
  shared_ptr<Ressource> nullp(nullptr);
  // nullp->hi();   // Speicherzugriffsfehler!
  // STL-Container mit shared_ptr
  vector<shared_ptr<Ressource>> vec(10);
  shared_ptr<Ressource> px(new Ressource(100));
  vec.push_back(px);
  vec[1] = shared_ptr<Ressource>(new Ressource(4));
  vec[1]->hi();
  // make_shared
  auto px1 = make_shared<Ressource>(99);
}
