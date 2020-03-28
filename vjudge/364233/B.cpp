#include <bits/stdc++.h>

using namespace std;

#define D(x)  cout << #x << " = " << x << endl
#define pii   pair<int, int>
#define pll   pair<long, long>
#define ll    long long
#define float double

int main() {
  int t; cin >> t;
  while(t--) {
    ll s; cin >> s;
    ll ans = 0;

    while(s >= 10) {
      ll tmp = s - s % 10;
      s -= tmp;
      s += tmp / 10;
      ans += tmp;
    }

    ans += s;
    cout << ans << endl;
  }
}
