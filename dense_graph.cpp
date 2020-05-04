#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char* argv[]){
    int numOfNodes = 100, numOfEdges = 0;
	
	int firstNode = 0, secondNode = -1;
	vector<vector<int> > adjList; adjList.resize(numOfNodes);
	
	for(int i=1; i<numOfNodes; i++){
		secondNode = i;
		for(int j=0; j<secondNode; j++){
			firstNode = j;
			adjList[firstNode].push_back(secondNode); 
			numOfEdges++;
		}
	}
	
	streambuf *psbuf, *backup;
	ofstream o;
	o.open(argv[1]);
	backup = cout.rdbuf();
	psbuf = o.rdbuf();
	cout.rdbuf(psbuf);
	
	cout << "0" << endl;
	cout << numOfNodes << " " << numOfEdges << endl;
	for(int i=0; i<adjList.size(); i++){
		for(int j=0; j<adjList[i].size(); j++){
			cout << i << " " << adjList[i][j] << endl;
		}
	}
	
	cout.rdbuf(backup);
	o.close();
}