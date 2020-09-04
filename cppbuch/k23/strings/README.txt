Die Programme in diesem Verzeichnis verwenden eine andere
Sprachumgebung als "C". Dies setzt voraus, dass die Sprachumgebung vom
C++-Compiler unterstützt wird. 

Der GNU C++-Compiler für Linux unterstützt diverse Sprachen, sein
Gegenstück für Windows, der MinGW-C++-Compiler leider nicht!  Die
Windows-Fehlermeldung lautet "This application has requested the
Runtime in an unusual way." usw. MinGW kann leider nur die Umgebungen
"C" und ""(aktuell eingestellte Umgebung).

Das Programm cppbuch/k30/checklocales.cpp prüft die Unterstüzung Ihres
Compilers für manche Sprachumgebungen. Lesen Sie es und lassen Sie es
laufen.


