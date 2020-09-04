/* cppbuch/k3/ort1/ort1.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ORT1_H
#define ORT1_H

class Ort1 {  // 1. Version
public:
  int getX() const;
  int getY() const;
  void aendern(int x, int y);  // x,y = neue Werte
private:
  int xKoordinate;
  int yKoordinate;
};
#endif  //  ORT1_H
