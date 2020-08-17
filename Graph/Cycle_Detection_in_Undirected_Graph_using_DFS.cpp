//Cycle Detection in a Undirected Graph using DFS Approach
//If a node is visited more than one time,then it contains a cycle.


#include<bits/stdc++.h>
using namespace std;


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

      bool cycle_Helper(int node,bool *visited,int parent){
        visited[node]=true;
        for(auto neighbour:l[node]){
          //Two cases
          if(!visited[neighbour]){
            //Go and recursively visits its neighbour
            bool cycle_mila=cycle_Helper(neighbour,visited,node);
            if(cycle_mila)
            return true;
          }
          //This is the case when neighbour is visited but neighbour should not be equal to parent.
          else if(neighbour!=parent)
          return true;
        }
        return false;
      }


      //Checks for cycle in Undirected Graph
      bool contains_Cycle(){
        bool *visited=new bool[V];

        for(int i=0;i<V;i++)
        visited[i]=false;

        return cycle_Helper(0,visited,-1);
      }
};


int main(){

      Graph g(5);
      g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,4);
      g.addEdge(4,0);

      if(g.contains_Cycle())
      cout<<"The Given Undirected Graph contains a cycle."<<endl;
      else
      cout<<"The Given Undirected Graph do not contains a cycle."<<endl;

      return 0;
}
