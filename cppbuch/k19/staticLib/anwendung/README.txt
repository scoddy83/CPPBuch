Wenn es Linker-Fehler wie "cannot find -lm" usw. gibt, fehlen die
statischen Bibliotheken.

Linux: Das Package glibc-devel-static installieren.

Mac: 
Statische Bindung eigener Programme wird NICHT unterstützt!
Fehler: crt0.o wird nicht gefunden
Zwar kann man statische Bibliotheken erzeugen, sie aber nicht
statisch linken.
Begründung siehe
https://developer.apple.com/library/content/qa/qa1118/_index.html

