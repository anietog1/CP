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
  ll a[n]; forn(i, n) cin >> a[i];

  ll countn = 0;
  ll countz = 0;
  ll countp = 0;

  ll movp = 0;
  ll movz = 0;
  ll movn = 0;

  forn(i, n) {
    if(a[i] < 0) {
      countn++;
      movn += -1 - a[i];
    }

    if(a[i] > 0) {
      countp++;
      movp += a[i] - 1;
    }

    if(a[i] == 0) {
      countz++;
      movz++;
    }
  }

  if((countn & 1) && !countz) {
    cout << movp + movz + movn + 2 << endl;
  } else {
    cout << movp + movz + movn << endl;
  }
}
