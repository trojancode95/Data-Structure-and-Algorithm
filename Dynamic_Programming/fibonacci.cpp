#include <bits/stdc++.h>
using namespace std;
/*
//Recursive Approach : (2^n)
int fib(int n){
  //base case
  if(n==0 || n==1)
  return n;
  int ans;
  ans=fib(n-1)+fib(n-2);
  return ans;
}
*/

//Top Down DP Approach or Recursion + Memoization
int fibTD(int n,int dp[]){
    if(n==0 || n==1)
    return n;

    if(dp[n]!=0)
    return dp[n];

    int ans;
    ans=fibTD(n-1,dp)+fibTD(n-2,dp);
    return dp[n]=ans;

}
//Down Top DP Approach
int fibBT(int n){
  int dp[100]={0};
  dp[1]=1;

  for(int i=2;i<=n;i++)
  dp[i]=dp[i-1]+dp[i-2];

  return dp[n];
}
//Bottom Up Approach with Space Optimisation
int fibSpaceOptimised(int n){
  if(n==0 || n==1)
  return n;

  int a=0,b=1;
  for(int i=2;i<=n;i++){
    b=a+b;
    a=b-a;
  }
  return b;
}
int main(){
    int n;
    cin>>n;

    int dp[100]={0};
    cout<<fibTD(n,dp)<<endl;
    cout<<fibBT(n)<<endl;
    cout<<fibSpaceOptimised(n)<<endl;

}
