a: main.o MyNumber.o
	g++ -std=c++11 -g -Wall main.o MyNumber.o -o a

main.o: main.cpp MyNumber.h
	g++ -std=c++11 -g -Wall -c main.cpp

MyNumber.o: MyNumber.cpp MyNumber.h
	g++ -std=c++11 -g -Wall -c MyNumber.cpp

clean:
	rm *.o a

