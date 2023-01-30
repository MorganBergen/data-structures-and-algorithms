a: main.o IntCell.o
	g++ -std=c++11 -g -Wall main.o IntCell.o -o a

main.o: main.cpp IntCell.h
	g++ -std=c++11 -g -Wall -c main.cpp

IntCell.o: IntCell.cpp IntCell.h
	g++ -std=c++11 -g -Wall -c IntCell.cpp

clean:
	rm *.o a

