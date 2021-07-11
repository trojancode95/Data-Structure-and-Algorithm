#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cin.tie(NULL)

int maxSumIS(int a[], int n)  
{  
    //longest sum subsequence ending at index i
    int dp[n];
    for(int i = 0; i < n; ++i) {
        dp[i] = a[i];
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if (a[j] < a[i] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }
    int msis = 0;
    for(int i = 0; i < n; ++i) {
        msis = max(msis, dp[i]);
    }
    return msis;
}  


int main() {
    fastio;
    int a[] = {20, 8, 27, 37, 9, 12, 46};
    int n = sizeof(a) / sizeof(int);
    cout << maxSumIS(a, n) << endl;
}