//https://ide.codingblocks.com/s/263748


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>>customPair;
int kthSmallest(vector<vector<int>>v,int row,int column,int k){
      priority_queue<customPair,vector<customPair>,greater<customPair>>pq;
      map<pair<int,int>,bool>visited;
      for(int i=0;i<column;i++){
        pq.push({v[0][i],{0,i}});
        // cout<<"inserted {"<<0<<" , "<<i<<" } "<<v[0][i]<<endl;
        visited[{0,i}]=true;
      }
      int result;
      while(k--){
        customPair t=pq.top();
        pq.pop();
        int element=t.first;
        int i=t.second.first;
        int j=t.second.second;

        // cout<<element<<" "<<i<<" "<<j<<endl;

        if(k==0) result=element;

        //now next elemenet to be inserted are (i+1,j) and (i,j+1)

        if(j<column-1 &&  visited[{i,j}]==0){
          pq.push({v[i][j+1],{i,j+1}});
          // cout<<"inserted {"<<i<<" , "<<j+1<<" } "<<v[i][j+1]<<endl;
          visited[{i,j+1}]=true;
        }
        if(i<row-1 && visited[{i+1,j}]==0){
          pq.push({v[i+1][j],{i+1,j}});
          // cout<<"inserted {"<<i+1<<" , "<<j<<" } "<<v[i+1][j]<<endl;
          visited[{i+1,j}]=true;
        }
      }
      return result;
}



int main(){


        int row,column,k,x;
        cin>>row>>column;
        vector<vector<int>>v;
        for(int i=0;i<row;i++){
          vector<int>temp;
          for(int j=0;j<column;j++){
            cin>>x;
            temp.push_back(x);
          }
          v.push_back(temp);
        }

        cin>>k;
        cout<<kthSmallest(v,row,column,k)<<endl;
}
