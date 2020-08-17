//Distance calculated by bfs or level order traversal is the shortest
//Unweighted Graph

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
     map<T,list<T>>l;
   public:
     //Directed Edges
     void addEdge(int x,int y){
       l[x].push_back(y);
     }
     int singleSourceShortestPath(T sourceNode,T destination){
       map<T,int>distance;
       map<T,T>parent;
       queue<T>q;
       // All other nodes will have INT_MAX distance
       for(auto node_pair:l){
         T node=node_pair.first;
         distance[node]=INT_MAX;
       }
       q.push(sourceNode);
       distance[sourceNode]=0;
       parent[sourceNode]=sourceNode;
       while(!q.empty()){
         T node=q.front();
         q.pop();
         for(int neighbour:l[node]){
           if(distance[neighbour]==INT_MAX){
             q.push(neighbour);
             parent[neighbour]=node;
             //Mark that node as visited
             distance[neighbour]=distance[node]+1;
           }
         }
       }
       //Destination to source
       T temp=destination;
       while(temp!=sourceNode){
         cout<<temp<<"<--";
         temp=parent[temp];
       }
       cout<<sourceNode<<endl;
       
       //Print the distance from source to destination
       return distance[destination];
     }
};



int main(){


      //Input
      int board[50]={0};
      //Snakes and Ladder
      board[2]=13;
      board[5]=2;
      board[9]=18;
      board[18]=11;
      board[17]=-13;
      board[20]=-14;
      board[24]=-8;
      board[25]=10;
      board[32]=-2;
      board[34]=-22;

      //Add Edges to the Graph
      Graph<int>g;
      for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
          int location=i+dice;
          location+=board[location];
          if(location<=36)
          g.addEdge(i,location);//Directed Edges
        }
      }
      g.addEdge(36,36);

      int distance = g.singleSourceShortestPath(0,36);
      cout<<distance<<endl;

      return 0;
}
