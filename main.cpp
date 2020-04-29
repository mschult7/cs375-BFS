#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main(int argc, char* argv[]){
    int numOfNodes = 0, numOfEdges = 0;
	int firstNode, secondNode;
	string line;
	
	ifstream infile(argv[1]);
	
	getline(infile, line);
	stringstream s(line);
	s >> numOfNodes >> numOfEdges;
	
	while(getline(infile, line)){
		break;
	}
	
	cout << numOfNodes << ", " << numOfEdges << endl;
}