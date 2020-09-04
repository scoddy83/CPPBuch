Die Lösungen zu den Aufgaben

10: Ausgabeoperator: siehe ../../../include/datum.h

11: relationale Operatoren: siehe ../../../include/datum.h

12: Datumdifferenz: siehe ../../../include/datum.h


15: toString() fehlt. Beispiel

std::string Datum::toString() const {
  std::string temp("tt.mm.jjjj");
  // implizite Umwandlung in char
  temp[0] = tag_ / 10 + '0';
  temp[1] = tag_ % 10 + '0';
  temp[3] = monat_ / 10 + '0';
  temp[4] = monat_ % 10 + '0';
  unsigned int pos = 9; // letzte Jahresziffer
  unsigned int j = jahr_;
  while (j > 0) {
    temp[pos] = j % 10 + '0'; // letzte Ziffer
    j = j / 10;               // letzte Ziffer abtrennen
    --pos;
  }
  return temp;
}

Alternativ: to_string() benutzen, siehe 
../../../include/ungueltigesdatumexception.h
