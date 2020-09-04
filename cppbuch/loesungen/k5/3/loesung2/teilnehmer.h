/* cppbuch/loesungen/k5/3/loesung2/teilnehmer.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef TEILNEHMER_H
#define TEILNEHMER_H
#include <string>
#include <vector>

class Teilnehmer {
public:
  Teilnehmer(const std::string& name);
  ~Teilnehmer();
  void lerntKennen(Teilnehmer& tn);
  bool kennt(const Teilnehmer& tn) const;
  void druckeBekannte() const;
  const std::string& gibNamen() const;

private:
  std::string name;
  std::vector<Teilnehmer*> dieBekannten;
};
#endif
