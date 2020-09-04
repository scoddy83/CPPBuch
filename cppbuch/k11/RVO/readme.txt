Das Kommando 'make' erzeugt zwei ausführbare Dateien aus demselben
Quellprogramm main.cpp:

rvo.exe : Der Aufruf des Kopierkonstruktors wird teilweise wegoptimiert.

norvo.exe : Der Aufruf des Kopierkonstruktors wird NICHT wegoptimiert
            (Compiler-Option -fno-elide-constructors, siehe makefile).


norvo.exe erzeugt mehr Aufrufe des Kopierkonstruktors als rvo.exe

