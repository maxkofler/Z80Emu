all: builddir main.o

	(cd build && g++ -o ../z80.out main.o z80.o iManager.o iSet.o incdecaddsub.o memoryManager.o mainIs.o)
	
	

main.o:	z80.o Z80/log/log.h
	g++ -o build/main.o -c main.cpp

z80.o: Z80/z80.cpp z80.h memoryManager.o iManager.o Z80/log/log.h
	g++ -o build/z80.o -c Z80/z80.cpp

iManager.o: z80.h Z80/log/log.h iSet.o
	g++ -o build/iManager.o -c Z80/iManager/iManager.cpp

mainIs.o: z80.h Z80/log/log.h incdecaddsub.o
	g++ -o build/mainIs.o -c Z80/iManager/iSet/MAINIS/mainIs.cpp

incdecaddsub.o:	z80.h Z80/iManager/iSet/INCDECADDSUB/incdecaddsub.h
	g++ -o build/incdecaddsub.o -c Z80/iManager/iSet/INCDECADDSUB/incdecaddsub.cpp

memoryManager.o: Z80/log/log.h Z80/memoryManager/memoryManager.h
	g++ -o build/memoryManager.o -c Z80/memoryManager/memoryManager.cpp

iSet.o:	z80.h Z80/log/log.h Z80/iManager/iSet/iSet.h mainIs.o
	g++ -o build/iSet.o -c Z80/iManager/iSet/iSet.cpp



builddir:
	@-mkdir build

clean:
	(cd build && rm -rfv *)