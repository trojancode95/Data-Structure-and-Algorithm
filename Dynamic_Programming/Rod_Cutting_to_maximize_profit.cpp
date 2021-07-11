#include <bits/stdc++.h>
using namespace std;

//Top Down Approach
int maxProfitTD(int a[],int n,int dp[]){
   if(n==0)
   return 0;

   if(dp[n]!=0)
   return dp[n];

   int best=0;
   for(int i=1;i<=n;i++){
     int profit=a[i]+maxProfitTD(a,n-i,dp);
     best=max(best,profit);
   }
   return dp[n]=best;
}

//Bottom Up Approach
int maxProfitBU(int a[],int n){
   int dp[100]={0};


   for(int len=1;len<=n;len++){
      for(int cut=1;cut<=len && len>=cut ;cut++){
        dp[len]=max(a[cut]+dp[len-cut],dp[len]);
      }
   }
   return dp[n];
}


int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int priceOfEachLen[100]={0};

   int length;
   cin>>length;

   for(int i=1;i<=length;i++)
   cin>>priceOfEachLen[i];

   int dp[100]={0};

   cout<<maxProfitTD(priceOfEachLen,length,dp)<<endl;

   cout<<maxProfitBU(priceOfEachLen,length)<<endl;

   return 0;
}
