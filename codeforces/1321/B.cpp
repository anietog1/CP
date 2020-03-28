#include <bits/stdc++.h>

using namespace std;
#define d(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define forn(i, n) for(long long i = 0; i < n; ++i)

int main() {
  long long n; cin >> n;
  map<long long, long long> pcount;
  long long ans=0;
  forn(i, n) {
    long long b; cin >> b;
    long long eq=b-(i+1);
    pcount[eq]+=b;
    if(ans<pcount[eq])ans=pcount[eq];
  }

  cout << ans << endl;
}
