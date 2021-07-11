// Common variants :-
// 1) Finding the Minimum/Maximum Cost Path in a Grid
// 2) Finding the Number of ways to reach a particular position from a given starting point in 2D Grid and so on.

#include <bits/stdc++.h>
using namespace std;

//Either you come from top or you come from left to any particular box
int minCost(int cost[][3],int dp[][3]){
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
          if(i==0 && j==0)
          dp[i][j]=cost[0][0];
          else if(i==0)
          dp[i][j]=dp[i][j-1]+cost[0][j];
          else if(j==0)
          dp[i][j]=dp[i-1][0]+cost[i][0];
          else
          dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
        }
      }
      return dp[2][2];
}

int main(){

      int cost[][3]={{1,5,2},{7,1,1},{8,1,3}};
      int dp[3][3]={0};
      cout<<minCost(cost,dp)<<endl;

      return 0;
}
