#include <bits/stdc++.h>
using namespace std;
#define size 100
//Top Down Approach
int lcsTD(string s1,int m,string s2,int n,int dp[][size]){
    if(n==0 || m==0)
    return 0;

    if(dp[m-1][n-1]!=-1)
    return dp[m-1][n-1];

    if(s1[m-1]==s2[n-1])
    dp[m-1][n-1] = 1 + lcsTD(s1,m-1,s2,n-1,dp);
    else
    dp[m-1][n-1] = max(lcsTD(s1,m-1,s2,n,dp),lcsTD(s1,m,s2,n-1,dp));

    return dp[m-1][n-1];
}
//Bottom Up Approach
int lcsBU(string s1,int m,string s2,int n){
  int dp[m+1][n+1];

  for(int i=0;i<=m;i++){
      for(int j=0;j<=n;j++){
          if(i==0 || j==0)
          dp[i][j]=0;
          else if(s1[i-1]==s2[j-1])
          dp[i][j]=1+dp[i-1][j-1];
          else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
  }
  return dp[m][n];
}
int main(){
    string s1="abcdef";
    string s2="bcde";

    int dp[100][100];
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
         dp[i][j]=-1;
    cout<<lcsTD(s1,6,s2,4,dp)<<endl;
    cout<<lcsBU("abcded",6,"abcd",4)<<endl;

    return 0;
}
