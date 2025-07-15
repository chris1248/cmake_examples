MAKEFLAGS += --no-print-directory
PREFIX_TEST_DIR?=${HOME}/Downloads/hello

generate:
	cmake -S . -B build

binaries: generate
	cmake --build build --target all

install: binaries	
	cmake --install build --prefix ${PREFIX_TEST_DIR}

package: binaries
	@echo "-------------------------------------------------------"
	@cmake --build build --target package
	@dpkg-deb --contents bin/packages/hello-0.1.0.deb

install-package: package
	@echo "-------------------------------------------------------"
	sudo dpkg -i bin/packages/hello-0.1.0.deb
	@echo "Package installed successfully."

remove-package:
	sudo dpkg -r hello
	@echo "Package removed successfully."

clobber-install:
	rm -rf ${PREFIX_TEST_DIR}


dump-package: build
	dpkg-deb --contents bin/packages/hello-0.1.0.deb