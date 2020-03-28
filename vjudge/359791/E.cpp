#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl

int pow(int x, int n) {
  if(n == 0) return 1;
  return x * pow(x, n - 1);
}

int solve(int x, int idx, int n) {
  int tmp = pow(idx, n);
  if(tmp > x) return 0;
  if(tmp == x) return 1;
  return solve(x - tmp, idx + 1, n) + solve(x, idx + 1, n);
}

int main() {
  int x, n; cin >> x >> n;
  cout << solve(x, 1, n) << endl;
}
