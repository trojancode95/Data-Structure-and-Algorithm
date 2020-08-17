//Distance calculated by bfs or level order traversal is the shortest
//Unweighted Graph

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
     void singleSourceShortestPath(T sourceNode){
       map<T,int>distance;
       queue<T>q;
       // All other nodes will have INT_MAX distance
       for(auto node_pair:l){
         T node=node_pair.first;
         distance[node]=INT_MAX;
       }
       q.push(sourceNode);
       distance[sourceNode]=0;
       while(!q.empty()){
         T node=q.front();
         q.pop();
         for(int neighbour:l[node]){
           if(distance[neighbour]==INT_MAX){
             q.push(neighbour);
             //Mark that node as visited
             distance[neighbour]=distance[node]+1;
           }
         }
       }
       //Print the distance to every node
       for(auto node_pair:l){
         T node=node_pair.first;
         int d=distance[node];
         cout<<"Node "<<node<<" is at a distance "<<d<<" from source"<<endl;
       }
     }
};



int main(){
      Graph<int>g;
      g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,0);
      g.addEdge(3,4);
      g.addEdge(4,5);

      g.singleSourceShortestPath(0);


    return 0;
}
