/* cppbuch/k16/dialog/NamenDialog.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef NAMENDIALOG_H
#define NAMENDIALOG_H
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

class NamenDialog : public QDialog {
  Q_OBJECT
public:
  NamenDialog(QWidget* parent = 0)
      : QDialog(parent), eingabezeile(new QLineEdit),
        text(new QLabel("&Namen eingeben:")), okButton(new QPushButton("OK")),
        abbruchButton(new QPushButton("Abbruch")),
        zeile1(new QBoxLayout(QBoxLayout::LeftToRight)),
        zeile2(new QBoxLayout(QBoxLayout::LeftToRight)),
        alles(new QBoxLayout(QBoxLayout::TopToBottom)) {
    setWindowTitle("Name?");
    text->setBuddy(eingabezeile);
    zeile1->addWidget(text);
    zeile1->addWidget(eingabezeile);
    zeile2->addWidget(okButton);
    zeile2->addWidget(abbruchButton);
    alles->addLayout(zeile1);
    alles->addLayout(zeile2);
    setLayout(alles);
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(abbruchButton, SIGNAL(clicked()), this, SLOT(reject()));
  }

  ~NamenDialog() {
    delete eingabezeile;
    delete text;
    delete okButton;
    delete abbruchButton;
    delete zeile1;
    delete zeile2;
    delete alles;
  }

  QString getText() const { return eingabezeile->text(); }

private:
  QLineEdit* eingabezeile;
  QLabel* text;
  QPushButton* okButton;
  QPushButton* abbruchButton;
  QBoxLayout* zeile1;
  QBoxLayout* zeile2;
  QBoxLayout* alles;
};
#endif
