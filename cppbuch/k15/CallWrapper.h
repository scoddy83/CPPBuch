/* cppbuch/k15/CallWrapper.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef CALLWRAPPER_H
#define CALLWRAPPER_H
// einführende Alternative zu reference_wrapper, siehe Text
template <class Callee> class CallWrapper {
public:
  CallWrapper(Callee& c) : callee(c) {}

  void operator()() { callee(); }

private:
  Callee& callee;
};
#endif
