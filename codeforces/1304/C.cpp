#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl

int main() {
  int q; cin >> q;
  while(q--) {
    int n, m; cin >> n >> m;
    int t[n], l[n], h[n];
    for(int i = 0; i < n; ++i) cin >> t[i] >> l[i] >> h[i];

    bool done = false;

    for(int i = n - 1; i > 0; --i) {
      int d = (t[i] - t[i - 1]);

      int prevl = l[i] - d;
      int prevh = h[i] + d;

      prevl = max(prevl, l[i - 1]);
      prevh = min(prevh, h[i - 1]);

      if(prevl > prevh) {
        cout << "NO" << endl;
        done = true;
        break;
      }

      l[i - 1] = prevl;
      h[i - 1] = prevh;
    }

    if(!done) {
      int d = t[0];
      if(l[0] - d <= m && m <= h[0] + d) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
}
