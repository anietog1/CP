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
  int T; cin >> T;
  while(T--) {
    int a, b; cin >> a >> b;
    int d = abs(a - b);

    int acum = 0;
    acum += d / 5;
    d %= 5;
    acum += d / 2;
    d %= 2;
    acum += d;

    cout << acum << endl;
  }
}
