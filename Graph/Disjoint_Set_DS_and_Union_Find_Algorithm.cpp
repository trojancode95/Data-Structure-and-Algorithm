// A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
// A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
//
// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
//
// Union: Join two subsets into a single subset.
//
// In this post, we will discuss the application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.
//
// Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not.
// Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find.
// This method assumes that the graph doesn’t contain any self-loops.
// We can keep track of the subsets in a 1D array, let’s call it parent[].

//Que Link : https://hack.codingblocks.com/app/contests/537/p/1171
// Q-There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
// You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
// Find out the number of ways in which cities can be chosen.
//
// Input Format:
// The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.
//
// Constraints:
// 1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1
//
// Output Format
// An integer that denotes the number of permissible ways to choose a pair of cities.

// Input :
// 5 3
// 0 1
// 2 3
// 0 4
// Output :- 6
#include<bits/stdc++.h>
using namespace std;

class disjointSetUnion{
public:
    vector<int>parent,sizeOfSuperParent;
    int total_Unconnected_Component;
    //Initialize
    void Initialize(int n){
      parent.resize(n);
      sizeOfSuperParent.resize(n);
      for(int i=0;i<n;i++){
        parent[i]=i;
        sizeOfSuperParent[i]=1;
      }
      total_Unconnected_Component=n;
    }
    //Method to get the SuperParent of any node.
    int get_SuperParent(int x){
      if(x==parent[x])
      return x;

      //Path Compression
      return parent[x]=get_SuperParent(parent[x]);
    }

    void unite(int x,int y){
      int SuperParent_x=get_SuperParent(x);
      int SuperParent_y=get_SuperParent(y);
      if(SuperParent_x!=SuperParent_y){
        parent[SuperParent_x]=SuperParent_y;
        total_Unconnected_Component--;
        sizeOfSuperParent[y]+=sizeOfSuperParent[x];
        sizeOfSuperParent[x]=0;
      }
    }
};


void solve(){
      disjointSetUnion G;
      int n,m;//n cities and m pair
      cin>>n>>m;
      G.Initialize(n);
      for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        G.unite(x,y);
      }
      int ans=0;
      //All elements are in there connected components
      for(int i=0;i<n;i++){
        // i is considered as x
        int SuperParent_i=G.get_SuperParent(i);
        ans+=n-G.sizeOfSuperParent[SuperParent_i];
      }
      cout<<ans/2<<endl;
}
int main(){
     solve();

     return 0;
}
