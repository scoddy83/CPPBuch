/* cppbuch/k16/signalslot/main.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "Window.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Window win;
  win.show();
  return app.exec();
}
