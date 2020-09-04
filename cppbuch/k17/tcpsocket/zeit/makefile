include ../../../make/mf_alle
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -lpthread -lboost_system  -lboost_thread
ifeq "$(findstring Windows,$(OS))" "Windows"
LDFLAGS+=-lWs2_32
endif


