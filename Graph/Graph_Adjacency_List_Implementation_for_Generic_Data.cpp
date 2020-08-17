#include <bits/stdc++.h>
using namespace std;

//Weighted Graph
class Graph{
    //Adjacency List
    unordered_map<string,list<pair<string,int>> >l;
public:
    void addEdge(string x,string y,bool bidirectional,int weight){
      l[x].push_back(make_pair(y,weight));

      if(bidirectional)
      l[y].push_back(make_pair(x,weight));
    }

    void printAdjList(){
      //Iterate over all the key in the map
      for(auto x:l){
        string city=x.first;
        list<pair<string,int>>neighbours=x.second;
        //y.first is the destination and y.second is the distance from the city
        for(auto y:neighbours)
        cout<<city<<"<-----"<<y.second<<"----->"<<y.first<<endl;
      }
    }
};



int main(){

    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,30);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();

    return 0;
}
