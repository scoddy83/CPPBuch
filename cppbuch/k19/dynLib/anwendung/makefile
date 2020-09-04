.PHONY: run zeigeLibs clean

CXX := g++
CXXFLAGS := -c -g -Wall -std=c++14
LIBPROJEKT := ../libprojekt
LIBDIR := $(LIBPROJEKT)/lib
LDFLAGS := -g -L$(LIBDIR) -lrational
EXE := projekt.exe

$(EXE): main.o
	$(MAKE) -C  $(LIBPROJEKT)
	$(CXX) -o $(EXE) main.o $(LDFLAGS)

main.o: main.cpp  rational.h
	$(CXX) $(CXXFLAGS) main.cpp

# Unix/Linux
zeigeLibs: $(EXE)
ifeq "$(findstring Windows,$(OS))" "Windows"
	@echo ldd nicht vorhanden!
else
ifeq ($(shell uname),Darwin)
	otool -L $(EXE)
else
	ldd $(EXE)
endif
endif

run: $(EXE)
ifeq "$(findstring Windows,$(OS))" "Windows"
ifeq "$(findstring $(subst /,\,$(LIBDIR)),$(PATH))" ""
	@echo Keine Ausfuehrung! $(LIBDIR) muss im Pfad liegen!
else
	$(EXE)
endif
else 
# Mac
ifeq ($(shell uname),Darwin)
	export DYLD_LIBRARY_PATH=$(LIBDIR);./$(EXE)
else
# Linux/Unix
	export LD_LIBRARY_PATH=$(LIBDIR);./$(EXE)
endif
endif

clean:
	rm -f $(EXE) main.o

