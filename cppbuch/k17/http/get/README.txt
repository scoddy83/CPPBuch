Wenn Sie eine Integrierte Entwicklungsumgebung (IDE) benutzen,
vergessen Sie nicht, Boost bekannt zu machen, indem Sie bei
Project - Build options Folgendes eintragen:

Search Directories / Compiler: $(BOOSTINCLUDE)
Search Directories / Linker  :   $(BOOSTLIBDIR)

Linker settings    / Link libraries: 
boost_thread
boost_system
pthread


