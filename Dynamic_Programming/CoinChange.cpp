#include <bits/stdc++.h>
using namespace std;

//Minimum coins needed to make a desired value

//Top Down Approach
int minCoinsTD(int n,int coins[],int t,int dp[]){
  //Base Case
  if(n==0)
  return 0;

  //Lookup
  if(dp[n]!=0)
  return dp[n];

  //Rec Case
  int ans=INT_MAX;
  for(int i=0;i<t;i++){
    if(n-coins[i]>=0){
      int subproblem=minCoinsTD(n-coins[i],coins,t,dp);
      ans=min(ans,subproblem+1);
    }
  }
  return dp[n]=ans;
}

//Bottom Up Approach
int minCoinsBU(int n,int coins[],int t){
  int dp[100]={0};

  //Iterate over all states 1...n
  for(int i=1;i<=n;i++){
    //Initiliase our current ans to INT_MAX
    dp[i]=INT_MAX;
    //Iterating over the value of coins
    for(int j=0;j<t;j++){
      if(i-coins[j]>=0){
        int subproblem=dp[i-coins[j]];
        dp[i]=min(dp[i],subproblem+1);
      }
    }
  }
  return dp[n];
}




int main(){
  int n=15;
  int coins[]={1,7,10};
  int dp[100]={0};
  int t=sizeof(coins)/sizeof(int);
  cout<<minCoinsTD(n,coins,t,dp)<<endl;
  cout<<minCoinsBU(n,coins,t)<<endl;

  return 0;
}
