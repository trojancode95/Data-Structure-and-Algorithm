//https://www.codechef.com/problems/CD1IT4

// Robot and Paths


// A robot is designed to move on a rectangular grid of M rows and N columns. The robot is initially positioned at (1, 1), i.e., the top-left cell. The robot has to reach the (M, N) grid cell. In a single step, robot can move only to the cells to its immediate east and south directions. That means if the robot is currently at (i, j), it can move to either (i + 1, j) or (i, j + 1) cell, provided the robot does not leave the grid.
//
// Now somebody has placed several obstacles in random positions on the grid, through which the robot cannot pass. Given the positions of the blocked cells, your task is to count the number of paths that the robot can take to move from (1, 1) to (M, N).
//
// Since the answer can get very large, output the answer modulo 1000000007.
//
// Input
// The first line contains 3 integers M, N and P denoting the number of rows, number of columns and number of blocked cells respectively.
// In the next P lines, each line has exactly 2 integers i and j denoting that the cell (i, j) is blocked.
//
// Output
// Output should contain a single integer, the number of paths modulo 1000000007.
//
// Constraints
// 1 <= M, N <= 103
// 0 <= P <= M * N
// 1 <= i <= M
// 1 <= j <= N
// Example
// Input
// 4 3 2
// 3 3
// 3 1
//
// Output
// 2
//
// Explanation
// The only 2 possible paths are
// (1, 1) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3) and
// (1, 1) -> (2, 1) -> (2, 2) -> (3, 2) -> (4, 2) -> (4, 3)








#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int dp[1001][1001];
int numWays(int row,int col){
    //Base Case
    if(dp[0][0]==-1)
    return 0;


    //Compute the number of rows for the first rows
    for(int j=0;j<col;j++){
      if(dp[0][j]==-1)
      break;
      else
      dp[0][j]=1;
    }

    for(int i=0;i<row;i++){
      if(dp[i][0]==-1)
      break;
      else
      dp[i][0]=1;
    }

    // Bottom Up Approach
    for(int i=1;i<row;i++){
      for(int j=1;j<col;j++){
        //if the cell is blocked, leave it
        if(dp[i][j]==-1)
        continue;

        if(dp[i-1][j]!=-1)
        dp[i][j]+=dp[i-1][j]%mod;

        if(dp[i][j-1]!=-1)
        dp[i][j]+=dp[i][j-1]%mod;
      }
    }
    //Check for the final cell
    if(dp[row-1][col-1]==-1)
    return 0;

    return dp[row-1][col-1];
}


int main()
 {
    memset(dp,0,sizeof(dp));

    int m,n,number_of_cell_blocked;
    cin>>m>>n>>number_of_cell_blocked;
    int x,y;
    for(int i=0;i<number_of_cell_blocked;i++){
      cin>>x>>y;
      dp[x-1][y-1]=-1;
    }
    cout<<numWays(m,n)<<endl;
	  return 0;
}
