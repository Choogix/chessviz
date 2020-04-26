g = g++
CFLAGS = -Wall -Werror -MP -MMD

.PHONY: clean run all

all:	./bin/source.exe

-include build/src/*.d

./bin/source.exe: ./build/main.o ./build/draw.o ./build/source.o
		$(g) $(CFLAGS) -o ./bin/source ./build/main.o ./build/source.o ./build/draw.o

./build/main.o: ./src/main.cpp ./src/header.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp

./build/draw.o: ./src/draw.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/draw.o -c ./src/draw.cpp

./build/source.o: ./src/source.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/source.o -c ./src/source.cpp

clean:
		rm -rf build/*.o build/*.d

run:
		./bin/source
