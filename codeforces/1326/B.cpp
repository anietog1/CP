#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define forn(i, n) for(long i = 0; i < n; ++i)
#define fore(i, a, b) for(long i = a; i <= b; ++i)

int main() {
  long n; cin >> n;
  long b[n]; forn(i, n) cin >> b[i];
  long a[n];
  a[0] = b[0];

  long cmax = a[0];
  fore(i, 1, n-1) {
    a[i] = b[i] + cmax;
    cmax = max(cmax, a[i]);
  }

  forn(i, n)
    cout << (i == 0? "":" ") << a[i];
  cout << endl;
}
