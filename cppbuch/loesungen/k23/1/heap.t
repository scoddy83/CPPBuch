/* cppbuch/loesungen/k23/1/heap.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef HEAP_T
#define HEAP_T
#include <algorithm>
#include <cstddef>
#include <functional>
#include <vector>

#define TESTHEAP
// siehe unten
template <class T, class Compare = std::less<T>> class Heap {
public:
  Heap(const Compare& cmp = Compare())
      : anz(0), comp(cmp), v(std::vector<T>(1)), last(v.begin()) {}
  void push(const T& t) {
    if (anz == v.size()) {
      v.resize(anz + 100);
      last = v.begin() + anz;  // neu bestimmen
    }
    *last = t;
    push_heap(v.begin(), ++last, comp);
    ++anz;
#ifdef TESTHEAP
    if (!is_heap(v.begin(), last)) {
      throw "push(): Heap-Bedingung verletzt!";
    }
#endif
  }
  void pop() {
    pop_heap(v.begin(), last--, comp);
    --anz;
#ifdef TESTHEAP
    if (!is_heap(v.begin(), last)) {
      throw "pop(): Heap-Bedingung verletzt!";
    }
#endif
  }
  const T& top() const { return *v.begin(); }
  bool empty() const { return anz == 0; }
  std::size_t size() const { return anz; }
  std::vector<T> toSortedVector() const {
    std::vector<T> temp(v.begin(), v.begin() + anz);
    sort_heap(temp.begin(), temp.end(), comp);
    return temp;
  }

private:
  std::size_t anz;
  Compare comp;
  std::vector<T> v;
  typename std::vector<T>::iterator last;
};
#endif
