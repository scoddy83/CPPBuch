/* cppbuch/k8/literale/stringliterale.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <string_view>

int main() {
  std::string_view asciiOderISO8859{"ASCI oder ISO 8859-1"};
  std::string_view utf8{u8"UTF-8"};
  std::u16string_view utf16{u"UTF-16"};
  std::u32string_view utf32{U"UTF-32"};
  std::wstring_view multibyte{L"Multibyte"};
}
