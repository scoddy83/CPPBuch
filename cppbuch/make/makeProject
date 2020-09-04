CPPBUCH_HOME=$(subst /make/makeProject,,$(lastword $(MAKEFILE_LIST)))
# Compiliert und linkt alle .cpp-Dateien im aktuellen Verzeichnis als Projekt,
# d.h. es gibt danach EIN ausfuehrbares Programm, so dass es nur exakt EIN 
# main-Programm im Verzeichnis geben darf
INCLUDE := -I$(CPPBUCH_HOME)/include
include $(CPPBUCH_HOME)/make/einstellungen.mak


EXE ?= projekt.exe

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
HEADERS := $(wildcard *.h)
TEMPLATES := $(wildcard *.t)
.PHONY: clean

$(EXE): $(OBJS)
	-$(CXX) -o $@ $(OBJS) $(LDFLAGS)

$(OBJS): %.o : %.cpp  $(HEADERS) $(TEMPLATES)
	-$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJS) $(EXE)

