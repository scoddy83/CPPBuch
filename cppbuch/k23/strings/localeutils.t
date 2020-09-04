/* cppbuch/k23/strings/localeutils.t
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <locale>
#include <string>

template <typename charT>
void klein(std::basic_string<charT>& s,
           const std::locale& loc = std::locale()) {
  for (auto& c : s) {
    c = std::use_facet<std::ctype<charT>>(loc).tolower(c);
  }
}

template <typename charT>
void gross(std::basic_string<charT>& s,
           const std::locale& loc = std::locale()) {
  for (auto& c : s) {
    c = std::use_facet<std::ctype<charT>>(loc).toupper(c);
  }
}

template <typename charT> struct Stringvergleich {
  Stringvergleich(const std::locale& lo = std::locale()) : loc(lo) {}
  bool operator()(const std::basic_string<charT>& s1,
                  const std::basic_string<charT>& s2) {
    return std::use_facet<std::collate<charT>>(loc).compare(
               s1.c_str(), s1.c_str() + s1.length(), s2.c_str(),
               s2.c_str() + s2.length()) < 0;
  }
  const std::locale loc;
};

template <typename charT>
inline bool equalIgnoreCase(charT c1, charT c2,
                            const std::locale& loc = std::locale()) {
  return std::use_facet<std::ctype<charT>>(loc).toupper(c1) ==
         std::use_facet<std::ctype<charT>>(loc).toupper(c2);
}

template <typename charT> struct EqualIgnoreCase {
  EqualIgnoreCase(const std::locale& lo = std::locale()) : loc(lo) {}
  bool operator()(charT c1, charT c2) { return equalIgnoreCase(c1, c2, loc); }
  const std::locale loc;
};

template <typename charT>
std::size_t
findeSuchstringIgnoreCase2(std::basic_string<charT> text,
                           std::basic_string<charT> such,
                           const std::locale& loc = std::locale("de_DE")) {
  gross(text, loc);
  gross(such, loc);
  return text.find(such);
}

template <typename charT>
std::size_t
findeSuchstringIgnoreCase(const std::basic_string<charT>& text,
                          const std::basic_string<charT>& such,
                          const std::locale& loc = std::locale("de_DE")) {
  auto pos = std::search(text.begin(), text.end(), such.begin(), such.end(),
                         EqualIgnoreCase<charT>(loc));
  return pos == text.end() ? std::basic_string<charT>::npos
                           : (pos - text.begin());
}
