all: build build/main

build:
	mkdir -p build

clean:
	rm -r build

# Debug
build/main: build/main.o
	g++ build/main.o -o build/main

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o
