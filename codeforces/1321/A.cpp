#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
  int n; cin >> n;
  int r[n]; forn(i, n) cin >> r[i];
  int b[n]; forn(i, n) cin >> b[i];

  int rsum = 0; forn(i, n) rsum += r[i];
  int bsum = 0; forn(i, n) bsum += b[i];
  int onlyr = 0; forn(i, n) onlyr += r[i] > b[i];
  
  if(rsum == 0 || onlyr == 0)
    cout << -1 << endl;
  else {
    rsum -= onlyr;
    int count = 1;
    while(rsum + count * onlyr <= bsum) ++count;
    cout << count << endl;
  }
}
