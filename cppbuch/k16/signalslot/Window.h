/* cppbuch/k16/signalslot/Window.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WINDOW_H
#define WINDOW_H
#include "QtBeispiel.h"
#include <QtGui>  // enthält qApp, siehe unten
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>

class Window : public QMainWindow {
  // Das Makro  \tt{Q\_OBJECT} sorgt u.a. für die richtige
  // Interpretation der Signale und Slots.
  Q_OBJECT

public:
  Window() {
    setGeometry(100, 100, 400, 300);
    QtBeispiel* widget = new QtBeispiel(this);
    setCentralWidget(widget);
    menuAnlegen();         // siehe unten
    statuszeileAnlegen();  // siehe unten
    connect(widget->getZeichenflaeche(), SIGNAL(radiusChanged(int)), this,
            SLOT(statuszeileAktualisieren(int)));
  }
  ~Window() {
    delete statusLabel;
    delete fileMenu;
  }

private slots:
  void statuszeileAktualisieren(int radius) {
    if (radius < 51) {
      statusLabel->setText("<span style=\"color:green\">klein</span>");
    } else {
      statusLabel->setText("<span style=\"color:red\">gross</span>");
    }
  }

private:
  void menuAnlegen() {
    fileMenu = menuBar()->addMenu(tr("&Datei"));
    QAction* quitAction = new QAction(tr("&Ende"), this);
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Programm beenden"));
    fileMenu->addAction(quitAction);
    // qApp ist globale Variable der Applikation, s.o. #include
    // <QtGui>
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
  }

  void statuszeileAnlegen() {
    statusLabel = new QLabel("nicht bewegt");
    statusBar()->addWidget(statusLabel);
  }
  QMenu* fileMenu;
  QLabel* statusLabel;
};

#endif
