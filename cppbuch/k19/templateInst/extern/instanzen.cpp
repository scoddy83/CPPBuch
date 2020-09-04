/* cppbuch/k19/templateInst/extern/instanzen.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "meintyp.t"
#include <string>

// explizite Instanziierung
template class MeinTyp<std::string>;
template class MeinTyp<double>;
