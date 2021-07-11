#include <bits/stdc++.h>
using namespace std;


//Standard Solution : O(n2) time complexity and O(n) space complexity.
//dp[i] represents the longest increasing subsequence ending at index i.
int lis(int a[],int n){
    int dp[n]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i])
            dp[i]=max(dp[i],dp[j]);
        }
        dp[i]++;
        //Printing the longest increasing subsequence ending at index i.
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    int lis=0;
    for(int i=0;i<n;i++)
    lis=max(dp[i],lis);

    //Returning the length of Longest Increasing Subsequence
    return lis;
}
//Tricky Solution : O(n2) time complexity and O(n) space complexity.
//dp[i] represents the elements at which the longest increasing subsequence of length i ends.
int longest_increasing_subsquence(int a[],int n){
    int dp[n+1]; //length from 0 to n.
    dp[0]=INT_MIN;

    for(int i=0;i<n;i++){
      dp[i+1]=INT_MAX;
      for(int j=0;j<n;j++){
        if(dp[j]<a[i] && a[i]<dp[j+1]){
          dp[j+1]=a[i];
          break;
        }
      }
    }
    int lis=0;

    for(int i=1;i<=n;i++){
      if(dp[i]!=INT_MAX)
      lis=i;
      else
      break;
    }
    //Returning the length of Longest Increasing Subsequence
    return lis;
}

//Optimised Code for longest_increasing_subsquence : O(nlogn) time complexity and O(n) space complexity
//Extension of Tricky Solution
//Using Binary Search
int lisOptimised(int a[],int n){
    int dp[n+1];
    dp[0]=INT_MIN;
    for(int i=0;i<n;i++){
      dp[i+1]=INT_MAX;
      int low=0,high=i+1;
      while(low<=high){
        int mid=(low+high)/2;
        if(a[i]>dp[mid])
        low=mid+1;
        else if(a[i]<dp[mid])
        high=mid-1;
      }
      dp[low]=a[i];
    }

    int lis=0;

    for(int i=1;i<=n;i++){
      if(dp[i]!=INT_MAX)
      lis=i;
      else
      break;
    }
    //Returning the length of Longest Increasing Subsequence
    return lis;
}
int main(){

    int a[]={1,5,2,3,4,9,6,10};
    int n=sizeof(a)/sizeof(int);
    cout<<lis(a,n)<<endl;
    cout<<longest_increasing_subsquence(a,n)<<endl;
    cout<<lisOptimised(a,n)<<endl;

    return 0;
}
