#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <queue>

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

vector<pair<int,int> > BFS_list(vector<vector<int> >, vector<Node* >, int);

int main(int argc, char* argv[]){
	int directed = -1; //directed = 1, undirected = 0
    int numOfNodes = -1, numOfEdges = -1;

	int firstNode = -1, secondNode = -1;
	string line;

	ifstream infile(argv[1]);

	getline(infile, line);
	stringstream s1(line);
	s1 >> directed;

	getline(infile, line);
	stringstream s2(line);
	s2 >> numOfNodes >> numOfEdges;

	vector<vector<int> > adjList; adjList.resize(numOfNodes);
	vector<Node *> nodes; nodes.resize(numOfNodes);

	while(getline(infile, line)){
		stringstream s3(line);
		s3 >> firstNode >> secondNode;

		vector<int>::iterator indexFound;

		if(directed==1){
			if(adjList[firstNode].size()==0){
				adjList[firstNode].push_back(secondNode);
			}else{
				indexFound = find(adjList[firstNode].begin(), adjList[firstNode].end(), secondNode);

				if(indexFound==adjList[firstNode].end()){
					adjList[firstNode].push_back(secondNode);
				}
			}
		}else{
			if(adjList[firstNode].size()==0){
				adjList[firstNode].push_back(secondNode);
			}else{
				indexFound = find(adjList[firstNode].begin(), adjList[firstNode].end(), secondNode);

				if(indexFound==adjList[firstNode].end()){
					adjList[firstNode].push_back(secondNode);
				}
			}

			if(adjList[secondNode].size()==0){
				adjList[secondNode].push_back(firstNode);
			}else{
				indexFound = find(adjList[secondNode].begin(), adjList[secondNode].end(), firstNode);

				if(indexFound==adjList[secondNode].end()){
					adjList[secondNode].push_back(firstNode);
				}
			}
		}
	}

	/*for(int i=0; i<adjList.size(); i++){
		cout << "Node: " << i << endl;
		for(int j=0; j<adjList[i].size(); j++){
			cout << adjList[i][j] << endl;
		}
	}*/
  BFS_list(adjList,nodes,1);
}

// vector<pair<int,int> > BFS_mat(int[][] mat, vector<Node*> nodes, int start){
//     for(Node * u: nodes){
//       u->color = 0;//white
//       u->distance = -1;//infinity
//       u->parent = NULL;
//     }
//     vector<pair<int,int> > edgesIncluded;
//     queue<Node*> q;
//     Node * s = nodes[start];
//     s->color = 1;
//     s->distance = 0;
//     s->parent = NULL;
//     s->index = start;
//     q.push(s);
//
//     Node* curr;
//     while(!q.empty()){
//         curr = q.front();
//         q.pop(); //remove current node from queue
//
//         for(int i = 0; i < mat[].size(); i++){ //check nodes adajcent to current node
//             //for(int j = 0; j > mat[][].size(); j++){}
//
//             if(mat[curr->index][i] == 1 && nodes[i]->color == 0){ //if node is adjacent and not visited
//                 nodes[i]->color = 1;    //mark node (grey)
//                 nodes[i]->distance = curr->distance + 1;
//                 nodes[i]->parent = curr;
//                 nodes[i]->index = i;
//                 pair<int,int> BFSedge(curr->index,i);
//                 edgesIncluded.push_back(BFSedge)
//                 q.push(nodes[i]);   //add to queue
//             }
//         }
//         curr->color = 2; //current node has been explored (black)
//
//     }
//
//     return edgesIncluded;
// }

vector<pair<int,int> > BFS_list(vector<vector<int> > adjList, vector<Node* > vertex, int startNode){
  for(Node * u: vertex){
    u->color = 0;//white
    u->distance = -1;//infinity
    u->parent = NULL;
  }
  vector<pair<int,int> > edgesIncluded;
  Node * s = vertex[startNode];
  s->color = 1;//grey
  s->distance = 0;//origin
  s->parent = NULL;
  s->index = startNode;
  queue<Node *> q;
  q.push(s);
  Node * x;
  Node * v;
  while(!q.empty()){
     x = q.front();
    q.pop();
    for(int edge: adjList[x->index]){
      v = vertex[edge];
      if(v->color==0){//white
        v->color=1;//grey
        v->distance = x->distance + 1;
        v->parent = x;
        v->index = edge;
        pair<int,int> BFSedge(x->index,v->index);
        edgesIncluded.push_back(BFSedge);
        q.push(v);
      }
    }
    x->color = 2;//black
  }
  return edgesIncluded;
}

//it = find (myvector.begin(), myvector.end(), 30);
