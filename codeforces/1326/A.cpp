#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << #x << " = " << x << endl
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, a, b) for(int i = a; i <= b; ++i)

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;

    if(n == 1) cout << -1 << endl;
    else {
      if((n - 1) % 3 == 0) {
        forn(i, n - 2) cout << 2;
        cout << 33 << endl;
      } else {
        forn(i, n - 1) cout << 2;
        cout << 3 << endl;
      }
    }
  }
}
