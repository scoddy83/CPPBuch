/* cppbuch/k20/einfach.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(einfacher_stringtest)

BOOST_AUTO_TEST_CASE(laenge) {
  std::string s("xyz");
  BOOST_CHECK(s.length() == 3);
}

BOOST_AUTO_TEST_CASE(gleichheits_operator) {
  std::string s("abc");
  BOOST_CHECK(s == "abc");
}

BOOST_AUTO_TEST_SUITE_END()
