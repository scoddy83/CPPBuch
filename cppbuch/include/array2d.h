/* cppbuch/include/array2d.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// 2-dim. Array-Klasse mit zusammenhängendem (contiguous)
// Memory-Bereich
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <algorithm>  // \tt{std::copy\_n()},  \tt{std::fill\_n()}
#include <cstddef>
#include <iostream>
#include <stdexcept>  // \tt{std::range\_error}
#include <utility>    // \tt{std::swap()}
// ggf auskommentieren
#define TEST

#ifdef TEST
#define TESTAUSGABE(x) std::cout << #x << std::endl
#else
#define TESTAUSGABE(x) /* nichts */
#endif

template <typename T> class Array2d {
public:
  // Typedefs wegen Standard-Konformität
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using pointer = T*;
  using const_pointer = const T*;
  using difference_type = int;
  using size_type = std::size_t;

  // Konstruktoren, Destruktor, Zuweisung
  Array2d(std::size_t z, std::size_t s)
      : zeilen(z), spalten(s), arr(new T[z * s]) {}
  Array2d(std::size_t z, std::size_t s, const T& wert)
      : zeilen(z), spalten(s), arr(new T[z * s]) {
    init(wert);
  }
  Array2d(std::size_t z, std::size_t s, const T* array)
      : zeilen(z), spalten(s), arr(new T[z * s]) {
    std::copy_n(array, size(), arr);
  }

  Array2d(std::initializer_list<std::initializer_list<T>> liste)
      : zeilen(liste.size()), spalten(liste.begin()->size()),
        arr(new T[zeilen * spalten]) {
    std::size_t index = 0;
    for (const auto& zeileninitialisierer : liste) {
      for (auto element : zeileninitialisierer) {
        arr[index++] = element;
      }
    }
  }

  Array2d(const Array2d& a)
      : zeilen(a.zeilen), spalten(a.spalten), arr(new T[zeilen * spalten]) {
    std::copy_n(a.arr, size(), arr);
    TESTAUSGABE(Array2d(const Array2d<T>& a));
  }
  Array2d(Array2d&& a) : zeilen(0), spalten(0), arr(nullptr) {
    swap(a);
    TESTAUSGABE(Array2d(const Array2d<T>&& a)(move));
  }

  // Destruktor
  ~Array2d() { delete[] arr; }
  // Zuweisungsoperatoren
  Array2d& operator=(const Array2d& a) {
    Array2d temp(a);
    swap(temp);
    TESTAUSGABE(operator=(const Array2d<T>& a));
    return *this;
  }
  Array2d& operator=(Array2d&& a) {
    swap(a);
    TESTAUSGABE(operator=(const Array2d<T>&& a)(move));
    return *this;
  }

  // andere Elementfunktionen
  std::size_t getZeilen() const { return zeilen; }
  std::size_t getSpalten() const { return spalten; }

  void init(const T& wert) {  // Alle Elemente mit wert initialisieren
    std::fill_n(arr, size(), wert);
  }

  // Elementzugriff
  void checkIndizes(std::size_t z, std::size_t s) const {
    if (z >= zeilen)
      throw std::range_error(
          "Array2d: Zeile ausserhalb des erlaubten Bereichs");
    if (s >= spalten)
      throw std::range_error(
          "Array2d: Spalte ausserhalb des erlaubten Bereichs");
  }
  const T& at(std::size_t z, std::size_t s) const {
    checkIndizes(z, s);
    return arr[z * spalten + s];
  }

  T& at(std::size_t z, std::size_t s) {
    checkIndizes(z, s);
    return arr[z * spalten + s];
  }

  const T* operator[](std::size_t z) const { return &arr[z * spalten]; }

  T* operator[](std::size_t z) { return &arr[z * spalten]; }

  const T* data() const { return arr; }

  // STL-entsprechende Funktionen
  std::size_t size() const { return zeilen * spalten; }
  iterator begin() { return arr; }
  iterator end() { return arr + zeilen * spalten; }
  const_iterator begin() const { return arr; }
  const_iterator end() const { return arr + size(); }
  const_iterator cbegin() const { return arr; }
  const_iterator cend() const { return arr + size(); }
  void swap(Array2d& a) {
    std::swap(a.zeilen, zeilen);
    std::swap(a.spalten, spalten);
    std::swap(a.arr, arr);
  }

  void print(std::ostream& ausgabe = std::cout) const {
    for (std::size_t z = 0; z < getZeilen(); ++z) {
      for (std::size_t s = 0; s < getSpalten(); ++s) {
        ausgabe << (*this)[z][s] << " ";
      }
      ausgabe << '\n';
    }
  }

private:
  std::size_t zeilen;
  std::size_t spalten;
  pointer arr;
};

// relationale Operatoren
template <typename T>
bool operator==(const Array2d<T>& a, const Array2d<T>& b) {
  if (a.getZeilen() != b.getZeilen())
    return false;
  if (a.getSpalten() != b.getSpalten())
    return false;
  return std::equal(a.begin(), a.end(), b.begin());
}

template <typename T>
bool operator<(const Array2d<T>& a, const Array2d<T>& b) {
  return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}
// Statt using namespace std::rel_ops :
template <typename T>
bool operator!=(const Array2d<T>& a, const Array2d<T>& b) {
  return !(a == b);
}
template <typename T>
bool operator>(const Array2d<T>& a, const Array2d<T>& b) {
  return b < a;
}
template <typename T>
bool operator<=(const Array2d<T>& a, const Array2d<T>& b) {
  return !(b < a);
}
template <typename T>
bool operator>=(const Array2d<T>& a, const Array2d<T>& b) {
  return !(a < b);
}

#endif
