#include <std.io>
#include <vector>
#include <queue>
using namespace std;

void BFS_mat(int[][] mat, vector<Node*> nodes, int start){
    queue<Node*> q;
    nodes[start] = s;
    s->color = 1;
    s->dist = 0;
    s->parent = NULL;
    q.push(s);

    Node* curr;
    while(!q.empty()){
        curr = q[0];
        
        for(int i = 0; i < mat[].size(); i++){ //check nodes adajcent to current node
            //for(int j = 0; j > mat[][].size(); j++){}

            if(mat[curr][i] == 1 && nodes[i]->color == 0){ //if node is adjacent and not visited
                nodes[i]->color = 1;    //mark node (grey)
                nodes[i]->distance = curr-> + 1;
                nodes[i]->parent = curr;
                q.push(nodes[i]);   //add to queue
            }
        }
        curr->color = 2; //current node has been explored (black)
        q.pop(); //remove current node from queue
    }

    return; //what am i returning??
}
