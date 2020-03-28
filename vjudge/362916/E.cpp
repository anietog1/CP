#include <bits/stdc++.h>

using namespace std;;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define ll long long
#define vi vector<int>
#define vii vector<pii>

int main() {
  int t; cin >> t;
  while(t--) {
    int n, s, k; cin >> n >> s >> k;
    int a[k]; forn(i, k) cin >> a[i];
    sort(a, a + k);
    int idx = 0;
    while(idx < k && a[idx] < k) idx++;
    if(a[idx] == s) cout << 0 << endl;
    else {
      int d = (1 << 30);
      int i = max(0, idx - 1), j = min(idx + 1, k - 1);

      while(i > 0) {
        if(a[i]-a[i-1] > 1) break;
        i--;
      }

      while(j < k-1) {
          if(a[j+1]-a[j] > 1) break;
          j++;
      }

      D(i); D(j);

      cout << min(s - (a[i] - 1), a[j] + 1 - s) << endl;
    }
  }
}
