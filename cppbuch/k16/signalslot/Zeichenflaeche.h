/* cppbuch/k16/signalslot/Zeichenflaeche.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef ZEICHENFLAECHE_H
#define ZEICHENFLAECHE_H
#include <QPainter>
#include <QWidget>

class Zeichenflaeche : public QWidget {
  Q_OBJECT
public:
  Zeichenflaeche() {
    aktuellerRadius = 1;
    setPalette(QPalette(QColor(255, 255, 255)));  // weiß
    setAutoFillBackground(true);
  }

public slots:
  void setRadius(int radius) {
    if (radius != aktuellerRadius) {  // nur dann etwas tun!
      if (radius < 1) {
        radius = 1;
      }
      aktuellerRadius = radius;
      update();  // \tt{paintEvent()}-Aufruf einplanen
      emit radiusChanged(aktuellerRadius);  // Änderung signalisieren
    }
  }

signals:
  void radiusChanged(int neuerRadius);

protected:
  void paintEvent(QPaintEvent*) {  // Parameter wird nicht benutzt
    QPainter painter(this);
    // Transformation der Koordinaten auf die Zeichenfläche
    painter.translate(0, rect().height());
    int offset = rect().height() / 2;
    int r = aktuellerRadius;
    // einen durch ein Rechteck definierten Kreis zeichnen:
    painter.drawEllipse(QRectF(offset - r, -offset - r, 2 * r, 2 * r));
  }

private:
  int aktuellerRadius;
};
#endif
