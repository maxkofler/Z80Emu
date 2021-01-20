all: builddir

	g++ -std=c++17 -o build/z80.o -c Z80/z80.cpp
	g++ -std=c++17 -o build/iManager.o -c Z80/iManager/iManager.cpp

	g++ -std=c++17 -o build/mainIs.o -c Z80/iManager/iSet/MAINIS/mainIs.cpp
	g++ -o build/bitIs.o -c "Z80/iManager/iSet/BIT/bitIS.cpp"


	g++ -std=c++17 -o build/incdecaddsub.o -c Z80/iManager/iSet/incdecaddsub/incdecaddsub.cpp
	g++ -std=c++17 -o build/memoryManager.o -c Z80/memoryManager/memoryManager.cpp
	g++ -std=c++17 -o build/iSet.o -c Z80/iManager/iSet/iSet.cpp
	g++ -std=c++17 -o build/rotate.o -c Z80/iManager/iSet/rotate/rotate.cpp
	g++ -std=c++17 -o build/arithmetic.o -c Z80/iManager/iSet/arithmetic/arithmetic.cpp
	g++ -std=c++17 -o build/cpuctl.o -c Z80/iManager/iSet/cpuctl/cpuctl.cpp

	g++ -std=c++17 -o build/main.o -c main.cpp

	(cd build && g++ -std=c++17 -o ../z80.out main.o z80.o iManager.o iSet.o incdecaddsub.o memoryManager.o mainIs.o bitIs.o rotate.o arithmetic.o cpuctl.o)


builddir:
	@-mkdir build

clean:
	(cd build && rm -rfv *)