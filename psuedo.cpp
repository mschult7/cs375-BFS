
//Start BFS at the Sth node in Graph G
BFS(Graph G, int s){
  for each Node u: G.V{
    u->color = white;
    u->dist = inf;
    u->parent = NULL;
  }
  G.V[s]->color = grey;
  G.V[s]->dist = 0;
  G.V[s]->parent = NULL;
  List<Node> queue;
  Enqueue(queue,G.V[s]);
  while(!queue.empty()){
    Node x = queue.pop();
    for each Node v: adj[x]{
      if(v->color == white){
        v->color = grey;
        v->dist = x->dist + 1;
        v->parent = x;
        Enqueue(queue,v);
      }
    }
    x->color = black;
  }
}
