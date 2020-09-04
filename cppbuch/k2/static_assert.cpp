/* cppbuch/k2/static_assert.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/

int main() {
  static_assert(sizeof(long) > sizeof(int),
                "long hat nicht mehr Bits als int!");
}
