/* cppbuch/k16/window/Window.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WINDOW_H
#define WINDOW_H
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <fstream>

class Window : public QMainWindow {
protected:
  void closeEvent(QCloseEvent*) {  // Name wird nicht gebraucht
    int antwort =
        QMessageBox::warning(this, "Titel", "closeEvent gerufen. Sichern?",
                             QMessageBox::Yes | QMessageBox::No);
    if (antwort == QMessageBox::Yes) {
      save();
    }
  }

private:
  void save() {
    std::ofstream log("daten.txt");
    log << "gesicherte Daten\n";
    log.close();
  }
};

#endif
