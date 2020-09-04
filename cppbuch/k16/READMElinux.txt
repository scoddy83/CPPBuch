LINUX:

Installieren Sie Qt5 mithilfe Ihres Systemtools (yast/apt usw.)
Auch libqwt5 muss installiert sein!

Öffnen Sie im Verzeichnis mit dieser README-Datei (cppbuch/k16) ein
Terminal (bzw. Konsole).  Passen Sie die Datei qtenv.sh Ihrem
Qt-System an, indem Sie den Pfad entsprechend Ihrer Installation
eintragen. Geben Sie dann

./qtenv.sh

ein. Der Compiler für Qt muss *vor* dem bereits installierten im Pfad
liegen.  Genau dafür sorgt qtenv.sh. Der Grund: Der bereits
installierte Compiler ist eine neuere Version, Qt wurde aber mit einer
älteren Version gebaut. Um Probleme zu vermeiden, wird für eigene
Qt-Programme der von Qt mitgelieferte Compiler verwendet.

Gehen Sie in das gewünschte Verzeichnis, zum Beispiel mit 
cd label
Das Vorgehen gilt auch für die anderen Beispiele.
Geben Sie 

qmake -project 
ein. 
ACHTUNG: Manche Systeme erlauben Qt4 und Qt5. Möglicherweise ist statt
qmake
qmake-qt5
zu verwenden! (Z.B. Opensuse 14.2)

Lesen Sie die README-Datei und folgen den Anweisungen. Geben Sie dann

make

ein. Das Programm wird übersetzt. Sie finden die ausführbare Datei im aktuellen Verzeichnis.

Bitte die auch README-Dateien in den anderen Unterverzeichnissen lesen.


ACHTUNG!
Nach Programmaenderungen genuegt es,  make nochmal aufzurufen,
aber:
Bei Aenderungen der Dateistruktur muessen vorher auch
  qmake -project
  qmake
aufgerufen werden! Falls Qtwidgets benoetigt werden, unbedingt
in der *pro-Datei die Zeile
QT += widgets
hinzufuegen!

Bei unerklaerlichen Uebersetzungsproblemen hilft manchmal,
alle vom Meta-Objekt-Compiler erzeugten Dateien zu loeschen.
Deren Name beginnt mit moc_. Das kann mit dem Befehl
  make clean
erreicht werden.
  make distclean
loescht zusaetzlich das Makefile und das Executable, erfordert also ein neues
  qmake


*********************************

Falls Sie Qt-Anwendungen mit einer Entwicklungsumgebung programmieren
wollen, empfehle ich Ihnen Qt-Creator. 



*********************************
Weitere Hinweise entnehmen Sie bitte den README.txt-Dateien in
den Unterverzeichnissen.



