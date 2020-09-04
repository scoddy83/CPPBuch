/* cppbuch/include/pi.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef PI_H
#define PI_H

template <typename T> constexpr T pi 
      = static_cast<T>(3.14159265358979323846264338328L);

#endif
