Programm uebersetzen:

qmake -project

sofern die Datei mit der Endung .pro noch nicht existiert oder geloescht wurde.
Dann der entstandenen Datei mit einem Editor die Zeile

QT += widgets

und für Windows noch

CONFIG += console

hinzufuegen und speichern. Dann 

qmake
make

Die ausfuehrbare Datei befindet sich danach

- im Arbeitsverzeichnis (Linux)

- im Unterverzeichnis release (Windows), Ausführung mit release\label.exe

Wenn die Dateistruktur sich nicht aendert, genuegt danach
make
zur Uebersetzung nach Programmaenderungen.

