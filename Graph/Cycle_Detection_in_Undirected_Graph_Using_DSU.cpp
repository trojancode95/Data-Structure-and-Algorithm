//Cycle Detection in Undirected Graph using Disjoint Set Union

// Let's make a simple graph
// 4 4
// 1 2
// 2 3
// 3 4
// 1 4


#include<bits/stdc++.h>
using namespace std;

class disjointSetUnion{
public:
    vector<int>parent;
    void Initialize(int n){
      parent.clear();
      parent.resize(n);
      iota(parent.begin(),parent.end(),0);
    }
    int get_SuperParent(int x){
      return (x==parent[x]?x:(parent[x]=get_SuperParent(parent[x])));
    }
    void unite(int x,int y){
      x=get_SuperParent(x);
      y=get_SuperParent(y);
      if(x!=y)
      parent[x]=y;
    }
};


void detectCycle(){
      bool cycle=false;
      int n,m;
      cin>>n>>m;// n number of nodes and m pairs
      disjointSetUnion G;
      G.Initialize(n);//0 --> n-1
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;//0 based indexing
        y--;//0 based indexing
        if(G.get_SuperParent(x)!=G.get_SuperParent(y)){
          //Different connected components
          G.unite(x,y);
        }
        else{
          // Same components
          //There was a path from x to y, so there is a cycle.
          cycle=true;
        }
      }
      if(cycle)
      cout<<"Graph contains a cycle"<<endl;
      else
      cout<<"Graph do not contains a cycle"<<endl;
}

int main(){
     detectCycle();

     return 0;
}
