Der Verzeichnisname gibt das Kapitel an. Zum Beispiel enthält das
Verzeichnis "cppbuch/k5 die Beispiele aus Kapitel 5.

In jedem Verzeichnis, das makefile enthält, kann die Übersetzung
durch den Aufruf
 make
angestoßen werden.
 make clean
löscht alle erzeugten Dateien. Anschließend mögliche Aufrufe:

      make
        übersetzt sämtliche Beispiele. Wenn Sie einen Multikern-
        prozessor haben, können Sie zum Beispiel
        make -j2 oder make -j4 für einen Dual- bzw. Quadcore-
        Rechner aufrufen, um den Vorgang zu beschleunigen.

      make clean
        löscht sämtliche bei der Übersetzung erzeugte Dateien,
        soweit (noch) vorhanden

      make  2> error.log
        übersetzt sämtliche Beispiele und sammelt die Fehlermeldungen
        in der Datei error.log

      make > compile.log 2>&1
        übersetzt sämtliche Beispiele und sammelt alle Ausgaben
        einschließlich der Fehlermeldungen in der Datei compile.log

Erläuterungen zu makemakefile finden Sie im Abschnitt
"Makefile für rekursive Aufrufe erzeugen" des Buchs.

Das Kapitel 15 setzt die Installation von Qt voraus. Siehe Hinweise
im Kapitel.

######## EINSCHRÄNKUNGEN BEI DER ÜBERSETZUNG! ############
Damit Sie sich nicht wundern, falls nicht alles übersetzt wird:
Das Beispiel mit static_assert ist absichtlich nicht übersetzbar,
 wenn long-Zahlen nicht mehr Bits als int-Zahlen haben.


Falls Sie Windows benutzen:
*****************************************

Einige Kapitel setzen die Installation von Boost voraus.  Wenn Sie die
empfohlene Installationsdatei für den Compiler benutzen, wird Boost
automatisch mit installiert.
Falls Sie NICHT die vorgeschlagene Standardinstallation nutzen
wollen, müssen Sie an den folgenden Stellen Änderungen vornehmen:
in make/einstellungen.mak :
BOOST-Verzeichnis und -Variante anpassen
(Namen siehe Boost/lib)

Falls Sie MacOS benutzen: 
*****************************************

Alle Beispiele werden vom g++-Compiler 7.1 sowohl unter Windows wie
auch Linux übersetzt.  Der Compiler in der XCode Version 9, die ich
benutzt habe, übersetzt leider nicht alle Beispiele (insbesondere die
aus Kap. 24), vermutlich weil Apple nicht sofort die aktuellste
Compiler-Version einbaut.


