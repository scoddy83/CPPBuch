/* cppbuch/k10/liste/liste.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
//  Listen-Template für einfach-verkettete Liste
// T ist ein Platzhalter für den Datentyp eines Listenelements
// Unvollständig! (nur für das Beispiel notwendige Funktionen sind
// implementiert). Siehe auch Übungsaufgaben.
#ifndef LISTE_T
#define LISTE_T
#include <cstddef>
#include <iterator>

template <typename T> 
class Liste {
public:
  // Kopierkonstruktor, Destruktor und Zuweisungsoperator fehlen!!! (Aufgaben)

  // \tt{push\_front()} erzeugt ein neues Listenelement und
  // fügt es am Anfang der Liste ein:
  void push_front(const T& wert) { 
    anfang = new ListElement(wert, anfang); 
  }

private:
  struct ListElement {
    T daten;
    ListElement* naechstes;
    ListElement(const T& wert, ListElement* p) 
      : daten{wert}, naechstes{p} {
      }
  };
  ListElement* anfang{nullptr};

public:
  class Iterator {
  public:
    // von \tt{find()} geforderte Schnittstelle:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = ptrdiff_t;

    Iterator(ListElement* init = nullptr) 
      : aktuellesElement{init} {
    }

    T& operator*() {  // Dereferenzierung
      return aktuellesElement->daten;
    }

    const T& operator*() const {  // Dereferenzierung
      return aktuellesElement->daten;
    }

    Iterator& operator++() {   // Präfix
      if (aktuellesElement) {  // noch nicht am Ende angelangt?
        aktuellesElement = aktuellesElement->naechstes;
      }
      return *this;
    }

    Iterator operator++(int) {  // Postfix
      Iterator temp{*this};
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

  //   Einige Methoden der Klasse \tt{Liste} benutzen die Klasse {\tt Iter\-ator} (siehe unten):
  Iterator begin() const { return Iterator(anfang); }
  Iterator end() const { return Iterator(); }
};

#endif
