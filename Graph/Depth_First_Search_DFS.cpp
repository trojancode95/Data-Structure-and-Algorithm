//Depth First Search

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
     map<T,list<T>>l;
   public:
     void addEdge(int x,int y){
       l[x].push_back(y);
       l[y].push_back(x);
     }

     void dfs_helper(T source,map<T,bool>&visited){
       //Recursive function that will traverse the Graph
       cout<<source<<" ";
       //Mark this node is visited
       visited[source]=true;
       //Go to all neighbour of that node that is not visited
       for(T neighbour:l[source]){
         if(!visited[neighbour])
         dfs_helper(neighbour,visited);
       }
     }
     void dfs(T source){
       map<T,bool>visited;
       //Mark all the node that is not visited in the beginning.
       for(auto p:l){
         T node=p.first;
         visited[node]=false;
       }
       //Call the dfs dfs_helper function
       dfs_helper(source,visited);
       cout<<endl;
     }
};



int main(){
      Graph<int>g;
      g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,4);
      g.addEdge(4,5);
      g.addEdge(3,0);

      g.dfs(0);


      return 0;
}
