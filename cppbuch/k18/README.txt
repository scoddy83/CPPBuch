Wenn Sie eine Integrierte Entwicklungsumgebung (IDE) benutzen,
vergessen Sie nicht, sqlite3 bekannt zu machen, indem Sie bei
Project - Build options Folgendes eintragen:

Linker settings / Link libraries: sqlite3


---------------------------------------------

Datenbank: shopdb.db

Datenbank neu erzeugen:
- shopdb.db loeschen
- Tabellen anlegen mit
  sqlite3 shopdb.db < shopdb.txt
- Tabellen fuellen mit
  sqlite3 shopdb.db < shopdbfuellen.txt

sqlite3 interaktiv nutzen:

sqlite3 shopdb.db
.help Hilfe
.dump Datenbank anzeigen
.exit beenden

(Punkt vor jedem Kommando nicht vergessen.)

abfrage.exe: Interaktiv SQL-Anfragen stellen

mit Skript (s. skript.txt)
abfrage.exe < skript.txt



