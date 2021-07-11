//https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long int Friend_Pairing_Problem(int n){
    long int dp[n+1]={0};

    for(int i=1;i<=n;i++){
      if(i<=2)
      dp[i]=i;
      else
      dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n]%mod;
}


int main(){

     int t;
     cin>>t;
     while(t--){
       int n;
       cin>>n;
       cout<<Friend_Pairing_Problem(n)<<endl;
     }
     return 0;
}
