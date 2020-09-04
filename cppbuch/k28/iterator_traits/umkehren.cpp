/* cppbuch/k28/iterator_traits/umkehren.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iterator>
#include <list>
#include <showContainer.h>
#include <vector>
// Bestimmung von Wert- und Distanz-Typ

template <class BidirectionalIterator>
void reverseIt(BidirectionalIterator first, BidirectionalIterator last,
               std::bidirectional_iterator_tag) {
  // difference_type wird zur Berechnung der Anzahl der Vertauschungen
  // verwendet. difference_type wird vom Iteratortyp abgeleitet:
  // typename std::iterator_traits<BidirectionalIterator>::difference_type
  auto n = std::distance(first, last) - 1;

  while (n > 0) {
    // Auch der Werttyp wird vom Iteratortyp abgeleitet:
    // typename std::iterator_traits<BidirectionalIterator>::value_type
    auto temp = *first;
    *first++ = *--last;
    *last = temp;
    n -= 2;
  }
}

/* Die zweite Implementation benutzt Arithmetik, um die Entfernung
 (= Anzahl der Vertauschungen) zu berechnen. Dies geht nur mit
 Random-Access-Iteratoren.
*/
template <class RandomAccessIterator>
void reverseIt(RandomAccessIterator first, RandomAccessIterator last,
               std::random_access_iterator_tag) {
  // difference_type wird zur Berechnung der Anzahl der Vertauschungen
  // verwendet. difference_type wird vom Iteratortyp abgeleitet:
  // auto statt
  // typename std::iterator_traits<RandomAccessIterator>::difference_type
  auto n = last - first - 1;  // Arithmetik!

  while (n > 0) {
    // Auch der Werttyp wird vom Iteratortyp abgeleitet: auto statt
    // typename std::iterator_traits<RandomAccessIterator>::value_type
    auto temp = *first;
    *first++ = *--last;
    *last = temp;
    n -= 2;
  }
}

template <class BidirectionalIterator>
void reverseIt(BidirectionalIterator first, BidirectionalIterator last) {
  typename std::iterator_traits<BidirectionalIterator>::iterator_category
      typeobject;
  /* Die Reihenfole umzudrehen bedeutet, dass ein Element temporär
  gespeichert werden muss. Dazu muss sein Typ bekannt sein. Entsprechend
  dem erprobten Schema ruft die Funktion die für diesen Iteratortyp
  passende Implementation auf:
  */
  reverseIt(first, last, typeobject);
}

int main() {
  std::list<int> liste{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  reverseIt(liste.begin(), liste.end());
  showContainer(liste);

  std::vector<double> vektor{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  reverseIt(vektor.begin(), vektor.end());
  showContainer(vektor);

  // C-Array und Ausnutzung der partiellen Spezialisierung
  // iterator_traits<int*>
  int tabelle[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  reverseIt(std::begin(tabelle), std::end(tabelle));
  // Ausgabe
  std::copy(std::begin(tabelle), std::end(tabelle),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';
}
