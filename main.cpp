#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

class Node{
	public:
		int index;
		int color; //0 = white, 1 = grey, 2 = black
		int distance;
		Node * parent;
		
		Node(){
			index = -1;
			color = 0;
			distance = -1;
			parent = NULL;
		}
};

int main(int argc, char* argv[]){
	bool directed = false; //directed = true, undirected = false
    int numOfNodes = 0, numOfEdges = 0;
	
	int firstNode = 0, secondNode = 0;
	string line;

	ifstream infile(argv[1]);

	getline(infile, line);
	stringstream s(line);
	s >> directed;
	
	getline(infile, line);
	stringstream s2(line);
	s >> numOfNodes >> numOfEdges;
	
	vector<vector<int> > adjList;

	while(getline(infile, line)){
		stringstream s3(line);
		
		
	}

	cout << directed << "\n" << numOfNodes << ", " << numOfEdges << endl;
}
