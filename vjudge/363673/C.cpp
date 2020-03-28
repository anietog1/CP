#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)

int main() {
  int n; cin >> n;
  int l[n], r[n]; forn(i, n) cin >> l[i] >> r[i];
  int p; cin >> p;
  int x[p]; forn(i, n) cin >> x[i];

  int count[n] = {};
  vector<int> nx;

  int lastp = -1;
  int cp = 0;
  for(int i = 0; i < n; ++i) {
    if(lastp == l) cnt[i]++;
    while(x[cp] < l[i]) cp++;
    while(l[i] <= x[cp] && x[cp] <= r[i]) {
      cnt[i]++;
      cp++;
    }

    if(cnt > 2) {
      cout << "impossible" << endl;
      return;
    }

    cp--;

    if(cnt == 1) {
      
    }

    if(cnt == 0) {
      
    }
  }
}
