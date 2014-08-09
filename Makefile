all: ./build/Makefile
	@ make -C build

./build/Makefile:
	@ cd build && cmake ..

doc: ./build/doc

./build/doc:
	@ rm -rf ./build/doc
	@ doxygen

FORCE:

distclean:
	@- cd build && cmake ..
	@- make -C build clean || true
	@- rm -rf ./build/*
	@- rm -rf ./build/doc
