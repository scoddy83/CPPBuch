/* cppbuch/k28/iterator_traits/ityp.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// Funktions-Template zur Ermittlung der Kategorie des Iterators
template <class Iterator>
typename iterator_traits<Iterator>::iterator_category
getIteratortyp(const Iterator&) {
  typename iterator_traits<Iterator>::iterator_category kategorie;
  return kategorie;
}

// überladene Funktionen
void welcherIterator(const input_iterator_tag&) {
  cout << "Input-Iterator\n";
}

void welcherIterator(const output_iterator_tag&) {
  cout << "Output-Iterator\n";
}

void welcherIterator(const forward_iterator_tag&) {
  cout << "Forward-Iterator\n";
}

void welcherIterator(const random_access_iterator_tag&) {
  cout << "Random-Access-Iterator\n";
}

int main() {                                // Anwendung
  // Bei Grunddatentypen (hier: ein Zeiger) wird das partiell spezialisierte
  // \tt{iterator\_traits<T*>}- Template von Seite \pageref{partielleSpezialisierung} benutzt.
  int* ip;                                  // Random-Access-Iterator
  // Anzeige des Iteratortyps
  welcherIterator(getIteratortyp(ip));
  welcherIterator(iterator_traits<int*>::iterator_category());

  // Definition eines Datei-Objekts zum Lesen (eine tatsächliche Datei
  // ist nicht erforderlich, es geht nur um den Typ)
  ifstream Source;
  // Ein \tt{istream\_iterator} ist ein Input-Iterator.
  istream_iterator<string> IPos(Source);
  // Anzeige des Iteratortyps
  welcherIterator(getIteratortyp(IPos));  // oder:
  welcherIterator(
      iterator_traits<istream_iterator<string>>::iterator_category());

  // Definition eines Datei-Objekts zum Schreiben
  ofstream Destination;
  // Ein \tt{ostream\_iterator} ist ein Output-Iterator.
  ostream_iterator<string> OPos(Destination);
  // Anzeige des Iteratortyps
  welcherIterator(getIteratortyp(OPos));  // oder:
  welcherIterator(
      iterator_traits<ostream_iterator<string>>::iterator_category());

  vector<int> v(10);
  // Anzeige des Iteratortyps
  welcherIterator(getIteratortyp(v.begin()));
  // oder ein anderer Iterator als \tt{begin()}
  welcherIterator(
      iterator_traits<vector<int>::iterator>::iterator_category());
}
