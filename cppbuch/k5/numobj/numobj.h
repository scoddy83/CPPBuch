/* cppbuch/k5/numobj/numobj.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef NUMOBJ_H
#define NUMOBJ_H

class NummeriertesObjekt {  // noch nicht vollständig!!! (siehe Text)
public:
  NummeriertesObjekt();
  NummeriertesObjekt(const NummeriertesObjekt&);
  ~NummeriertesObjekt();
  unsigned long seriennummer() const {
    return serienNr;
  }
  static int anzahl() {
    return anz;
  }
  static bool testmodus;

private:
  static int anz;  // \tt{int} statt \tt{unsigned }(s. Text)
  static unsigned long maxNummer;
  const unsigned long serienNr;
};
#endif  // Ende von numobj.h
