CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGETS = TesteFuncional.exe TestePositivos.exe TesteBoundary.exe

all: $(TARGETS)

%.exe: %.cpp ListaSequencial.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	if exist *.exe del *.exe

test: all
	TesteFuncional.exe
	TestePositivos.exe
	TesteBoundary.exe

run-basico: TesteFuncional.exe
	TesteFuncional.exe

run-extremos: TestePositivos.exe
	TestePositivos.exe

run-limites: TesteBoundary.exe
	TesteBoundary.exe

compile-manual:
	g++ -Wall -std=c++11 -o TesteFuncional.exe TesteFuncional.cpp ListaSequencial.cpp
	g++ -Wall -std=c++11 -o TestePositivos.exe TestePositivos.cpp ListaSequencial.cpp
	g++ -Wall -std=c++11 -o TesteBoundary.exe TesteBoundary.cpp ListaSequencial.cpp
