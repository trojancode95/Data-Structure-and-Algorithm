//Cycle Detection in a Directed Graph using DFS Approach
//If a graph has a back edge, then it contains a cycle. Back edge is a node to its ancestor from the same path.

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
        //Directed Graph
        l[x].push_back(y);
      }

      bool cycle_Helper(int node,bool *visited,bool *stack){
        //When you visit a node
        visited[node]=true;
        stack[node]=true;

        for(int neighbour:l[node]){
          //Two Cases
          if(stack[neighbour]==true)
          return true;

          else if(visited[neighbour]==false){
            bool cycle_mila=cycle_Helper(neighbour,visited,stack);
            if(cycle_mila==true)
            return true;
          }
        }

        //Leave a node
        stack[node]=false;
        return false;
      }


      //Checks for cycle in Directed Graph
      bool contains_Cycle(){
        bool *visited=new bool[V];
        bool *stack=new bool[V];

        for(int i=0;i<V;i++)
        visited[i]=stack[i]=false;

        return cycle_Helper(0,visited,stack);
      }
};


int main(){

      Graph g(7);
      g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,4);
      g.addEdge(4,5);
      g.addEdge(1,5);
      g.addEdge(5,6);
      g.addEdge(4,2);//Back Edge

      if(g.contains_Cycle())
      cout<<"The Given Directed Graph contains a cycle."<<endl;
      else
      cout<<"The Given Directed Graph do not contains a cycle."<<endl;

      return 0;
}
