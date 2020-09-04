/* cppbuch/loesungen/k10/liste.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Listen-Template für einfach-verkettete Liste
// T ist ein Platzhalter für den Datentyp eines Listenelements
// Unvollständig! (nur für das Beispiel notwendige Funktionen sind
// implementiert)

/*******  Die Lösungen zu den Übungsaufgaben befinden
sich am Ende  **/

#ifndef LISTE_T
#define LISTE_T
#include <cstddef>
#include <iterator>

template <typename T> class Liste {
public:
  Liste() = default;

  // \tt{push\_front()} erzeugt ein neues Listenelement und
  // fügt es am Anfang der Liste ein:
  void push_front(const T& wert) { anfang = new ListElement(wert, anfang); }

private:
  struct ListElement {
    T daten;
    ListElement* naechstes;
    ListElement(const T& wert, ListElement* p) : daten{wert}, naechstes{p} {}
  };
  ListElement* anfang{nullptr};

public:
  class Iterator {
    friend class Liste;

  public:
    // von find() geforderte Schnittstelle:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;

    Iterator(ListElement* init = nullptr) : aktuellesElement(init) {}

    T& operator*() {  // Dereferenzierung
      return aktuellesElement->daten;
    }

    const T& operator*() const {  // Dereferenzierung
      return aktuellesElement->daten;
    }

    Iterator& operator++() {  // Präfix
      if (aktuellesElement)   //  noch nicht am Ende angelangt?
        aktuellesElement = aktuellesElement->naechstes;
      return *this;
    }

    Iterator operator++(int) {  // Postfix
      Iterator temp = *this;
      ++*this;
      return temp;
    }

    bool operator==(const Iterator& x) const {
      return aktuellesElement == x.aktuellesElement;
    }

    bool operator!=(const Iterator& x) const {
      return aktuellesElement != x.aktuellesElement;
    }

  private:
    ListElement* aktuellesElement;  // Verweis auf aktuelles Element
  };                                // Iterator
  //   Einige Methoden der Klasse \tt{Liste} benutzen die Klasse
  //   {\tt
  //   Iter\-ator} (siehe unten):
  Iterator begin() const { return Iterator(anfang); }
  Iterator end() const { return Iterator(); }

  /*******  Lösungen  zu den Übungsaufgaben  *************/

  Liste(const Liste& liste) {  // Kopierkonstruktor
    if (liste.anfang) {
      Iterator i{liste.begin()};
      push_front(*i++);  // erstes Element anlegen, anfang ist danach
                         // != nullptr
      ListElement* letztes{anfang};
      while (i != liste.end()) {
        // Elemente am Ende einfügen, damit die
        // Reihenfolge erhalten bleibt
        letztes->naechstes = new ListElement(*i++, nullptr);
        letztes = letztes->naechstes;
      }
    }
  }

  Liste& operator=(Liste temp) {  // Zuweisungsoperator
    std::swap(temp.anfang, anfang);
    return *this;
  }

  ~Liste() {  // Destruktor
    clear();
  }

  Iterator erase(Iterator p) {
    if (empty()) {
      return Iterator();  // leere Liste
    }
    ListElement* zuLoeschen{p.aktuellesElement};
    // Vorgänger suchen
    ListElement* vorgaenger{anfang};
    if (zuLoeschen != anfang) {
      while (vorgaenger->naechstes != zuLoeschen) {
        vorgaenger = vorgaenger->naechstes;
      }
      // Zeiger verbiegen
      vorgaenger->naechstes = zuLoeschen->naechstes;
    } else {                           // am Anfang löschen
      anfang = zuLoeschen->naechstes;  // Zeiger verbiegen
    }
    Iterator nachfolger{++p};
    delete zuLoeschen;
    return nachfolger;
  }

  void pop_front() { erase(begin()); }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  bool empty() const { return anfang == nullptr; }

  size_t size() const {
    size_t anzahl{0};
    ListElement* temp{anfang};
    while (temp) {
      ++anzahl;
      temp = temp->naechstes;
    }
    return anzahl;
  }

  /*******  Ende der Lösungen  zu den Übungsaufgaben *************/
};

#endif
