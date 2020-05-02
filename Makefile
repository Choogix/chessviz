g = g++
CFLAGS = -Wall -MP -MMD

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

-include build/test/*.d

GTEST_DIR = thirdparty/googletest

test: testlib ./bin/source-test

testlib:
		$(g) $(CFLAGS) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
		-pthread -c ${GTEST_DIR}/src/gtest-all.cc -o build/test/gtest-all.o
		ar -rv build/test/libgtest.a build/test/gtest-all.o

./bin/source-test: ./build/test/main.o
		$(g) $(CFLAGS) -isystem ${GTEST_DIR}/include -pthread \
		build/test/libgtest.a -o

./build/test/test.o: test/main.cpp
		$(g) $(CFLAGS) -I $(GTEST_DIR)/include -o

clean:
		rm -rf build/*.o build/*.d

run:
		./bin/source
