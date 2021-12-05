cmake:
	mkdir -p ./build && cd ./build && cmake ..

build: cmake
	cd ./build && cmake --build .

clean:
	cd ./build && cmake --build . --target clean

tests: build
	cd ./build && ctest
