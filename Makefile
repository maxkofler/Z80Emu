all:
	g++ -o main.o -c main.cpp

	g++ -o z80.o -c Z80/z80.cpp
	g++ -o iManager.o -c Z80/iManager/iManager.cpp

	g++ -o mainIs.o -c Z80/iManager/iSet/MAINIS/mainIs.cpp
	g++ -o incdecaddsub.o -c Z80/iManager/iSet/INCDECADDSUB/incdecaddsub.cpp

	g++ -o memoryManager.o -c Z80/memoryManager/memoryManager.cpp
	g++ -o iSet.o -c Z80/iManager/iSet/iSet.cpp

	g++ -o main.out main.o z80.o iManager.o iSet.o incdecaddsub.o memoryManager.o mainIs.o
	
	-rm main.o

	-rm z80.o
	-rm iManager.o
	-rm iSet.o
	-rm incdecaddsub.o
	-rm memoryManager.o
	-rm mainIs.o