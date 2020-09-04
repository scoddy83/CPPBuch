/* cppbuch/k8/smartptr/smartptr.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef SMARTPTR_T
#define SMARTPTR_T
#include "NullPointerException.h"

template <typename T> class SmartPointer {
public:
  SmartPointer(T* p = nullptr);
  ~SmartPointer();  // nicht virtual: Vererbung ist nicht geplant
  T* operator->() const;
  T& operator*() const;
  explicit operator bool() const;

private:
  T* zeigerAufObjekt;
  void check() const;  // Prüfung auf nicht-Null
  // Ergänzung siehe Text
  void operator=(const SmartPointer&) = delete;  // Zuweisung verbieten
  // Initialisierung mit \tt{SmartPointer} verbieten:
  SmartPointer(const SmartPointer&) = delete;
};

template <typename T>
SmartPointer<T>::SmartPointer(T* p) : zeigerAufObjekt{p} {}

template <typename T> void SmartPointer<T>::check() const {
  if (!zeigerAufObjekt) {
    throw NullPointerException();
  }
}

template <typename T> SmartPointer<T>::~SmartPointer() {
  delete zeigerAufObjekt;
}

template <typename T> T* SmartPointer<T>::operator->() const {
  check();
  return zeigerAufObjekt;
}

template <typename T> T& SmartPointer<T>::operator*() const {
  check();
  return *zeigerAufObjekt;
}

template <typename T> SmartPointer<T>::operator bool() const {
  return bool(zeigerAufObjekt);
}

#endif  // SMARTPTR_T
