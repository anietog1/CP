#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define MAXN 40
#define MOD (10000000000 + 7)

typedef long long ll;

int main() {
  ll dp[MAXN] = {};

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i = 4; i < MAXN; ++i) {
    dp[i] = (dp[i]+dp[i-1]+dp[i-2]+dp[i-3])%MOD;
  }
  
  int s; cin >> s;
  while(s--) {
    int n; cin >> n;
    cout << dp[n] << endl;
  }
}
