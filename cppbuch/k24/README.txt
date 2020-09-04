Wenn Sie eine Integrierte Entwicklungsumgebung (IDE) benutzen,
vergessen Sie nicht, die Filesystem-Library
bekannt zu machen (siehe makefile)

Sie finden in den Programmen
#include <experimental/filesystem>
und
std::experimental::

Das heißt, dass die Software diesbezueglich noch nicht ausgereift ist.
So funktieren bei mir alle Programme unter Linux, aber unter Windows
10 gehen die Loeschoperationen und die Ermittlung des kanonischen
Pfades nicht. Unter MacOS und XCode 9 werden die Programme von Kapitel
24 gar nicht übersetzt.

