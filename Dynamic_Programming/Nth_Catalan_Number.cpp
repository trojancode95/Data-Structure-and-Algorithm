#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

//Sigma dp[i-1]*dp[n-i] from i=1 to n
cpp_int Nth_Catalan_Number(int n) {
  cpp_int dp[n + 1] = {0};
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++)
      dp[i] += dp[j - 1] * dp[i - j];
  }
  return dp[n];
}

//Sigma dp[i]*dp[n-i-1] from i=0 to n-1
cpp_int Nth_Catalan_Number(int n) {
  cpp_int dp[n + 1] = {0};
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++)
      dp[i] += dp[j] * dp[i - j - 1];
  }
  return dp[n];
}

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    cout << Nth_Catalan_Number(n) << endl;
  }

  return 0;
}




