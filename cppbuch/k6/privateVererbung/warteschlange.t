/* cppbuch/k6/privateVererbung/warteschlange.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WARTESCHLANGE_T
#define WARTESCHLANGE_T
#include <list>

template <typename T>
class Warteschlange : private std::list<T> {  // mit privater Vererbung
  // (Implementationsvererbung)
public:
  using std::list<T>::empty;
  using std::list<T>::size;
  void push(const T& x) { std::list<T>::push_back(x); }  // am Ende einfügen
  void pop() { std::list<T>::pop_front(); }  // am Anfang entnehmen
  using std::list<T>::front;                 // am Anfang lesen
  using std::list<T>::back;                  // am Ende lesen
};
#endif
