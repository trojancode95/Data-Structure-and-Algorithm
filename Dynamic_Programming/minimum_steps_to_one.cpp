#include <bits/stdc++.h>
using namespace std;

//Minimum steps to one :- n->n/3, n/2, n-1
//Top Down Approach
int minStepsTD(int n,int dp[]){
    //Base Case
    if(n==1)
    return 0;


    //Lookup if n is already computed
    if(dp[n]!=0)
    return dp[n];

    //Compute if dp[n] is not known
    int opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX;
    if(n%3==0)
    opt1 = minStepsTD(n/3,dp);
    if(n%2==0)
    opt2 = minStepsTD(n/2,dp);
    opt3 = minStepsTD(n-1,dp);

    int ans=min(min(opt1,opt2),opt3) + 1;

    return dp[n]=ans;
}

//Bottom Up Approach
int minStepsBU(int n){
    int dp[100]={0};

    dp[1]=0;
    for(int i=2;i<=n;i++){
      int opt1,opt2,opt3;
      opt1=INT_MAX,opt2=INT_MAX,opt3=INT_MAX;
      if(i%3==0)
      opt1=dp[i/3];
      if(i%2==0)
      opt2=dp[i/2];
      opt3=dp[i-1];

      dp[i]=min(min(opt1,opt2),opt3)+1;
    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;

    int dp[100]={0};
    cout<<minStepsTD(n,dp)<<endl;
    cout<<minStepsBU(n)<<endl;
    return 0;
}
