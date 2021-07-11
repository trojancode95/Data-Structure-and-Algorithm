//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0

#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

//Top Bottom Approach
int OptimalGameStrategy(int value[],int i,int j,int sum){
    if(j==i+1)
    return max(value[i],value[j]);

    if(dp[i][j]!=-1)
    return dp[i][j];

    dp[i][j]=max(sum-OptimalGameStrategy(value,i+1,j,sum-value[i]),sum-OptimalGameStrategy(value,i,j-1,sum-value[j]));

    return dp[i][j];

}


int main(){
     int t;
     cin>>t;

     while(t--){
       int n;
       cin>>n;
       int value[n];

       int sum=0;
       for(int i=0;i<n;i++){
         cin>>value[i];
         sum+=value[i];
       }
       memset(dp,-1,sizeof(dp));
       cout<<OptimalGameStrategy(value,0,n-1,sum)<<endl;
     }
}
