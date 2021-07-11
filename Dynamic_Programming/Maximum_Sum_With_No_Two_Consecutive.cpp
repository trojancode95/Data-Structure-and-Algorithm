#include <bits/stdc++.h>
using namespace std;

//Bottom Up DP Approach
int kadaneIIBU(int a[],int n){
   if(n==1)
   return a[0];

   int dp[100]={0};

   dp[0]=a[0];
   dp[1]=max(a[0],a[1]);
   for(int i=2;i<n;i++){
     dp[i]=max(max(dp[i-1],dp[i-2]+a[i]),a[i]);
   }
   return dp[n-1];
}

//Space Optimised DP solution ..
int kadaneII(int a[],int n){
    if(n==1)
    return a[0];

    int prev_prev=a[0];
    int prev=max(a[0],a[1]);
    int res=prev;
    for(int i=2;i<n;i++){
      res=max(max(prev_prev+a[i],prev),a[i]);
      prev_prev=prev;
      prev=res;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    cout<<kadaneIIBU(a,n)<<endl;


    cout<<kadaneII(a,n)<<endl;
}
