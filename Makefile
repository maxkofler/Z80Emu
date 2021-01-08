all:
	g++ -o main.o -c main.cpp
	g++ -o iManager.o -c Z80/iManager/iManager.cpp

	g++ -o main.out main.o
	-rm main.o