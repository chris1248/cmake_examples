MAKEFLAGS += --no-print-directory
PREFIX_TEST_DIR?=${HOME}/Downloads/hello

generate:
	cmake -S . -B build

binaries: generate
	cmake --build build --target all

install: binaries	
	cmake --install build --prefix ${PREFIX_TEST_DIR}

clobber-install:
	rm -rf ${PREFIX_TEST_DIR}


dump-package: build
	dpkg-deb --contents bin/packages/hello-0.1.0.deb