CXX := g++
### Windows 7
ifeq "$(findstring Windows,$(OS))" "Windows"
CXX :=/cygdrive/c/MinGW/bin/g++.exe
endif
CXXFLAGS := -g -Wall -c
INCLUDE := -I.
LDFLAGS := -g 
OBJDIR := obj
BINDIR := bin
DISTDIR := dist
EXEFILE := projekt.exe

objects := $(subst $(SRCDIR),$(OBJDIR),$(cppfiles:.cpp=.o))
deps := $(objects:.o=.d)

.PHONY: all clean dist

all: $(BINDIR)/$(EXEFILE)

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

$(DISTDIR)/gepackt.tar.gz: $(BINDIR)/$(EXEFILE)
	mkdir -p $(DISTDIR)
	tar cvf $(DISTDIR)/gepackt.tar $(BINDIR)/$(EXEFILE)
	gzip $(DISTDIR)/gepackt.tar

dist: $(DISTDIR)/gepackt.tar.gz

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) -rf $(BINDIR)

ultraclean: clean
	$(RM) -rf $(DISTDIR)



