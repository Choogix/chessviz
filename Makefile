g = g++
CFLAGS = -Wall -Werror

.PHONY: clean open

.bin/board: ./build/main.o ./build/draw.o ./build/source.o
		$(g) $(CFLAGS) -o ./bin/source ./build/main.o ./build/source.o ./build/draw.o -lm

./build/main.o: ./src/main.cpp ./src/header.h
		$(g) $(CFLAGS) -o build/main.o -c src/main.cpp -lm

./build/draw.o: ./src/draw.cpp ./src/header.h build
		$(g) $(CFLAGS) -o ./build/draw.o -c ./src/draw.cpp -lm

./build/source.o: ./src/source.cpp ./src/header.h
		$(g) $(CFLAGS) -o ./build/source.o -c ./src/source.cpp -lm

clean:
		rm -rf build bin

open:
		./bin/source

run:
		./bin/source
