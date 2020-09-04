all: rvo.exe norvo.exe

rvo.exe: main.cpp einfacherstring.h
	g++ $(CXXFLAGS) -o rvo.exe main.cpp 

norvo.exe: main.cpp einfacherstring.h
	g++ $(CXXFLAGS) -fno-elide-constructors -o norvo.exe main.cpp 

clean:
	rm -f rvo.exe norvo.exe


