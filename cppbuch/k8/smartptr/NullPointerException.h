/* cppbuch/k8/smartptr/NullPointerException.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef NULLPOINTEREXCEPTION_H
#define NULLPOINTEREXCEPTION_H
#include <stdexcept>

class NullPointerException : public std::runtime_error {
public:
  NullPointerException() : std::runtime_error("NullPointerException!") {}
};

#endif
