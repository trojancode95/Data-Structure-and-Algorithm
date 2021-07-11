#include <bits/stdc++.h>
using namespace std;

//Kadane's Algorithm

//Bottom Up Approach : O(n) time complexity and space complexity
int maxSum(int a[],int n){
    int dp[100]={0};
    dp[0]=a[0]>0?a[0]:0;

    int max_so_far=dp[0];
    for(int i=1;i<n;i++){
      dp[i] = dp[i-1]+a[i];

      if(dp[i]<0)
      dp[i]=0;

      max_so_far=max(dp[i],max_so_far);
    }
    return max_so_far;
}

//Space Optimised Code
int maxSumSpaceOptimised(int a[],int n){
    int current_sum=0;
    int max_so_far=0;
    for(int i=0;i<n;i++){
      current_sum+=a[i];

      if(current_sum<0)
      current_sum=0;

      max_so_far=max(current_sum,max_so_far);
    }
    return max_so_far;
}

//Handle the case when all the elements are negative and you have to return the smallest negative number
int maxSubArraySum(int a[],int n){
    int current_sum=a[0],max_sum=a[0];
    for(int i=1;i<n;i++){
      current_sum=max(current_sum+a[i],a[i]);
      max_sum=max(current_sum,max_sum);
    }
    return max_sum;
}



int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int a[] = {-3,2,5,-1,6,3,-2,7,-5,2};
   int n = sizeof(a)/sizeof(int);

   cout<<maxSum(a,n)<<endl;
   cout<<maxSumSpaceOptimised(a,n)<<endl;

   int arr[] = {-7,-6,-5,-4,-8,-11};
   int len = sizeof(arr)/sizeof(int);
   cout<<maxSubArraySum(arr,len)<<endl;

   return 0;
}
