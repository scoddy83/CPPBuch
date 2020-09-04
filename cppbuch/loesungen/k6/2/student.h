/* cppbuch/loesungen/k6/2/student.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
#include <string>

class StudentIn : public Person {
public:
  StudentIn(const std::string& name, const std::string& vorname,
            const std::string& matnr)
      : Person{name, vorname}, matrikelnummer{matnr} {}
  const std::string& getMatrikelnummer() const { return matrikelnummer; }
  virtual std::string toString() const override {
    return "Student/in " + Person::toString() + ", Mat.Nr.: " +
           matrikelnummer;
  }

private:
  std::string matrikelnummer;
};
#endif
