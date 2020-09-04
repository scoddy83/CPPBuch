Die Beispiele in regex/ sind erst ab G++ Version 4.9 compilierbar.
Bei früheren G++-Versionen bitte die BOOST-Variante nehmen
(regex_boost).  

Das Aequivalent der Datei regex_boost/loc.cpp fehlt im Verzeichnis
regex/, weil Standard C++ im Gegensatz zu Boost und Java keine
regulaeren Ausdruecke unterstuetzt, die '(?s)' enthalten. (?s)
bedeutet, dass \n wie ein normales Zeichen interpretiert wird
(dot-matches-all-Regel).
