mkbuild: ./build
	mkdir -p ./build

cmake: mkbuild
	cd ./build && cmake ..

build: cmake
	cd ./build && cmake --build .

clean:
	cd ./build && cmake --build . --target clean

tests: build
	cd ./build && ctest -R "test_.*"

all_tests: build
	cd ./build && ctest .
