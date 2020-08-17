#include<bits/stdc++.h>
using namespace std;

//By default of the priority_queue is max heap..
int connectTheRopesWithMinimumCost(vector<int> &ropes){
    priority_queue<int,vector<int>,greater<int>> pq(ropes.begin(),ropes.end());
    int cost=0;
    while(pq.size()>1){
      int first=pq.top();
      pq.pop();
      int second=pq.top();
      pq.pop();
      cost+=first+second;
      pq.push(first+second);
    }
    return cost;
}



int main(){

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      vector<int> ropes(n);
      for(int i=0;i<n;i++)
      cin>>ropes[i];
      cout<<connectTheRopesWithMinimumCost(ropes)<<endl;
    }
    return 0;
}
