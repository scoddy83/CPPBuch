Der in der Aufgabenstellung gezeigte Fall mit den Namen Dirac und
Pauli ist dadurch gekennzeichnet, dass das Objekt "pauli" nach Ende
des Blocks nicht mehr existiert

Im Verzeichnis loesung1 werden die Bekannten in einem vector<string>
abgespeichert. Der in der Aufgabenstellung gezeigte Fall mit den Namen
Dirac und Pauli ist unkritisch. Es kann natürlich sein, dass es zwei
Teilnehmer gleichen Namens gibt. Diese können nicht unterschieden
werden. Teilnehmer, die aus dem Blickfeld geraten sind, bleiben im
Gedächtnis.

Im Verzeichnis loesung2 werden die Bekannten in einem
vector<Teilnehmer*> abgespeichert. Der in der Aufgabenstellung
gezeigte Fall mit den Namen Dirac und Pauli wird dadurch gelöst, dass
der Destruktor eines Teilnehmers diesen Teilnehmer bei allen Bekannten austrägt.
Teilnehmer gleichen Namens können unterschieden werden.
