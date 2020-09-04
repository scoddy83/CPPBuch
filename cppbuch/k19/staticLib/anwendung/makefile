.PHONY: clean

CXX := g++
CXXFLAGS := -c -g -Wall -std=c++14
LIBPROJEKT := ../libprojekt
LIBDIR := $(LIBPROJEKT)/lib
LDFLAGS := -g -static -L$(LIBDIR) -lrational # ggf. -Bstatic probieren

projekt.exe: main.o
# Mac
ifeq ($(shell uname),Darwin)
	$(MAKE) -C  $(LIBPROJEKT)
	@echo static wird von Apple NICHT unterstuetzt! Siehe README.txt
else
	$(MAKE) -C  $(LIBPROJEKT)
	$(CXX) -o projekt.exe main.o $(LDFLAGS)
endif
main.o: main.cpp  rational.h
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -f projekt.exe main.o

