prog: main.o
	g++ -g -Wall -std=c++11 main.o -o prog

main.o: main.cpp
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o prog
