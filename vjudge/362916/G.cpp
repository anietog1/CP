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
    int n; cin >> n;

    if(n >= 3 && (n & 1)) {
      cout << 7;
      n -= 3;
    }

    while(n > 0) {
      cout << 1;
      n -= 2;
    }

    cout << endl;
  }
}
