EXE=get.exe
include ../../../make/makeProject
INCLUDE+=-I$(BOOSTINCLUDE)
LDFLAGS+=-L$(BOOSTLIBDIR) -lpthread -lboost_system -lboost_thread -lpthread
ifeq "$(findstring Windows,$(OS))" "Windows"
LDFLAGS+=-lWs2_32
endif


