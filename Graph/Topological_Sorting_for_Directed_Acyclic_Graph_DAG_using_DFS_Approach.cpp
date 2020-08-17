//TopologicalSort Using DFS Approach

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
     map<T,list<T>>l;
   public:
     //Directed Graph
     void addEdge(T x,T y){
       l[x].push_back(y);
     }

     void dfs_helper(T source,map<T,bool>&visited,list<T>&ordering){
       //Recursive function that will traverse the Graph


       //Mark this node is visited
       visited[source]=true;
       //Go to all neighbour of that node that is not visited
       for(T neighbour:l[source]){
         if(!visited[neighbour])
         dfs_helper(neighbour,visited,ordering);
       }
       ordering.push_front(source);
     }

     void dfs(){
       map<T,bool>visited;
       list<T>ordering;
       //Mark all the node that is not visited in the beginning.
       for(auto p:l){
         T node=p.first;
         visited[node]=false;
       }
       //Iterate over all the vertices and initiate a dfs Call
       for(auto p:l){
         T node=p.first;
         if(!visited[node]){
           dfs_helper(node,visited,ordering);
         }
       }
       //Finally return the list or print the list
       for(auto node:ordering)
       cout<<node<<" ";
       cout<<endl;
     }
};



int main(){
      Graph<string>g;
      g.addEdge("Python","DataPreProcessing");
      g.addEdge("Python","PyTorch");
      g.addEdge("Python","ML");
      g.addEdge("DataPreProcessing","ML");
      g.addEdge("PyTorch","DL");
      g.addEdge("ML","DL");
      g.addEdge("DL","FaceRecognition");
      g.addEdge("DataSet","FaceRecognition");

      g.dfs();


      return 0;
}
