Programm uebersetzen:

qmake -project

sofern die Datei mit der Endung .pro noch nicht existiert oder geloescht wurde.
Dann der entstandenen Datei mit einem Editor die Zeile

QT += widgets

hinzufuegen. Dann 

qmake
make

Die ausfuehrbare Datei befindet sich danach

- im Arbeitsverzeichnis (Linux)

- im Unterverzeichnis release (Windows)

Wenn die Dateistruktur sich nicht aendert, genuegt danach
make
zur Uebersetzung nach Programmaenderungen.

