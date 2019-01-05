snake:
	g++ main.cpp lib/*.cpp -o snake -lSDL2-2.0.0 -lSDL2_ttf -lSDL2_mixer -lgtest -lpthread -std=c++11

debug:
	g++ -g main.cpp lib/*.cpp -o debug -lSDL2-2.0.0 -lSDL2_ttf -lSDL2_mixer -lgtest -lpthread -std=c++11

INSTALLBINDIR := /usr/local/bin

install:
	cp snake $(INSTALLBINDIR)

test:
	g++ tests/main.cpp tests/*_test.cpp lib/mocks/*.cpp lib/*.cpp -o test -lSDL2-2.0.0 -lSDL2_ttf -lSDL2_mixer -lgtest -lgmock -lpthread -std=c++11
