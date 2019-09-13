#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int n; cin >> n;
  int h[2][n];
  for(int i = 0; i < n; ++i) cin >> h[0][i];
  for(int i = 0; i < n; ++i) cin >> h[1][i];

  long long dp[2][n];

  dp[0][0] = h[0][0];
  dp[1][0] = h[1][0];

  if(n > 1) {
    dp[0][1] = dp[1][0] + h[0][1];
    dp[1][1] = dp[0][0] + h[1][1];

    for(int i = 2; i < n; ++i) {
      dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + h[0][i];
      dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + h[1][i];
    }
  }

  cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
}
