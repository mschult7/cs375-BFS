#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
#include<chrono>

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
vector<pair<int,int> > BFS_mat(vector<vector<int> >, vector<Node* >, int);

int main(int argc, char* argv[]){
  vector<int> runtimeList; runtimeList.resize(100);
  vector<int> runtimeMatrix; runtimeMatrix.resize(100);

  // int qez =0;
  // for(int i=1;i<101;i++){
  //   cout << qez << " " << i << endl;
  //   if(i%2==0){
  //     qez++;
  //   }
  //

  //}

  for(int tester=0;tester<100;tester++){
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

    vector<vector<int> > matrix; matrix.resize(numOfNodes);

    for(int i=0; i<nodes.size(); i++){
      nodes[i] = new Node();
      matrix[i].resize(numOfNodes);
    }

    while(getline(infile, line)){
      stringstream s3(line);
      s3 >> firstNode >> secondNode;
	  
	  if(secondNode == -1) continue;

      vector<int>::iterator indexFound;

      if(directed==1){
        matrix[firstNode][secondNode] = 1;

        if(adjList[firstNode].size()==0){
          adjList[firstNode].push_back(secondNode);
        }else{
          indexFound = find(adjList[firstNode].begin(), adjList[firstNode].end(), secondNode);

          if(indexFound==adjList[firstNode].end()){
            adjList[firstNode].push_back(secondNode);
          }
        }
      }else{
        matrix[firstNode][secondNode] = 1;
        matrix[secondNode][firstNode] = 1;

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

vector<pair<int,int>>BFSTree_List;
vector<pair<int,int>>BFSTree_Mat;

auto start = chrono::steady_clock::now();
if(directed==0){
  BFSTree_List = BFS_list(adjList,nodes,0);
} else if(directed==1){
  BFSTree_List = BFS_list(adjList,nodes,0);
}
auto end = chrono::steady_clock::now();
int printBFSTree = 1;
if(argv[2]!=NULL){
  printBFSTree = stoi(argv[2]);
}

cout << "--------- BFS with adjacency list ---------" << endl;
if(printBFSTree){

  for(int i=0; i<nodes.size(); i++){
    cout << "Node: " << i << endl;
    cout << "distance: " << nodes[i]->distance << endl;
    if(nodes[i]->parent != NULL){
      cout << "parent: " << nodes[i]->parent->index << endl;
    } else {
      cout << "parent: NULL //This is the start Node" << endl;
    }

    cout << "edges: " << endl;
    for(int j=0; j<BFSTree_List.size(); j++){
      if(BFSTree_List[j].first == i ){
        cout << BFSTree_List[j].second << endl;
      }else if ( BFSTree_List[j].second == i && directed==0 ) {
        cout << BFSTree_List[j].first << endl;
      }
    }
  }
}

runtimeList[tester] = (chrono::duration_cast<chrono::microseconds>(end - start).count());
cout << "Microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;

cout << "---------------------------------------------" << endl;
cout << "--------- BFS with adjacency Matrix ---------" << endl;

start = chrono::steady_clock::now();
if(directed==0){
  BFSTree_Mat = BFS_mat(matrix,nodes,0);
} else if(directed==1){
  BFSTree_Mat = BFS_mat(matrix,nodes,0);
}
end = chrono::steady_clock::now();

if(printBFSTree){
  for(int i=0; i<nodes.size(); i++){
    cout << "Node: " << i << endl;
    cout << "distance: " << nodes[i]->distance << endl;
    if(nodes[i]->parent != NULL){
      cout << "parent: " << nodes[i]->parent->index << endl;
    } else {
      cout << "parent: NULL //This is the start Node" << endl;
    }

    cout << "edges: " << endl;
    for(int j=0; j<BFSTree_Mat.size(); j++){
      if(BFSTree_Mat[j].first == i ){
        cout << BFSTree_Mat[j].second << endl;
      }else if ( BFSTree_Mat[j].second == i && directed==0 ) {
        cout << BFSTree_Mat[j].first << endl;
      }
    }
  }

}
runtimeMatrix[tester] = (chrono::duration_cast<chrono::microseconds>(end - start).count());

cout << "Microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
cout << "---------------------------------------------" << endl;
}
int nList = runtimeList.size();
double averagel = 0.0;
for(int i=0;i<nList;i++){
  averagel += runtimeList[i];
}
averagel = averagel/nList;

int nMat = runtimeMatrix.size();
double averagem = 0.0;
for(int i=0;i<nMat;i++){
  averagem += runtimeMatrix[i];
}
averagem = averagem/nMat;


cout << "average adjList: " << averagel << endl;
cout << "average adjMatrix: " << averagem  << endl;
}

vector<pair<int,int> > BFS_mat(vector<vector<int> > matrix, vector<Node*> nodes, int start){
  for(Node * u: nodes){
    u->color = 0;//white
    u->distance = -1;//infinity
    u->parent = NULL;
  }
  vector<pair<int,int> > edgesIncluded;
  queue<Node*> q;
  Node * s = nodes[start];
  s->color = 1;
  s->distance = 0;
  s->parent = NULL;
  s->index = start;
  q.push(s);

  Node* curr;
  while(!q.empty()){
    curr = q.front();
    q.pop(); //remove current node from queue

    for(int i = 0; i < matrix.size(); i++){ //check nodes adajcent to current node
      //for(int j = 0; j > mat[][].size(); j++){}

      if(matrix[curr->index][i] == 1 && nodes[i]->color == 0){ //if node is adjacent and not visited
        nodes[i]->color = 1;    //mark node (grey)
        nodes[i]->distance = curr->distance + 1;
        nodes[i]->parent = curr;
        nodes[i]->index = i;
        pair<int,int> BFSedge(curr->index,i);
        edgesIncluded.push_back(BFSedge);
        q.push(nodes[i]);   //add to queue
      }
    }
    curr->color = 2; //current node has been explored (black)

  }

  return edgesIncluded;
}

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
