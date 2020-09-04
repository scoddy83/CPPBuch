CXX :=g++
CXXFLAGS := -Wall -c -pedantic
LDFLAGS := -g
### Windows
ifeq "$(findstring Windows,$(OS))" "Windows"
CXXFLAGS+=-DWIN32 -std=c++17  -fmax-errors=1
####   ANPASSEN, falls keine Standardinstallation: ####
# diese Variablen werden in manchen Makefiles, die dieses Makefile 
# einschliessen,  benoetigt 
BOOSTINCLUDE=C:/MinGW/boost/include/boost
BOOSTLIBDIR=C:/MinGW/boost/lib
####  Ende Anpassungsbereich             ####
else
# Unix/Linux/Mac
OS:=$(shell uname)
ifeq "$(findstring Darwin,$(OS))" "Darwin"
### Mac
CXXFLAGS+=-std=c++1z  -ferror-limit=1
else
### Linux/Unix
CXXFLAGS+= -fdiagnostics-color=auto -std=c++17  -fmax-errors=1
endif
####   ANPASSEN:    ####
# diese Variablen werden in manchen Makefiles, die dieses Makefile 
# einschliessen, benoetigt. GGf. anpassen 
BOOSTINCLUDE=/usr/local/include
# bei Bedarf hinzufügen:
BOOSTLIBDIR=/usr/local/lib
####  Ende Anpassungsbereich             ####
endif
