#include <bits/stdc++.h>

using namespace std;

int dp[100] = {0, 1, 2};

int build(int left) {
  if(left <= 0) return 0;
  if(dp[left] != 0) return dp[left];
  return dp[left] = build(left - 1) + build(left - 2);
}

int main() {
  build(60);
  int n;
  while(cin >> n, n) {
    cout << dp[n] << endl;
  }
}
