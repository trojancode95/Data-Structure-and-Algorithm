//TopologicalSort Using BFS Approach

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

      void topologicalSort(){
        //indegree : incoming nodes
        int *indegree=new int[V];
        //Initialize all the indegree with 0.
        for(int i=0;i<V;i++)
        indegree[i]=0;

        //Update indegree by traversing edges x->y
        //indegree[y]++;
        for(int i=0;i<V;i++){
          for(auto y:l[i])
          indegree[y]++;
        }
        //Now, we have to apply BFS
        queue<int>q;
        //Step 1. Find nodes with 0 indegree
        for(int i=0;i<V;i++){
          if(indegree[i]==0)
          q.push(i);
        }
        while(!q.empty()){
          int node=q.front();
          cout<<node<<" ";
          q.pop();
          //Iterate over the neighbour of that node and reduce its indegree by 1.
          for(auto neighbour:l[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            q.push(neighbour);
          }
        }
        cout<<endl;
      }
};


int main(){

      Graph g(6);
      g.addEdge(0,2);
      g.addEdge(1,2);
      g.addEdge(1,4);
      g.addEdge(2,3);
      g.addEdge(2,5);
      g.addEdge(3,5);
      g.addEdge(4,5);

      g.topologicalSort();

      return 0;
}
