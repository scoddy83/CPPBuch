/* cppbuch/k1/ansiesc.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
using namespace std;
/* Weitere ANSI-Escape-Sequenzen finden Sie im Internet.
   Falls ANSI-Escape-Sequenzen von Ihrem System nicht oder nicht
   korrekt umgesetzt werden, fragen Sie bitte nicht mich, sondern
   den Hersteller Ihres Betriebssystems.
   Windows: Es ist mindestens Windows 10 Version 1511 (nov. 2015)
   erforderlich.

   Die Escape-Sequenzen beginnen mit dem Escape-Zeichen (Nr. 27
   (dezimal) der ASCII-Tabelle bzw. 0x1B (hexadezimal) bzw 033
   (oktal). Im  Programm müssen sie als \0x1B bzw. \33 oder \033
   codiert werden.

   Übersetzen Sie die Datei in der Konsole mit
   g++ ansiesc.cpp -o ansiesc.exe
   und starten Sie das Programm mit
   ansiesc.exe
*/

int main() {
  char eingabe;
  cout << "Fuer jeden Test die ENTER-Taste betaetigen!\n"
          "Bildschirm (Konsolenfenster) loeschen:\n";
  cin.get(eingabe);  // wird an anderer Stelle erkärt
  cout << "\33[2J"   // Bildschirm loeschen
          "Nicht zu loeschende Zeile\n";
  cout << "DIESE ZWEITE ZEILE LOESCHEN:";
  cin.get(eingabe);
  cout << "\33[" << 1 << "A"       // Cursor um 1 nach oben
                         "\33[K";  // Zeile loeschen
  cout << "Cursor Home-Position:";
  cin.get(eingabe);
  cout << "\33[H"  // Cursor go home!
          "Hier ist Home.\n"
          "An Position (5 Zeilen, 10 Zeichen) weiterschreiben:";
  cin.get(eingabe);
  cout << "\33[" << 5 << ";" << 10 << "H"
                                      "... hier geht es weiter:\n";
  cout << "\33[1;31m"  // rote Zeichen
          "rote Zeichen"
          "\33[42m"  // grüner Hintergrund
          "auf gruenem Hintergrund\n";
  cout << "\33[1;45m"  // violetter Hintergrund
          "\33[1;33m"  // gelbe Zeichen
          "gelb auf violett\n";
  cout << "\33[44m"  // blauer Hintergrund
          "\33[36m"  // cyanblaue Zeichen
          "cyanblau auf blau\n";
  cout << "\33[0;40m"  // schwarzer Hintergrund
          "\33[1;37m"  // weiße Zeichen
          "Weisse Zeichen auf schwarzem Hintergrund\n";
  cout << "\33[0m"  // auf normale Darstellung schalten
          "normale Darstellung\nProgrammende\n";
}
