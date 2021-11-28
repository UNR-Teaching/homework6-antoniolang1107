graph: main.o
	g++ main.o -o graph

main.o: main.cpp graph.h
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o graph