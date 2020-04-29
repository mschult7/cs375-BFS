BFS:	main.o
	g++ main.o -o BFS

main.o:	main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o BFS
