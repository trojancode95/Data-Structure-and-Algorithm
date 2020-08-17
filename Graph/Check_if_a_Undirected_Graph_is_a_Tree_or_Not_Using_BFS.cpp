//Cycle Detection in a Unirected Graph using BFS Approach

#include<bits/stdc++.h>
using namespace std;

//Check if a Undirected Graph is a Tree or Not.
//If a Graph contains a cycle , then it is tree ,else it is a tree.
//If a node is visited by more than one path, then it contains a cycle.
class Graph{

      list<int>*l;
      int V;
    public:
      Graph(int V){
        this->V=V;
        l=new list<int>[V];
      }
      void addEdge(int x,int y){
        //Undirected Graph
        l[x].push_back(y);
        l[y].push_back(x);
      }
      bool is_tree(){
        bool *visited=new bool[V];
        int *parent=new int[V];

        queue<int>q;

        for(int i=0;i<V;i++){
          visited[i]=false;
          parent[i]=i;
        }
        int sourceNode=0;
        q.push(sourceNode);
        visited[sourceNode]=true;

        //Pop out the one node and visits its neighbour
        while(!q.empty()){
          int node=q.front();
          q.pop();

          for(int neighbour:l[node]){
            if(visited[neighbour]==true && parent[node]!=neighbour)
            return false;
            else if(!visited[neighbour]){
              q.push(neighbour);
              visited[neighbour]=true;
              parent[neighbour]=node;
            }
          }
        }
        return true;
      }
};


int main(){

      Graph g(4);
      g.addEdge(0,1);
      g.addEdge(3,2);
      g.addEdge(1,2);
      g.addEdge(0,3);

      if(g.is_tree())
      cout<<"The Given Undirected Graph is a Tree"<<endl;
      else
      cout<<"The Given Undirected Graph is not a Tree"<<endl;

      return 0;
}
