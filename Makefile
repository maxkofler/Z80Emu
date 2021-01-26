all: builddir

	g++ -o build/z80.o -c Z80/z80.cpp
	g++ -o build/iManager.o -c Z80/iManager/iManager.cpp

	g++ -std=c++17 -o build/mainIs.o -c Z80/iManager/iSet/MAINIS/mainIs.cpp
	g++ -o build/bitIs.o -c Z80/iManager/iSet/BIT/bitIS.cpp
	g++ -o build/ixcb.o -c Z80/iManager/iSet/IXCB/ixcb.cpp
	g++ -o build/iycb.o -c Z80/iManager/iSet/IYCB/iycb.cpp


	g++ -o build/incdecaddsub.o -c Z80/iManager/iSet/incdecaddsub/incdecaddsub.cpp
	g++ -o build/memoryManager.o -c Z80/memoryManager/memoryManager.cpp
	g++ -o build/iSet.o -c Z80/iManager/iSet/iSet.cpp

	g++ -o build/rotate.o -c Z80/iManager/iSet/rotate/rotate.cpp
	g++ -o build/arithmetic.o -c Z80/iManager/iSet/arithmetic/arithmetic.cpp
	g++ -o build/cpuctl.o -c Z80/iManager/iSet/cpuctl/cpuctl.cpp
	g++ -o build/bit.o -c Z80/iManager/iSet/bit/bit.cpp

	g++ -o build/main.o -c main.cpp

	(cd build && g++ -o ../z80.out main.o z80.o iManager.o iSet.o incdecaddsub.o memoryManager.o mainIs.o bitIs.o ixcb.o iycb.o rotate.o arithmetic.o cpuctl.o bit.o)


builddir:
	@-mkdir build

clean:
	(cd build && rm -rfv *)