/* cppbuch/k16/label/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <iostream>

class MeinLabel : public QLabel {
public:
  MeinLabel(const char* text) : QLabel(text) {}
};

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  MeinLabel mlabel("Erstes Qt-Programm");
  mlabel.setMinimumSize(200, 50);
  mlabel.show();
  return app.exec();
}
