/* //CPPBuch/K2/Übung 2.10/gettype.t */
#ifndef GETTYPE_T
#define GETTYPE_T
#include <string>

// Template
template <typename T> // Parametername wird nicht gebraucht
std::string getType(T) { // Parametername wird nicht gebraucht
  return "unbekannter Typ";
}

// Template-Spezialisierungen
template <> std::string getType(int) { return "int"; }
template <> std::string getType(unsigned int) { return "unsigned int"; }
template <> std::string getType(double) { return "double"; }
template <> std::string getType(char) { return "char"; }
template <> std::string getType(bool) { return "bool"; }

#endif
