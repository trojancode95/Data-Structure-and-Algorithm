// C : Vacation : Atcoder DP contest Problem

// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;


class activity{
public:
    int A;
    int B;
    int C;
};

//Bottom Up DP Approach
//dp[n][0] : maximum possible happiness from 1...N ,if the boy does the activity A on day N.
//dp[n][1] : maximum possible happiness from 1...N ,if the boy does the activity B on day N.
//dp[n][2] : maximum possible happiness from 1...N ,if the boy does the activity C on day N.
int vacation(vector<activity>v,int n){

     int dp[n+1][3];
     dp[1][0]=v[1].A;
     dp[1][1]=v[1].B;
     dp[1][2]=v[1].C;

    for(int i=2;i<=n;i++){
      dp[i][0]=(v[i].A + max(dp[i-1][1],dp[i-1][2]))%mod;
      dp[i][1]=(v[i].B + max(dp[i-1][0],dp[i-1][2]))%mod;
      dp[i][2]=(v[i].C + max(dp[i-1][0],dp[i-1][1]))%mod;
    }

    int ans = max(dp[n][0],max(dp[n][1],dp[n][2]));
    return ans % mod;
}



int main(){

     int n;
     cin>>n;
     vector<activity>v(n+1);
     for(int i=1;i<=n;i++){
       cin>>v[i].A;
       cin>>v[i].B;
       cin>>v[i].C;
     }

     cout<<vacation(v,n)<<endl;

     return 0;
}
