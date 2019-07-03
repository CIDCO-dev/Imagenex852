CC=g++
FLAGS=-Wall -O3 -std=c++11

default: dump852 octave-dumper
	echo "Building all"

dump852: prepare
	$(CC) $(FLAGS) -o build/bin/dump852 src/examples/dump852.cpp

octave-dumper: prepare
	$(CC) $(FLAGS) -o build/bin/octave-dumper src/examples/octave-dumper.cpp

imager:
	$(CC) $(FLAGS) $(pkg-config --cflags opencv) src/examples/imager.cpp `pkg-config --libs opencv` -o build/bin/imager

coverage:
	mkdir -p build/coverage || true
	mkdir -p build/coverage/reports || true
	mkdir -p build/coverage/bin || true
	cppcheck --xml --xml-version=2 --enable=all --inconclusive --language=c++ src 2> build/coverage/reports/cppcheck.xml

clean:
	rm -rf build

prepare: clean
	mkdir -p build || true
	mkdir -p build/bin || true
