#include<bits/stdc++.h>
using namespace std;


//Bottom up Approach
//dp[i] : Number of non_decreasing subarray ending at index i.
unsigned long long int countSubArray(int a[],int n){
     unsigned long long int dp[n];
     dp[0]=1;
     for(int i=1;i<n;i++){
       if(a[i]>=a[i-1])
       dp[i]=dp[i-1]+1;
       else
       dp[i]=1;
     }
     unsigned long long int count=0;
     for(int i=0;i<n;i++)
     count+=dp[i];

     return count;
}


int main()
{
     int t;
     cin>>t;
     while(t--){
       int n;
       cin>>n;
       int a[n];
       for(int i=0;i<n;i++)
       cin>>a[i];
       cout << countSubArray(a, n)<<endl;
    }

    return 0;
}
