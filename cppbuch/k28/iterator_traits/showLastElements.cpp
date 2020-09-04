/* cppbuch/k28/iterator_traits/showLastElements.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// Erste überladene Funktion
template <class Iterator, class Distance>
void showLastElementsImpl(Iterator last, Distance n,
                          std::bidirectional_iterator_tag) {
  Iterator temp = last;
  std::advance(temp, -n);
  while (temp != last) {
    std::cout << *temp++ << ' ';
  }
  std::cout << '\n';
}
/* Ein bidirektionaler Iterator erlaubt keinen wahlfreien Zugriff
(random
access) und daher keine Iterator-Arithmetik. Nur die Operatoren
++ und -- sind für die Bewegung möglich. Deshalb wird  advance()
benutzt, um n Schritte zurückzugehen und dann die restlichen
Elemente anzuzeigen. Ein Random-Access-Iterator erlaubt
Arithmetik, was die Implementierung dieses Falles ein wenig leichter
macht: */

// Zweite überladene Funktion
template <class Iterator, class Distance>
void showLastElementsImpl(Iterator last, Distance n,
                          std::random_access_iterator_tag) {
  Iterator first = last - n;  // Arithmetik
  while (first != last) {
    std::cout << *first++ << ' ';
  }
  std::cout << '\n';
}

/*  Diese Funktion ruft eine überladene Variante, wobei die Auswahl,
welche der überladenen Variante genommen wird, zur Compilierzeit
durch den Parameter iterator_category() bestimmt wird, dessen Typ
mit einem Iterator-Tag korrespondiert. Der dritte Parameter ist
ein Iterator-Tag-Objekt, konstruiert durch seinen Standard-
Konstruktor.
*/
// aufrufende Funktion
template <class Iterator>
void showLastElements(
    Iterator last,
    typename std::iterator_traits<Iterator>::difference_type n) {
  typename std::iterator_traits<Iterator>::iterator_category typeobject;
  showLastElementsImpl(last, n, typeobject);
}

int main() {
  std::list<int> liste{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // list

  // Aufruf der 1. überladenen Funktion
  showLastElements(liste.end(), 5);

  std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // vector

  // Aufruf der 2. überladenen Funktion
  showLastElements(v.end(), 5);
}
