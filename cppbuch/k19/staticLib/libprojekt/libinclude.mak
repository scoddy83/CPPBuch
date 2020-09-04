CXX := g++
ifeq "$(findstring Windows,$(OS))" "Windows"
CXX :=/cygdrive/c/MinGW/bin/g++.exe
endif
CXXFLAGS := -g -Wall -c -std=c++14
INCLUDE := -I.
OBJDIR := obj
LIBDIR := lib
## neu 
LIB := lib/librational.a

objects := $(subst $(SRCDIR), $(OBJDIR), $(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean dist

all: $(LIB)

-include $(deps)

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp 
	mkdir -p $(@D)
	$(CXX) -MM -MG -MT "$@ $(patsubst %.d,%.o,$@)" -MF $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

$(LIB): $(objects)
	mkdir -p $(@D)
	-ar cru $(LIB) $(objects)

clean:
	rm -r -f $(OBJDIR)
	rm -r -f $(LIBDIR)
