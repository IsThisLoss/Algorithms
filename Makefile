mkbuild: ./build
	mkdir -p ./build

build: mkbuild
	cd ./build && cmake .. && cmake --build .

clean:
	cd ./build && cmake --build . --target clean

tests: build
	cd ./build && ctest -R "test_.*"

all_tests: build
	cd ./build && ctest .
