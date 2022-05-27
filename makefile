all: HW8

HW8: main.o 
	g++ -o HW8 main.o 

main.o: main.cc
	g++ -c main.cc

clean:
	rm *.o HW8 main