//Breadth First Search
//Traversing all the nodes of the graph.
//Recursive way
//It is like a level order traversal of all the node i.e same level means same distance from the source node.
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
     void bfs(T sourceNode){
       map<T,int>visited;
       queue<T>q;
       q.push(sourceNode);
       visited[sourceNode]=true;
       while(!q.empty()){
         T node=q.front();
         q.pop();
         cout<<node<<" ";
         for(int neighbour:l[node]){
           if(!visited[neighbour]){
             q.push(neighbour);
             //Mark that node as visited
             visited[neighbour]=true;
           }
         }
       }
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

  g.bfs(0);


    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

vector <int> bfs(vector<int> g[], int N) {
    vector <bool> vis (N, false);
    int s = 0;
    vis[s] = true; // Initially mark source vertex as visited(true)
    vector <int> res;
    queue<int> q;
    q.push(s); // Push the source vertex to queue

    while (!q.empty()) // Till queue is not empty
    {
        int t = q.front();
        res.push_back (t);

        q.pop(); // Pop the queue front

        for (int v :
             g[t]) // Traverse through all the connected components of front
        {
            if (!vis[v]) { // If they are not visited, mark them visited and add
                           // to queue
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return res;
}


int main(){
    int t;
    cin>>t;
    while(t--){
      int n,e;
      cin>>n>>e;
      vector<int>adj[n];
      for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      vector<int>res=bfs(adj,n);
      for(int i=0;i<res.size();i++)
      cout<<res[i]<<" ";
      cout<<endl;
    }
    return 0;
}
*/
