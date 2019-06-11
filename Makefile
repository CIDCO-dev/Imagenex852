CC=g++
FLAGS=-Wall -O3 -std=c++11

default: prepare
	$(CC) $(FLAGS) -o build/bin/read852 src/read852.cpp
	
clean:
	rm -rf build

prepare: clean
	mkdir -p build || true
	mkdir -p build/bin || true

