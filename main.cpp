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
	int directed = 0; //directed = 1, undirected = 0
    int numOfNodes = 0, numOfEdges = 0;
	
	int firstNode = 0, secondNode = 0;
	string line;

	ifstream infile(argv[1]);

	getline(infile, line);
	directed = stoi(line);
	
	getline(infile, line);
	stringstream s(line);
	s >> numOfNodes >> numOfEdges;
	
	vector<vector<int> > adjList;
	vector<Node *> nodes; nodes.resize(numOfNodes);

	while(getline(infile, line)){
		stringstream s2(line);
		
		s2 >> firstNode >> secondNode;
		
		if(directed==1){
			
		}else{
			if()
		}
	}
	
	
}
