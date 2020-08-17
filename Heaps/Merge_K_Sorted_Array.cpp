#include<bits/stdc++.h>
using namespace std;

//Time complexity :- O(nklogk)
typedef pair<int, pair<int,int>> customPair; //In this pair, first int represents the element, next two int represents its position in 2d vector ie. i,j
vector<int> mergeKSortedArrays(vector<vector<int>>v)
{
      vector<int>result;
      priority_queue<customPair, vector<customPair>,greater<customPair>>pq;
      for(int i=0;i<v.size();i++)
      pq.push({v[i][0],{i,0}});//Pushing the first element of all K sorted arrays in the priority queue

      //Processing and pushing the remaining elements
      while(!pq.empty()){
          customPair current = pq.top();
          pq.pop();

          result.push_back(current.first);
          int x=current.second.first;
          int y=current.second.second;
          if(y+1<v[x].size())
          pq.push({v[x][y+1],{x,y+1}});
      }

      return result;
}

int main(){
        int t;
        cin>>t;
        while(t--){
            int k;
            cin>>k;
            int n=0;
            vector<vector<int>>v(k);
            for(int i=0;i<k;i++){
                for(int j=0;j<k;j++){
                    cin>>n;
                    v[i].push_back(n);
                }
            }
            vector<int>sorted=mergeKSortedArrays(v);
            for(auto x:sorted)
            cout<<x<<" ";
            cout<<endl;
         }
         return 0;

}
