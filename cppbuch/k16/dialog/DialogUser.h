/* cppbuch/k16/dialog/DialogUser.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef DialogUser_h
#define DialogUser_h
#include "NamenDialog.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

class DialogUser : public QMainWindow {
  Q_OBJECT
public:
  DialogUser() {
    namendialog = new NamenDialog(this);
    namendialog->setModal(true);
    namendialog->show();
    connect(namendialog, SIGNAL(accepted()), this, SLOT(dialogBeendet()));
    connect(namendialog, SIGNAL(rejected()), this, SLOT(dialogBeendet()));
  }
private slots:
  void dialogBeendet() {
    // Zuerst Ergebnis abfragen (hier mit Anzeige) ...
    QString str("Dialog abgebrochen");
    if (namendialog->result() == QDialog::Accepted) {  // doch erfolgreich
      str = namendialog->getText();
    }
    QMessageBox msgBox;
    QString msg("Dialogergebnis: ");
    msg += str;
    msgBox.setText(msg);
    msgBox.exec();
  }

private:
  NamenDialog* namendialog;
};
#endif
