#include <bits/stdc++.h>
using namespace std;

//Top Down Approach : O(n) sapace complexity and O(nk) time complexity
int ladders_topdown(int n,int k,int dp[]){

   //Base case
   if(n==0)
   return 1;

   //Lookup
   if(dp[n]!=0)
   return dp[n];

   //Recursive case
   int ways=0;
   for(int i=1;i<=k;i++){
     if(n-i>=0)
     ways+=ladders_topdown(n-i,k,dp);
   }
   return ways;
}

//Bottom Up Approach : O(n) sapace complexity and O(nk) time complexity
int ladders_bottomup(int n,int k){
   int dp[100]={0};

   //Base Case
   dp[0]=1;

   for(int i=1;i<=n;i++){
     for(int j=1;j<=k && i>=j;j++)
     dp[i]+=dp[i-j];
   }

   return dp[n];
}

//Optimised Bottom Up ladder DP Aprroach : O(n+k) time complexity and O(n) space complexity
int ladders_Optimised(int n,int k){
   int dp[100]={0};

   dp[0]=dp[1]=1;
   for(int i=2;i<=k;i++)
   dp[i]=2*dp[i-1];

   for(int i=k+1;i<=n;i++)
   dp[i]=2*dp[i-1]-dp[i-1-k];

   return dp[n];
}


int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n,k;
   cin>>n>>k;

   int dp[100]={0};
   cout<<ladders_topdown(n,k,dp)<<" ways"<<endl;
   cout<<ladders_bottomup(n,k)<<" ways"<<endl;
   cout<<ladders_Optimised(n,k)<<" ways"<<endl;

   return 0;
}
