/* cppbuch/k16/dirtree/tree.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "tree.h"
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <iostream>
#include <stdexcept>

namespace {
std::ostream& operator<<(std::ostream& os, const QString& qstr) {
  os << qstr.toStdString();
  return os;
}

void baumAnzeigen(const QDir& d, int level) {
  QStringList eintraege =
      d.entryList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
  QStringList::const_iterator dIterator = eintraege.begin();
  while (dIterator != eintraege.end()) {
    QString fn(*dIterator);
    QString absPfad(d.absolutePath() + "/" + fn);
    for (int i = 0; i < level; ++i) {
      std::cout << " |  ";
    }
    std::cout << " |-- " << fn << '\n';
    QFileInfo qi(absPfad);
    if (qi.isDir()) {
      QDir dir(absPfad);
      baumAnzeigen(dir, level + 1);
    }
    ++dIterator;
  }
}
}  // anonymer namespace

void baumAnzeigen(const std::string& verz) {
  QFileInfo pfad(verz.c_str());
  if (pfad.isDir()) {
    std::cout << verz << '\n';
    QDir dir(verz.c_str());
    baumAnzeigen(dir, 0);
  } else {
    throw std::runtime_error(" ist kein Verzeichnis!");
  }
}
