all: builddir

	g++ -o build/z80.o -c Z80/z80.cpp
	g++ -o build/iManager.o -c Z80/iManager/iManager.cpp
	g++ -o build/mainIs.o -c Z80/iManager/iSet/MAINIS/mainIs.cpp
	g++ -o build/incdecaddsub.o -c Z80/iManager/iSet/INCDECADDSUB/incdecaddsub.cpp
	g++ -o build/memoryManager.o -c Z80/memoryManager/memoryManager.cpp
	g++ -o build/iSet.o -c Z80/iManager/iSet/iSet.cpp
	g++ -o build/rotate.o -c Z80/iManager/iSet/rotate/rotate.cpp

	g++ -o build/main.o -c main.cpp

	(cd build && g++ -o ../z80.out main.o z80.o iManager.o iSet.o incdecaddsub.o memoryManager.o mainIs.o rotate.o)


builddir:
	@-mkdir build

clean:
	(cd build && rm -rfv *)