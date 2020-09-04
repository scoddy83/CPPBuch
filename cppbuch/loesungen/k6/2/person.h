/* cppbuch/loesungen/k6/2/person.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
public:
  Person(const std::string& n, const std::string& v)
      : nachname{n}, vorname{v} {}
  virtual ~Person() = default;
  Person(const Person&) = default;
  Person& operator=(const Person&) = default;
  const std::string& getNachname() const { return nachname; }
  const std::string& getVorname() const { return vorname; }
  virtual std::string toString() const = 0;

private:
  std::string nachname;
  std::string vorname;
};

// Die Standardimplementierung einer rein virtuellen Methode
// muss außerhalb der Klassendefinition stehen:
inline std::string Person::toString() const {
  return vorname + " " + nachname;
}
#endif
