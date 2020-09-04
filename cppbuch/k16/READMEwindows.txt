WINDOWS:


Am besten installieren Sie Qt von
http://download.qt.io/archive/qt/5.8/5.8.0/qt-opensource-windows-x86-mingw530-5.8.0.exe
Diese Version ist für 32-Bit und 64_Bit-Windows geeignet. Eine reine 64-Bit-Version mit MinGW wird nicht angeboten.

Falls Sie eine andere Qt-Version nehmen wollen:
Bitte achten Sie darauf, dass sie
- OpenSource ist (kostenfrei für Lern- und Lehrzwecke)
- "mingw" im Linknamen enthält
Die Anleitungen in diesem Buch gelten nicht für andere Varianten.

Öffnen Sie im Verzeichnis mit dieser README-Datei (cppbuch/k16) eine
">Eingabeaufforderung"< (Terminal/Konsole). Passen Sie die Datei
qtenv.bat Ihrem Qt-System an, indem Sie den Pfad entsprechend Ihrer
Installation eintragen. Geben Sie dann

qtenv.bat

ein. Der Compiler für Qt muss *vor* dem bereits installierten im Pfad
liegen.  Genau dafür sorgt qtenv.bat. Der Grund: Der bereits
installierte Compiler ist eine neuere Version, Qt wurde aber mit einer
älteren Version gebaut. Um Probleme zu vermeiden, wird für eigene
Qt-Programme der von Qt mitgelieferte Compiler verwendet.

Gehen Sie in das gewünschte Verzeichnis, zum Beispiel mit 
cd label
Das Vorgehen gilt auch für die anderen Beispiele. Geben Sie 

qmake -project
 
ein. Lesen Sie die README-Datei und folgen den Anweisungen. Geben Sie
dann

make

ein. Das Programm wird übersetzt. Das Executable ist im
Unterverzeichnis release des jeweiligen Ordners.


Bitte die auch README-Dateien in den anderen Unterverzeichnissen lesen.


Das Programm kann nicht durch Anklicken im Explorer gestartet werden,
weil der eingestellte Pfad nur für die Konsole gilt. Den Pfad auf
Systemebene entsprechend einzustellen, ist keine gute Idee, weil dann
der vorher installierte MinGW-Compiler nicht mehr gefunden wird.

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



