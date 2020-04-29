BFS:	main.o
	g++ main.o -o BFS
	
main.o:	main.cpp
	g++ -c main.cpp

clean:
	rm *.o BFS