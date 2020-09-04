CXX := g++
ifeq "$(findstring Windows,$(OS))" "Windows"
CXX :=/cygdrive/c/MinGW/bin/g++.exe
endif

CXXFLAGS := -g -Wall -c -std=c++14
# Festlegen der Verzeichnisnamen
SRCDIR := src
OBJDIR := obj
BINDIR := bin
EXEFILE := projekt.exe

cppfiles := $(wildcard $(SRCDIR)/*.cpp)
objects := $(subst $(SRCDIR)/, $(OBJDIR)/, $(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean

all:  $(BINDIR)/$(EXEFILE)
-include $(deps)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	mkdir -p $(@D)
	$(CXX) -MM -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo compiling  $< ...
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(BINDIR)/$(EXEFILE): $(objects)
	mkdir -p $(BINDIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) -r  $(OBJDIR)
	$(RM) -r  $(BINDIR)
