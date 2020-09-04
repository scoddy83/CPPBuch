/* cppbuch/k23/array2d/array2d.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// 2-dim. Array-Klasse mit zusammenhängendem (contiguous) Memory-Bereich,
// nicht mit new, sondern mit vector realisiert
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <algorithm>  // \tt{std::fill\_n()}
#include <cstddef>    // \tt{std::size\_t}
#include <initializer_list>
#include <iostream>
#include <stdexcept>  // \tt{std::range\_error}
#include <utility>    // \tt{std::swap()}
#include <vector>

template <typename T> 
class Array2d {
public:
  // Typedefs wegen Standard-Konformität
  using value_type = typename std::vector<T>::value_type;
  using reference = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;
  using pointer = typename std::vector<T>::pointer;
  using const_pointer = typename std::vector<T>::const_pointer;
  using difference_type = typename std::vector<T>::difference_type;
  using size_type = typename std::vector<T>::size_type;

  // Konstruktoren
  Array2d(std::size_t z, std::size_t s, const T& wert = T())
      : zeilen{z}, spalten{s}, arr{std::vector<T>(z * s, wert)} {}

  Array2d(std::size_t z, std::size_t s, const T* array)
      : zeilen{z}, spalten{s}, arr{std::vector<T>(array, array + z * s)} {}

  // Sequenzkonstruktor (siehe Seite \pageref{Sequenzkonstruktor} und Text)
  Array2d(std::initializer_list<std::initializer_list<T>> liste)
      : Array2d(liste.size(), liste.begin()->size()) {
    std::size_t index = 0;
    for (const auto& zeileninitialisierer : liste) {
      for (auto element : zeileninitialisierer) {
        arr[index++] = element;
      }
    }
  }

  // andere Elementfunktionen
  std::size_t getZeilen() const { return zeilen; }
  std::size_t getSpalten() const { return spalten; }

  void init(const T& wert) {  // Alle Elemente mit wert initialisieren
    std::fill(arr.begin(), arr.end(), wert);
  }

  // Elementzugriff
  void checkIndizes(std::size_t z, std::size_t s) const {
    if (z >= zeilen) {
      throw std::range_error("Array2d: Zeilenindex zu groß");
    }
    if (s >= spalten) {
      throw std::range_error("Array2d: Spaltenindex zu groß");
    }
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

  const T* data() const { return arr.data(); }

  // STL-entsprechende Funktionen
  size_type size() const { return arr.size(); }
  iterator begin() { return arr.begin(); }
  iterator end() { return arr.end(); }
  const_iterator begin() const { return arr.cbegin(); }
  const_iterator end() const { return arr.cend(); }
  const_iterator cbegin() const { return arr.cbegin(); }
  const_iterator cend() const { return arr.cend(); }
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
  std::vector<T> arr;
};

// relationale Operatoren
template <typename T> bool operator==(const Array2d<T>& a, const Array2d<T>& b) {
  if (a.getZeilen() != b.getZeilen()) {
    return false;
  } else if (a.getSpalten() != b.getSpalten()) {
    return false;
  }
  return std::equal(a.begin(), a.end(), b.begin());
}

template <typename T> bool operator<(const Array2d<T>& a, const Array2d<T>& b) {
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
