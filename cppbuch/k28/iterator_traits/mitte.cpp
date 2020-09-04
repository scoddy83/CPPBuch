/* cppbuch/k28/iterator_traits/mitte.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <class Iterator>                    // erste überladene Funktion
int holeMittleres(Iterator anfang, std::size_t n,
                  std::bidirectional_iterator_tag) {
  for (std::size_t i = 0; i < n / 2; ++i) {  // bis zur Mitte laufen
    ++anfang;
  }
  return *anfang;
}
// Der bidirektionale Iterator lässt keine wahlfreien Zugriffe und damit
// keine Iteratorarithmetik zu. Zur Bewegung sind nur die Operatoren
// \tt{++}  und \tt{-\relax-} erlaubt. Ein Random-Access-Iterator erlaubt Arithmetik, 
// sodass die Implementation für diesen Fall etwas einfacher ist:
template <class Iterator>
int holeMittleres(Iterator anfang,
                  std::size_t n,            // zweite überladene Funktion
                  std::random_access_iterator_tag) {
  return *(anfang + n / 2);                 // Arithmetik
}

// Aufrufende Funktion.
// Diese Funktion ruft nun die korrespondierende überladene Variante auf,
// wobei die Auswahl zur Compilierzeit durch den Parameter \tt{kategorie} geschieht.
template <class Iterator>
int mittleresElement(Iterator anfang,
                     std::size_t n) {       // aufrufende Funktion
  typename std::iterator_traits<Iterator>::iterator_category kategorie;
  return holeMittleres(anfang, n, kategorie);
}

int main() {                                           // Hauptprogramm
  std::list<int> liste{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // \tt{list}
  std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // \tt{vector}

  // Aufruf der ersten Implementierung für die Liste
  std::cout << mittleresElement(liste.begin(), liste.size()) << '\n';

  // Aufruf der zweiten Implementierung für den Vektor
  std::cout << mittleresElement(vec.begin(), vec.size()) << '\n';
}
