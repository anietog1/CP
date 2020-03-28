#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)
#define fornr(i, n) for(int i = n - 1; i >= 0; --i)
#define forer(i, b, a) for(int i = b; i >= a; --i)
#define pii pair<int, int>
#define MOD 998244353L

int main() {
  int n, k; cin >> n >> k;
  int p[n]; forn(i, n) cin >> p[i];

  pii r[n]; forn(i, n) r[i] = pii(p[i], i);
  sort(r, r + n);

  int idx[k]; long acum= 0;
  forn(i, k) {
    acum+=r[n-1-i].first;
    idx[i]=r[n-1-i].second;
  }

  sort(idx, idx + k);

  long cnt = 1;
  forn(i, k - 1) {
    long shared = idx[i+1] - idx[i];
    cnt = (cnt * shared) % MOD;
  }

  bool ispal = true;
  forn(i, n) if(p[i] != p[n-1-i]) ispal = false;
  if(ispal && k == 2) cnt++;
  cout << acum << " " << cnt << endl;
}
