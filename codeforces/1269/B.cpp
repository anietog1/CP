#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv, char** env) {
  int n, m; cin >> n >> m;
  int a[n], b[n];

  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) cin >> b[i];

  sort(b, b + n);

  int ans = 1 << 30;
  for(int i = 0; i < n; ++i) {
    int d = (b[0] - a[i] + m) % m;

    int tmpa[n];
    for(int j = 0; j < n; ++j)
      tmpa[j] = (a[j] + d) % m;
    sort(tmpa, tmpa + n);

    bool ok = true;
    for(int j = 0; j < n && ok; ++j)
      ok = (tmpa[j] == b[j]);

    if(ok) ans = min(ans, d);
  }

  cout << ans << endl;
}
