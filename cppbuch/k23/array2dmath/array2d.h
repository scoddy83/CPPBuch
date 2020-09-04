/* cppbuch/k23/array2dmath/array2d.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
// 2-dim. Array-Klasse mit zusammenhängendem (contiguous)
// Memory-Bereich,
// nicht mit new, sondern mit vector realisiert
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <algorithm>  // \tt{std::fill\_n()}
#include <cstddef>    // \tt{std::size\_t}
#include <initializer_list>
#include <iostream>
#include <numeric>
#include <stdexcept>  // \tt{std::range\_error}
#include <tuple>
#include <utility>  // \tt{std::swap()}
#include <vector>
// ggf. hier oder in main.cpp einschalten
//#define TESTARRAY2D

#ifdef TESTARRAY2D
#define TESTAUSGABE(x) std::cout << #x << std::endl
#else
#define TESTAUSGABE(x) /* nichts */
#endif

template <typename T> class Array2d;

template <typename T> 
struct Summand {
  Summand(T faktor, const Array2d<T>& arr) : f{faktor}, a(arr) {
    TESTAUSGABE(Summand(T faktor, const Array2d<T>& arr));
  }
  Summand(const Array2d<T>& arr) : Summand(T(1), arr) {
    TESTAUSGABE(Summand(const Array2d<T>& arr));
  }
  T getWert(std::size_t index) const { return *(a.data() + index) * f; }
  auto getZeilen() const { return a.getZeilen(); }
  auto getSpalten() const { return a.getSpalten(); }
  Summand<T>& operator*=(T faktor) {
    f *= faktor;
    return *this;
  }
  T f;
  const Array2d<T>& a;
};

////////// Berechnung über alle Summanden
template <std::size_t N, typename T, typename... Args> 
struct Summe {
  static T ergebnis(std::size_t index, const std::tuple<Args...>& t) {
    if constexpr(N > 1) {
        return std::get<N - 1>(t).getWert(index) +
              Summe<N - 1, T, Args...>::ergebnis(index, t);
    }
    else {
      return std::get<0>(t).getWert(index);
    }
  }
};

namespace {
template <typename T>  // Hilfsfunktion zur Multiplikation
void matMult(Array2d<T>& erg, const Array2d<T>& x, const Array2d<T>& y) {
  if (x.getSpalten() != y.getZeilen()) {
    throw std::range_error("Array2d-Multiplikation:: falsche Zeilen-/Spaltenanzahl");
  }
  Array2d<T> trans(y.transpose());
  for (std::size_t i = 0; i < erg.getZeilen(); ++i) {
    auto anfangZeile_i = x.begin() + i * x.getSpalten();
    auto endeZeile_i = anfangZeile_i + x.getSpalten();
    for (std::size_t j = 0; j < erg.getSpalten(); ++j) {
      auto anfangSpalte_j = trans.begin() + j * trans.getSpalten();
      erg[i][j] =
          std::inner_product(anfangZeile_i, endeZeile_i, anfangSpalte_j, T(0));
    }
  }
}
  /* alternativ:
template <typename T> 
void matMult1(Array2d<T>& erg, const Array2d<T>& x, const Array2d<T>& y) {
  if (x.getSpalten() != y.getZeilen()) {
    throw std::range_error("Array2d-Multiplikation:: falsche Zeilen-/Spaltenanzahl");
  }
  // Reihenfolge ikj ist die beste bzgl. Cacheverhalten
  erg.init(0); 
  for(auto i = 0u; i < erg.getZeilen(); ++i) {
    for(auto k = 0u; k < y.getZeilen(); ++k) {
      for(auto j = 0u; j < y.getSpalten(); ++j) {
        erg[i][j] += x[i][k] * y[k][j];
      }
    }
  }
}
  */
}

template <typename T> class Array2d {
public:
  // Typedefs wegen Standard-Konformität
  using value_typ = typename std::vector<T>::value_type;
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

  // Sequenzkonstruktor (siehe Seite \pageref{Sequenzkonstruktor} und Text )
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
    if (z >= zeilen)
      throw std::range_error("Array2d: Zeile ausserhalb des erlaubten Bereichs");
    if (s >= spalten)
      throw std::range_error("Array2d: Spalte ausserhalb des erlaubten Bereichs");
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

  // mathematische Operatoren + Zubehör
  void checkDimension(const Array2d& a) const {
    if (zeilen != a.zeilen || spalten != a.spalten)
      throw std::range_error("Array2d: ungleiche Zeilen-/Spaltenanzahl");
  }

  /////////  mathematische Operatoren und zugehörige Methoden //////////////

  //////////    unäres plus/minus  //////////////
  Array2d& operator+() { return *this; }

  Summand<T> operator-() {
    TESTAUSGABE(operator-());
    return Summand<T>(T(-1), *this);
  }
  //////////    binäre Kurzform-Operatoren  //////////////
  Array2d& operator*=(const Array2d& a) {
    TESTAUSGABE(operator*=(const Array2d<T>& a));
    checkDimension(a);
    // *this ist selbst Argument, temporärer Zwischenspeicher notwendig
    Array2d<T> tmp(*this);
    matMult(*this, tmp, a);
    return *this;
  }

  Array2d& operator*=(T wert) {
    TESTAUSGABE(operator*=(T wert));
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] *= wert;
    }
    return *this;
  }

  //////////     +=   //////////////
  Array2d& operator+=(const Summand<T>& o) {
    TESTAUSGABE(operator+=(const Summand<T>& o));
    checkDimension(o.a);
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] += o.getWert(i);
    }
    return *this;
  }

  Array2d& operator+=(const Array2d& a) {
    TESTAUSGABE(operator+=(const Array2d<T>& a));
    return operator*=(Summand<T>(a));
  }

  //////////     -=   //////////////
  Array2d& operator-=(const Summand<T>& o) {
    TESTAUSGABE(operator-=(const Summand<T>& a));
    checkDimension(o.a);
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] -= o.getWert(i);
    }
    return *this;
  }
  Array2d& operator-=(const Array2d& a) {
    TESTAUSGABE(operator-=(const Array2d<T>& a));
    return operator*=(Summand<T>(-1, a));
  }

  //////////    Zuweisungsoperatoren für Hilfsklassen //////////////
  template <typename... Args> 
  Array2d& operator=(const std::tuple<Args...>& t) {
    TESTAUSGABE(operator=(std::tuple));
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] = Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
    }
    return *this;
  }

  template <typename... Args>
  Array2d& operator+=(const std::tuple<Args...>& t) {
    TESTAUSGABE(operator+=(std::tuple));
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] += Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
    }
    return *this;
  }
  template <typename... Args>
  Array2d& operator-=(const std::tuple<Args...>& t) {
    TESTAUSGABE(operator+=(std::tuple));
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] -= Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
    }
    return *this;
  }

  //////////    Konstruktor für Hilfsklasse  //////////////
  template <typename... Args>
  Array2d(const std::tuple<Args...>& t) 
    : zeilen(0), spalten(0), arr(0) {
    TESTAUSGABE(Array2d(std::tuple));
    Array2d temp(std::get<0>(t).getZeilen(), std::get<0>(t).getSpalten());
    for (std::size_t i = 0; i < temp.size(); ++i) {
      temp.arr[i] = Summe<sizeof...(Args), T, Args...>::ergebnis(i, t);
    }
    swap(temp);
  }

  Array2d(const Summand<T>& op)
      : zeilen(op.getZeilen()), spalten(op.getSpalten()), arr(zeilen * spalten) {
    TESTAUSGABE(Array2d(const Summand&));
    for (std::size_t i = 0; i < size(); ++i) {
      arr[i] = op.getWert(i);
    }
  }

  auto transpose() const {  // transponierte Matrix erzeugen
    Array2d<T> temp(spalten, zeilen);
    for (std::size_t z = 0; z < temp.getZeilen(); ++z) {
      for (std::size_t s = 0; s < temp.getSpalten(); ++s) {
        temp[z][s] = (*this)[s][z];
      }
    }
    return temp;
  }

private:
  std::size_t zeilen;
  std::size_t spalten;
  std::vector<T> arr;
};

// relationale Operatoren
template <typename T>
bool operator==(const Array2d<T>& a, const Array2d<T>& b) {
  if (a.getZeilen() != b.getZeilen()) {
    return false;
  } else  if (a.getSpalten() != b.getSpalten()) {
    return false;
  }
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

/////////  globale mathematische Operatoren ///////////

//////////    mult  //////////////
template <typename T>
auto operator*(const Array2d<T>& x, const Array2d<T>& y) {
  TESTAUSGABE(operator*(const Array2d<T>&, const Array2d<T>&));
  // temporärer Zwischenspeicher notwendig, weil das Ergebnis einem Objekt
  // zugewiesen wird, das selbst an den Berechnungen beteiligt sein kann
  Array2d<T> tmp(x.getZeilen(), y.getSpalten());
  matMult(tmp, x, y);
  return tmp;
}

template <typename T>
auto operator*(const Summand<T>& s, const Array2d<T>& a2) {
  TESTAUSGABE(operator*(const Summand<T>&, const Array2d<T>&));
  // temporärer Zwischenspeicher notwendig, weil das Ergebnis einem Objekt
  // zugewiesen wird, das selbst an den Berechnungen beteiligt sein kann
  const Array2d<T>& a1 = s.a;
  Array2d<T> tmp(a1.getZeilen(), a2.getSpalten());
  matMult(tmp, a1, a2);
  return s.f * tmp;
}
template <typename T, typename... Args>
auto operator*(const Summand<T>& s, std::tuple<Args...> t) {
  TESTAUSGABE(operator*(const Summand<T>&, std::tuple<Args...> t));
  return s * Array2d<T>(t);
}

template <typename T> 
auto operator*(const T& f, const Array2d<T>& x) {
  TESTAUSGABE(operator*(T, const Array2d<T>&));
  return Summand<T>(f, x);
}

template <typename T> 
auto operator*(const Array2d<T>& x, T f) {
  TESTAUSGABE(operator*(const Array2d<T>&, T));
  return Summand<T>(f, x);
}

template <typename T> 
Summand<T> operator*(Summand<T> x, T f) {
  TESTAUSGABE(operator*(const Summand<T>&, T));
  return x *= f;
}

template <typename T>
Summand<T> operator*(T f, Summand<T> x) {
  TESTAUSGABE(operator*(T, const Summand<T>&));
  return x *= f;
}

// arr0*(arr1 + arr2 + arr3 + ...) und (arr1 + arr2 +...)*arr0
template <typename T, typename... Args>
auto operator*(const Array2d<T>& array, std::tuple<Args...> t) {
  TESTAUSGABE(operator*(const Array2d<T>& array, std::tuple<Args...> t));
  return array * Array2d<T>(t);
}
template <typename T, typename... Args>
auto operator*(std::tuple<Args...> t, const Array2d<T>& array) {
  TESTAUSGABE(operator*(std::tuple<Args...> t, const Array2d<T>& array));
  return Array2d<T>(t) * array;
}
// Ende: arr0*(arr1 + arr2 + arr3 + ...) und (arr1 + arr2 +...)*arr0

// (arr1+arr2+...) * ( arrx + arry + ..)
// Damit T  aus den Argumenten ableitbar ist, wird Summand<T> bei Args1 eingefuegt
template <typename T, typename... Args1, typename... Args2>
auto operator*(const std::tuple<Summand<T>, Args1...>& t1,
                      const std::tuple<Args2...>& t2) {
  TESTAUSGABE(operator*(std::tuple<Summand<T>, Args1...> t1, std::tuple<Args2...> t2));
  return Array2d<T>(t1) * Array2d<T>(t2);
}
// Ende: (arr1+arr2+...) * ( arrx + arry + ..)

// zahl*(arr1 + arr2 + arr3 + ...) und (arr1 + arr2 +...)*zahl
template <std::size_t N, typename T, typename... Args> 
struct MultFaktorTupel {
  static void multipliziere(T faktor, std::tuple<Args...>& t) {
    std::get<N - 1>(t) *= faktor;
    if constexpr (N > 1) {
        MultFaktorTupel<N - 1, T, Args...>::multipliziere(faktor, t);
      }
  }
};

template <typename T, typename... Args>
auto operator*(T f, std::tuple<Args...> t) {
  TESTAUSGABE(operator*(T f, std::tuple<Args...> t));
  // Alle Summanden mit f multiplizieren und Tupel zurückgeben
  MultFaktorTupel<sizeof...(Args), T, Args...>::multipliziere(f, t);
  return t;
}

template <typename T, typename... Args>
auto operator*(std::tuple<Args...> t, T f) {
  TESTAUSGABE(operator*(std::tuple<Args...> t, T f));
  return f * t;
}
// ENDE: zahl*(arr1 + arr2 + arr3 + ...) und (arr1 + arr2 +...)*zahl

//////////    plus  //////////////
template <typename T>
auto operator+(const Summand<T>& x, const Summand<T>& y) {
  x.a.checkDimension(y.a);
  TESTAUSGABE(operator+(const Summand<T>&, const Summand<T>&));
  return std::tuple<Summand<T>, Summand<T>>(x, y);
}
template <typename T>
auto operator+(const Summand<T>& x, const Array2d<T>& y) {
  TESTAUSGABE(operator+(const Summand<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(x, Summand<T>(y));
}
template <typename T>
auto operator+(const Array2d<T>& x, const Summand<T>& y) {
  TESTAUSGABE(operator+(const Summand<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(Summand<T>(x), y);
}
template <typename T>
auto operator+(const Array2d<T>& x, const Array2d<T>& y) {
  TESTAUSGABE(operator+(const Array2d<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(Summand<T>(x), Summand<T>(y));
}

template <typename T, typename... Args>
auto operator+(const std::tuple<Args...>& t, const Summand<T>& y) {
  TESTAUSGABE(operator+(const tupel<Args...>& t, const Summand<T>&));
  return std::tuple_cat(std::tuple<Summand<T>>(y), t);
}

template <typename T, typename... Args>
auto operator+(const Summand<T>& y, const std::tuple<Args...>& t) {
  TESTAUSGABE(operator+(const Summand<T>&, const tupel<Args...>& t));
  return std::tuple_cat(std::tuple<Summand<T>>(y), t);
}

template <typename T, typename... Args>
auto operator+(const std::tuple<Args...>& t, const Array2d<T>& y) {
  TESTAUSGABE(operator+(const tupel<Args...>& t, const Array2d<T>&));
  return t + Summand<T>(y);
}

// (arr1+arr2+...) + ( arrx + arry + ..)
// Damit T  aus den Argumenten ableitbar ist, wird Summand<T> bei Args1 eingefuegt
template <typename T, typename... Args1, typename... Args2>
auto operator+(const std::tuple<Summand<T>, Args1...>& t1,
                      const std::tuple<Args2...>& t2) {
  TESTAUSGABE(operator+(std::tuple<Summand<T>, Args1...> t1,
                        std::tuple<Args2...> t2));
  return std::tuple_cat(t1, t2);
}

//////////    minus  /////////////
template <typename T>
auto operator-(const Summand<T>& x, const Summand<T>& y) {
  x.a.checkDimension(y.a);
  TESTAUSGABE(operator-(const Summand<T>&, const Summand<T>&));
  return std::tuple<Summand<T>, Summand<T>>(x, y);
}
template <typename T>
auto operator-(const Summand<T>& x, const Array2d<T>& y) {
  TESTAUSGABE(operator-(const Summand<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(x, Summand<T>(-1, y));
}
template <typename T>
auto operator-(const Array2d<T>& x, const Summand<T>& y) {
  TESTAUSGABE(operator-(const Summand<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(Summand<T>(x), y);
}
template <typename T>
auto operator-(const Array2d<T>& x, const Array2d<T>& y) {
  TESTAUSGABE(operator-(const Array2d<T>&, const Array2d<T>&));
  return std::tuple<Summand<T>, Summand<T>>(Summand<T>(x), Summand<T>(-1, y));
}

template <typename T, typename... Args>
auto operator-(const std::tuple<Args...>& t, Summand<T>&& y) {
  TESTAUSGABE(operator-(const tupel<Args...>& t, const Summand<T>&));
  y.mult(-1);
  return std::tuple_cat(std::tuple<Summand<T>>(y), t);
}

template <typename T, typename... Args>
auto operator-(const std::tuple<Args...>& t, const Array2d<T>& a) {
  TESTAUSGABE(operator-(const tupel<Args...>& t, const Array2d<T>&));
  return t + Summand<T>(-1, a);
}

// (arr1+arr2+...) - ( arrx + arry + ..)
// Damit T  aus den Argumenten ableitbar ist, wird Summand<T> bei Args1 eingefuegt
template <typename T, typename... Args1, typename... Args2>
auto operator-(const std::tuple<Summand<T>, Args1...>& t1,
                      const std::tuple<Args2...>& t2) {
  TESTAUSGABE(operator-(std::tuple<Summand<T>, Args1...> t1,
                        std::tuple<Args2...> t2));
  auto t3 = static_cast<T>(-1) * t2;
  return std::tuple_cat(t1, t3);
}

#endif
