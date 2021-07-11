// Matrix Chain Multiplication
//
//
// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.
//
// Example:
//  if you had four matrices A, B, C, and D, you would have:
//
//     (ABC)D = (AB)(CD) = A(BCD) = ....
// However, the order in which one parenthesize the product affects the number of simple arithmetic operations needed to compute the product, or the efficiency.
//
// For example:
//
// A: 10 × 30 matrix
// B : 30 × 5 matrix
// C : 5 × 60 matrix
// Then,
//      (AB)C = (10×30×5) + (10×5×60)
//            = 1500 + 3000
//            = 4500 operations
//      A(BC) = (30×5×60) + (10×30×60)
//            = 9000 + 18000
//            = 27000 operations.
// Given an array arr[] which represents the chain of matrices such that the ith matrix Ai is of dimension arr[i-1] x arr[i]. Your task is to write a function that should print the minimum number of multiplications needed to multiply the chain.
//
//   Input: p[] = {40, 20, 30, 10, 30}
//   Output: 26000
//   There are 4 matrices of dimensions 40x20,
//   20x30, 30x10 and 10x30. Let the input 4
//   matrices be A, B, C and D.  The minimum
//   number of multiplications are obtained
//   by putting parenthesis in following way
//   (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30
//
//   Input: p[] = {10, 20, 30, 40, 30}
//   Output: 30000
//   There are 4 matrices of dimensions 10x20,
//   20x30, 30x40 and 40x30. Let the input 4
//   matrices be A, B, C and D.  The minimum
//   number of multiplications are obtained by
//   putting parenthesis in following way
//   ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30
// Input:
// The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The first line of each test case contains an integer N, denoting the number of elements in the array.
// Then next line contains N space separated integers denoting the values of the element in the array.
//
// Output:
// For each test case the print the minimum number of operations needed to multiply the chain.
//
// Constraints:
// 1<=T<=100
// 2<=N<=100
// 1<=A[]<=500
//
// Example:
// Input:
// 2
// 5
// 1 2 3 4 5
// 3
// 3 3 3
// Output:
// 38
// 27


#include <bits/stdc++.h>
using namespace std;

//Bottom Up Approach
//Time Complexity: O(n^3)
//Auxiliary Space: O(n^2)
int matrixChainMultiplication(int a[],int n){
    int dp[n][n];
    int i,j,k,l,q;
    for(i=1;i<n;i++)
    dp[i][i]=0;

    for(l=2;l<n;l++){
      for(i=1;i<n-l+1;i++){
        j=i+l-1;
        dp[i][j]=INT_MAX;
        for(k=i;k<=j-1;k++){
          q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
          if(q<dp[i][j])
          dp[i][j]=q;
        }
      }
    }
    return dp[1][n-1];
}

int main(){

    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
      cin>>a[i];

      cout<<matrixChainMultiplication(a,n)<<endl;
    }

    return 0;
}
