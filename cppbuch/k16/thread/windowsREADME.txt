An Windows-User:

Falls Sie die .pro-Datei mit 
  qmake -project
neu erzeugen:

CONFIG += console

als letzte Zeile hinzufuegen!
Danach wie ueblich
  qmake
  make



Die ausfuehrbare Datei befindet sich danach

- im Arbeitsverzeichnis (Linux)

- im Unterverzeichnis release (Windows)

Wenn die Dateistruktur sich nicht aendert, genuegt danach
make
zur Uebersetzung nach Programmaenderungen.

