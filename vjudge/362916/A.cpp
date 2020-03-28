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
  ll n; cin >> n;
  map<ll, ll> equiv;

  forn(i, n) {
    ll b; cin >> b;
    ll c = b - i;
    equiv[c] += b;
  }

  ll ans = -(1LL << 60);
  for(auto c : equiv) {
    ans = max(ans, c.second);
  }

  cout << ans << endl;
}
