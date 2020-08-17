//Dijkstra's Algorithm : It is also known as the single source shortest path Algorithm.
//It is an algorithm for the weighted graph with no negative weight cycle.

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
      unordered_map<T, list<pair<T,int>> > m; // (Source , (Destination,Distance) )

public:
      void addEdge(T u,T v,int distance,bool bidirectional=true){
        m[u].push_back(make_pair(v,distance));
        //If the edge is bidirectional
        if(bidirectional)
        m[v].push_back(make_pair(u,distance));
      }

      void printAdj(){
          //Iterate over all the key value value pairs in the map
          // j refers to key and the value as well
          for(auto j:m){
            cout<<j.first<<"-->";
            //Iterate over the list of cities
            for(auto l:j.second)
            cout<<"("<<l.first<<","<<l.second<<") ";
            cout<<endl;
          }
      }
      void DijkstraSSSP(T sourceNode){
        unordered_map<T,int>distance;
        //Set all distance to infinity
        for(auto j:m)
        distance[j.first]=INT_MAX;

        //Make a set to find out the node with minimum distance
        set<pair<int,T>>s; //Set sorts the element according to the first element , thats why i have kept int as the first parameter
        distance[sourceNode]=0;
        s.insert(make_pair(0,sourceNode));
        while(!s.empty()){
          //Find the pair at the front
          auto p=*(s.begin());
          T node=p.second;
          int nodeDistance=p.first;
          s.erase(s.begin());

          //Iterate over the neighbour/children of current node
          for(auto neighbour:m[node]){
            if(nodeDistance+neighbour.second < distance[neighbour.first]){
              //In the set , Updation of a particle node is not possible
              //So, we have to remove the old pair , and insert the new pair to stimulate Updation
              auto f=s.find(make_pair(distance[neighbour.first],neighbour.first));
              if(f!=s.end())
              s.erase(f);
              //Insert the new pair
              distance[neighbour.first]=nodeDistance+neighbour.second;
              s.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
          }
        }
        //Print Distances to all other nodes
        for(auto d:distance)
        cout<<d.first<<" is located at distance of "<<d.second<<endl;
      }
};



int main(){
      Graph<int>g;
      g.addEdge(1,2,1);
      g.addEdge(1,3,4);
      g.addEdge(2,3,1);
      g.addEdge(3,4,2);
      g.addEdge(1,4,7);

      g.printAdj();
      g.DijkstraSSSP(1);

      Graph<string>India;
      India.addEdge("Amritsar","Delhi",1);
      India.addEdge("Amritsar","Jaipur",4);
      India.addEdge("Jaipur","Delhi",2);
      India.addEdge("Jaipur","Mumbai",8);
      India.addEdge("Bhopal","Agra",2);
      India.addEdge("Mumbai","Bhopal",3);
      India.addEdge("Agra","Delhi",1);

      India.DijkstraSSSP("Amritsar");
}

// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?track=SPC-Graph&batchId=155

// vector <int> dijkstra(vector<vector<int>> g, int src, int V)
// {
//     vector<int>distance(V,INT_MAX);//(node,distance)
//     distance[src]=0;
//
//     set<pair<int,int>>s;//(distance,node)
//     s.insert({0,src});
//
//     while(!s.empty()){
//         auto p=*(s.begin());
//         int nodeDistance=p.first;
//         int node=p.second;
//         s.erase(p);
//         for(int i=0;i<V;i++){
//           if(i==node)
//           continue;
//           else{
//             if(nodeDistance+g[node][i]<distance[i] && g[node][i]){
//               auto f=s.find({distance[i],i});
//               if(f!=s.end())
//               s.erase(f);
//               distance[i]=nodeDistance+g[node][i];
//               s.insert({distance[i],i});
//             }
//           }
//         }
//     }
//     return distance;
// }
