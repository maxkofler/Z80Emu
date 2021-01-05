all:
	g++ -o main.o -c main.cpp

	g++ -o main.out main.o
	-rm main.o