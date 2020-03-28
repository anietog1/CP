#include <bits/stdc++.h>

using namespace std;
#define D(x) cout << #x << " = " << x << endl
#define forn(i, n) for(long long i = 0; i < n; ++i)
#define fore(i, a, b) for(long long i = a; i <= b; ++i)
#define pii pair<long long, long long>

bool cmp(pii a, pii b) {
  return a.first == b.first;
}

int main() {
  long long n; cin >> n;

  vector<pii> v(n);

  forn(i, n) {
    cin >> v[i].first;
    v[i].second = i+1L;
  }

  auto last = std::unique(v.begin(), v.end(), cmp);
  v.erase(last, v.end());
  long long prevn = n;
  n = v.size();
  long long cnt = 0, a = 0, b = 0;
  for(long long i = 1L; i < n; ++i) {
    long long cur = v[i].first, prev = v[i-1L].first;

    if(prev < cur && cnt == 0) {
      a = b = i;
    }

    if(prev > cur) {
      if(cnt == 1L) {
        cout << "impossible" << endl;
        return 0;
      }

      cnt = 1L;
      while(v[i-1L].first > v[i].first && i < n) {
        ++i;
        ++b;
      }
      --i;
    }
  }


  long long init;
  if(a > 0) {
    init = v[a-1L].first;
  } else init = -(1L<<60);

  long long lst;
  if(b < n-1L)
    lst=v[b+1L].first;
  else
    lst = 1L<<60;

  if(init <= v[b].first && lst >= v[a].first) {
    if(b == n - 1L)
      v[b].second = prevn;
    else v[b].second = v[b+1].second -1;
    cout << v[a].second << " " << v[b].second << endl;
  }
  else
    cout << "impossible" << endl;
}
