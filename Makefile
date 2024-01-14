# all: build build/lib
all: build build/debug

build:
	mkdir -p build

clean:
	rm -r build

# Debug
build/debug: build/debug.o
	g++ build/debug.o -o build/debug

build/debug.o: src/debug.cpp
	g++ -c src/debug.cpp -o build/debug.o
