game:
	g++ main.cpp lib/*.cpp -o play -I /usr/local/Cellar/sdl2/2.0.9/include/ -L /usr/local/Cellar/sdl2/2.0.9/lib/ -l SDL2-2.0.0 -lSDL2_image -lgtest -lpthread -std=c++11

INSTALLBINDIR := /usr/local/bin

install:
	cp play $(INSTALLBINDIR)

tests:
	g++ test/main.cpp test/*_test.cpp -o tests -I /usr/local/Cellar/sdl2/2.0.9/include/ -L /usr/local/Cellar/sdl2/2.0.9/lib/ -l SDL2-2.0.0 -lSDL2_image -lgtest -lpthread -std=c++11
