#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

bool comp(pii a, pii b) {
  return a.second < b.second;
}

int main() {
  int n, r;
  ll avg;

  cin >> n >> r >> avg;
  avg *= n;

  pii ab[n];
  ll sum = 0;

  for(int i = 0; i < n; ++i) {
    cin >> ab[i].first >> ab[i].second;
    sum += ab[i].first;
  }

  sort(ab, ab + n, comp);

  ll acum = 0;

  for(int i = 0; sum < avg; ++i) {
    ll needed = avg - sum;
    ll can = r - ab[i].first;

    if(needed < can) {
      acum += needed * ab[i].second;
      sum += needed;
    } else {
      acum += can * ab[i].second;
      sum += can;
    }
  }

  cout << acum << endl;
}
