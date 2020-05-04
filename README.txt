# CS375 Sec.B1 - Group 8 - Breadth First Search
Group: Matthew Schultz
       Tyler Wellington
       Jesse White

Data Structures:
	adjList: vector<vector<int> > - where each index represents a node and the vector at index represents the adj list of node at index
	adjMatrix: vector<vector<int> > - where each index represents a node and the vector at index represents the adj list of node at index;
					  -> NOTE: non-existing edges are included in this structure as a 0 in the adj list of the node at index
	nodeList: vector<Node *> - list of the nodes with their corresponding index

	runtimeList: vector<int> - stores the runtime in microseconds for each iteration of the BFS search with the list
	runtimeMatrix: vector<int> - stores the runtime microseconds for each iteration of the BFS search with the matrix

	q: queue<Node *> - putting nodes on the queue depending on their color and if they're fully explored or not 
	edgesIncluded: vector<pair<int, int> > - stores the indicies of edges contained in the final BFSTree 
       
To compile the main.cpp: "make" or "make BFS"
To run BFS: ./BFS <input.txt> 0 0
	-> where argv[0] is executable
	-> where argv[1] is your graph text file
	-> where argv[2] is your desired start node (optional: 0 if left blank)
	-> where argv[3] is if you want to print out all the nodes, their edges, distance, and parent (optional: "1" by default, 0 to turn it off)

	-> NOTE: You can change the upperBound of the tester variable in the for loop in main.cpp to increase or deacrease
		 the amount of times you run the search. We had it set to 100 times to get a somewhat concrete average.
		 WARNING: DO NOT EXCEED VALUE OF 100 FOR TESTER.

To compile "dense_graph.cpp" or "sparse_graph.cpp":
	g++ "name_of_generator.cpp"

To run "dense_graph.cpp" or "sparse_graph.cpp":
	./a.out <name_of_output_file.txt>
	-> where argv[0] is the default executable
	-> where argv[1] is the name of your desired output file, where the graph is outputed to
	
	-> Then, pass your generated file into the BFS

	-> NOTE: You can change the numOfNodes in each "dense_graph.cpp" and "sparse_graph.cpp" to create variable graph sizes of n nodes.
